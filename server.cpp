#include <winsock2.h>
#include <iostream>
#include <list>
#include <thread>
#include <string>

void receiver(SOCKET s) {
    char buffer[1024];
    while (true) {
        int byteReceived = recv(s, buffer, sizeof(buffer), 0);
        if (byteReceived > 0) {
            buffer[byteReceived] = '\0';
            std::cout << "Client sent: " << buffer << std::endl;
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

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0); //listening socket
    if (serverSocket == INVALID_SOCKET) {
        std::cout << "Error creating socket" << std::endl;
    }

    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = htons(8080);
    service.sin_addr.s_addr = INADDR_ANY;

    sockaddr_in clientAddr;
    int clientSize = sizeof(clientAddr);


    if (bind(serverSocket, (struct sockaddr *) &service, sizeof(service)) == SOCKET_ERROR) {
        std::cout << "Bind failed! Port 8080 might be in use." << std::endl;
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cout << "Listen failed!" << std::endl;
        return 1;
    }

    std::cout << "Server is now listening..." << std::endl;

    SOCKET connSocket = accept(serverSocket, (struct sockaddr *) &clientAddr, &clientSize);
    if (connSocket == INVALID_SOCKET) {
        std::cout << "Accept failed!" << std::endl;
        return 1;
    }
    std::cout << "Client connected!" << std::endl;

    std::thread serverThread(&receiver, connSocket);
    serverThread.detach();

    while (true) {
        std::string message;
        std::getline(std::cin, message);
        send(connSocket, message.c_str(), message.length(), 0);
        if (message == "exit" || message == "quit") {
            break;
        }
    }

    closesocket(connSocket);
    closesocket(serverSocket);

    WSACleanup();
    return 0;
}
