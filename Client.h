#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
using namespace System::Threading;
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
using namespace System;

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27016"
ref class Client {

private:
    SOCKET ConnectSocket;
    bool access;
    bool ready;

public:
    Client() {
        ready = false;
        access = false;
        ConnectSocket = INVALID_SOCKET;
    }
    void SetAccess(bool b) {
        access = b;
    }

    bool GetAccess() {
        return access;
    }

    void Disconnect() {
        closesocket(ConnectSocket);
    }

    void ConnectToServer() {
        WSADATA wsaData;
        struct addrinfo* result = NULL,
            * ptr = NULL,
            hints;

        int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (iResult != 0) {
            printf("WSAStartup failed with error: %d\n", iResult);
            return;
        }

        ZeroMemory(&hints, sizeof(hints));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;

        char host[] = "176.104.187.4";
        iResult = getaddrinfo(host, DEFAULT_PORT, &hints, &result);
        if (iResult != 0) {
            printf("getaddrinfo failed with error: %d\n", iResult);
            WSACleanup();
            return;
        }

        for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
            ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
            if (ConnectSocket == INVALID_SOCKET) {
                printf("socket failed with error: %ld\n", WSAGetLastError());
                WSACleanup();
                return;
            }

            iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
            if (iResult == SOCKET_ERROR) {
                closesocket(ConnectSocket);
                ConnectSocket = INVALID_SOCKET;
                continue;
            }
            break;
        }

        freeaddrinfo(result);

        if (ConnectSocket == INVALID_SOCKET) {
            printf("Unable to connect to server!\n");
            WSACleanup();
            return;
        }

        ready = true;
    }

    bool IsConnect() {
        int error = 0;
        int len = sizeof(error);

        int result = getsockopt(ConnectSocket, SOL_SOCKET, SO_ERROR, (char*)&error, &len);

        if (result == SOCKET_ERROR) {
            return false;
        }
        else {
            if (error == 0) {
                return true;
            }
            else {
                return false;
            }
        }
    }

    void DisconnectFromServer() {
        ready = false;
        if (ConnectSocket != INVALID_SOCKET) {
            int iResult = shutdown(ConnectSocket, SD_SEND);
            if (iResult == SOCKET_ERROR) {
                printf("shutdown failed with error: %d\n", WSAGetLastError());

            }
            printf("sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss");
            closesocket(ConnectSocket);
            WSACleanup();
        }
    }

    void SendToServer(const char* message) {
        if (ConnectSocket == INVALID_SOCKET) {
          
            ReconnectToServer();
        }
        printf(message);
        int iResult = send(ConnectSocket, message, strlen(message), 0);
        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
        }
        else {
            printf("Bytes Sent: %d\n", iResult);
        }
    }

    void ReconnectToServer() {
        if (ready) {
            DisconnectFromServer();
        }
        ConnectToServer();
    }


   
    String^ ReceiveData() {
        char recvbuf[DEFAULT_BUFLEN];
        int iResult = recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
        if (iResult > 0) {
            recvbuf[iResult] = '\0';

            System::Text::Encoding^ enc = System::Text::Encoding::UTF8;
            return gcnew String(recvbuf, 0, iResult, enc);
        }
        else if (iResult == 0) {
            return "Connection closing...\n";
        }
        else {
            printf("recv failed with error: %d\n", WSAGetLastError());
            return "";
        }
    }
};


