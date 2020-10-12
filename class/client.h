#ifndef CHAT_CLIENT
#define CHAT_CLIENT

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
/////////////////////////////////////////
// This client is for testing purposes //
/////////////////////////////////////////
class ChatClient
{

    private:
        struct sockaddr_in serv;

    public:
        
        ChatClient(unsigned int portNum);
        void sendDatagram(char message[]);
        short socketNum;
      

};


#endif