#ifndef CHAT_SERVER
#define CHAT_SERVER

#include "/usr/local/mysql/include/mysql.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <thread>

#define CHAT_PORT 51820

class ChatServer
{

    private:
        ChatServer();                       // Constructor

        void bindToThread();                // Bind each incoming client to a thread
        void handleClient();                // What to do with each client

        static ChatServer *Server;          // Single static instance of server
        struct sockaddr_in Server_Addr;     // Struct for server address <netinet/in.h>

        typedef struct CLIENT_INFO          // Structure for client information
        {
            struct sockaddr_in Client_Addr;
            socklen_t          Client_Len;
            int                Client_Sock; 
        } CLIENT_INFO;

        CLIENT_INFO CLIENTS[10];            // All clients
        std::thread CLIENT_THREADS[10];     // All of the clients' threads

        static unsigned short* parseIPV4(in_addr_t addrInt);
        static void            printIPV4(unsigned short* addr);

        MYSQL* sqlServer;

        void clearBuffer (char* buffer);

    public:
        unsigned long NUMBER_OF_CLIENTS;    // Number of how many clients are connected to server
        int servSock;                       // The socket's 'value'
        static ChatServer* getInstance();   // Get the single static instance
        void ACCEPT_CLIENTS();              // Polling function that will accept clients and delegate them to threads

};


#endif