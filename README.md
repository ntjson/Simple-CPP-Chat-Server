Here is a professional, formatted README designed specifically for your project. It uses **Markdown** syntax, which GitHub renders into a beautiful page.

You can copy the code block below, create a file named `README.md` in your CLion project, paste the text in, and commit/push it.

***

```markdown
# 📡 Multithreaded TCP Chat Application

![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B)
![Platform](https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows)
![Networking](https://img.shields.io/badge/Library-Winsock2-orange?style=for-the-badge)

A robust, bidirectional Client-Server chat application built from scratch using **C++**, **Winsock2**, and **Multithreading**. This project demonstrates core networking concepts including the TCP 3-Way Handshake, socket lifecycle management, and non-blocking I/O via threading.

---

## 🚀 Features

*   **Client-Server Architecture:** Distinct server and client implementations.
*   **TCP Protocol:** Ensures reliable, ordered delivery of messages without data loss.
*   **Multithreading (`std::thread`):**
    *   Separates **Sending** (Main Thread) and **Receiving** (Worker Thread).
    *   Allows users to type and receive messages simultaneously (Full Duplex).
*   **Graceful Shutdown:** Handles `exit` commands cleanly on both ends, closing sockets and terminating threads properly.
*   **Localhost Networking:** Configured to run locally on `127.0.0.1` port `8080`.

---

## 🛠️ Tech Stack

*   **Language:** C++ (Standard 14/17/20)
*   **Networking API:** Windows Sockets 2 (Winsock2 / `ws2_32.lib`)
*   **Build System:** CMake
*   **IDE:** CLion

---

## 🧩 Architecture

The application uses a **multithreaded approach** to solve the blocking I/O problem.

```mermaid
graph TD
    subgraph Server
    A[Main Thread] -->|Cin >> Send| Network
    B[Worker Thread] -->|Recv >> Cout| Network
    end
    
    subgraph Client
    C[Main Thread] -->|Cin >> Send| Network
    D[Worker Thread] -->|Recv >> Cout| Network
    end

    Network((TCP Connection))
```

1.  **Main Thread:** Handles User Input (`std::getline`) and sending data.
2.  **Receiver Thread:** Detached thread that loops `recv()` to listen for incoming data in the background.

---

## ⚙️ Getting Started

### Prerequisites
*   Windows OS (Required for `<winsock2.h>`)
*   MinGW Compiler (GCC) or MSVC
*   CMake

### Installation & Build

**Option 1: Using CLion**
1.  Open the project in CLion.
2.  Reload the CMake project.
3.  Select `server` from the Run Configuration and press Play.
4.  Select `client` from the Run Configuration and press Play.

**Option 2: Using Command Line (MinGW)**
If you prefer the terminal, ensure you link the Winsock library (`-lws2_32`):

```bash
# Compile Server
g++ server.cpp -o server.exe -lws2_32

# Compile Client
g++ client.cpp -o client.exe -lws2_32
```

---

## 🎮 How to Run

1.  **Start the Server first.**
    *   Open a terminal and run `server.exe`.
    *   It will display: `Server is now listening...`
2.  **Start the Client.**
    *   Open a second terminal and run `client.exe`.
    *   It will display: `Connected to server!`
3.  **Chat!**
    *   Type messages in either window and hit Enter.
4.  **Exit.**
    *   Type `exit` or `quit` to close the connection.

---

## 📸 Screenshots

*(You can add a screenshot of your two console windows chatting here later!)*

---

## 📝 Learning Outcomes

This project was built to master the following concepts:
*   **Winsock Initialization:** `WSAStartup` and `WSACleanup`.
*   **Socket Lifecycle:** `socket`, `bind`, `listen`, `accept`, `connect`.
*   **Data Transfer:** `send` and `recv` with buffer management.
*   **Concurrency:** Using `std::thread` and `.detach()` for parallel execution.

---

## 📜 License

This project is open source. Feel free to use it for educational purposes.
```

### How to add a screenshot (Optional but Recommended)
If you want to make it look *really* good:
1.  Run your Server and Client side-by-side.
2.  Type a small conversation.
3.  Take a screenshot (Windows Key + Shift + S).
4.  Save the image as `screenshot.png` inside your project folder.
5.  In the `README.md` file (under the Screenshots section), add this line:
    `![Demo Screenshot](screenshot.png)`

This shows visitors immediately that your code works!
