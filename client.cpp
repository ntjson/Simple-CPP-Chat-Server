#include <winsock2.h>
#include <iostream>
#include <thread>
#include <string>


void receiver(SOCKET s) {
    char buffer[1024];
    while (true) {
        int byteReceived = recv(s, buffer, sizeof(buffer), 0);
        if (byteReceived > 0) {
            buffer[byteReceived] = '\0';
            std::cout << "Client received: " << buffer << std::endl;
        } else if (byteReceived == 0) {
            std::cout << "Client disconnected!" << std::endl;
            closesocket(s);
            return;
        } else {
            std::cout << "Error receiving data." << std::endl;
            closesocket(s);
            return;
        }
    }
}

int main() {
    WSAData wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        return 1;
    }

    SOCKET connSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (connSocket == INVALID_SOCKET) {
        std::cout << "Error opening socket." << std::endl;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(connSocket, (SOCKADDR *) &serverAddress,
                sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cout << "Connection failed! Is the server running?" << std::endl;
        return 1;
    }
    std::cout << "Connected to server!" << std::endl;

    std::thread receiverThread(&receiver, connSocket);
    receiverThread.detach();

    while (true) {
        std::string message;
        std::getline(std::cin, message);
        send(connSocket, message.c_str(), message.length(), 0);
        if (message == "exit" || message == "quit") {
            break;
        }
    }

    closesocket(connSocket);
    WSACleanup();
    return 0;
}
