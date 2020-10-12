#include <iostream>
#include <stdio.h>
#include <vector>
#include "../class/server.h"
#include "../class/client.h"
#include "../class/packets.h"

int main() {
    
    /*
    ChatServer* SERVER = SERVER->getInstance();

    while(1)
        SERVER->ACCEPT_CLIENTS();
    */

    packets::NTP* testPacket = (packets::NTP*)malloc(sizeof(testPacket));
    *((char *)testPacket) = 0x1b;
    //std::cout << sizeof(*testPacket) << std::endl;
    //testPacket->li_vn_mode = SET_LI_VI_MODE(0,3,3);
    //testPacket->stratum    = 3;
    ChatClient* UDP_TEST = new ChatClient(123); 
    UDP_TEST->sendDatagram( (char *)(testPacket) );

}