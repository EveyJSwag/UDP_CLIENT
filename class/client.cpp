#include "client.h"

ChatClient::ChatClient(unsigned int portNum)
{

    this->socketNum = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    std::cout << this->socketNum << std::endl;

    this->serv.sin_port = htons(portNum);
    this->serv.sin_family = AF_INET;
    
    inet_pton(AF_INET, "192.168.7.50", &this->serv.sin_addr.s_addr);

    connect(this->socketNum, (struct sockaddr *)&this->serv, sizeof(this->serv));

}

void ChatClient::sendDatagram(char message[])
{
    std::cout << sizeof( ((char *)message) ) << std::endl;
    send(this->socketNum, message, 48,0);

}