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