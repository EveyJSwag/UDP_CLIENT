#include <iostream>
#include <stdio.h>
#include <vector>
#include "../class/server.h"
#include "../class/client.h"
#include "../class/packets.h"

int main() {
    

    packets::NTP* testPacket = (packets::NTP*)malloc(sizeof(testPacket));
    *((char *)testPacket) = 0x1b;
    ChatClient* UDP_TEST = new ChatClient(123); 
    UDP_TEST->sendDatagram( (char *)(testPacket) );

}
