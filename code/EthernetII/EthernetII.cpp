#include <stdio.h>
#include "EthernetII.h"

bool macHeader::CmpSource(unsigned char* mac){
    if(*(unsigned int*)mac != *(unsigned int*)Source)return false;              //first 4 bytes
    if(*(unsigned short*)(mac+4) != *(unsigned short*)(Source+4))return false;  //last 2 bytes
    return true;
}

bool macHeader::CmpDestination(unsigned char* mac){
    if(*(unsigned int*)mac != *(unsigned int*)Destination)return false;              //first 4 bytes
    if(*(unsigned short*)(mac+4) != *(unsigned short*)(Destination+4))return false;  //last 2 bytes
    return true;
}

void macHeader::PrintSource(FILE* stream){
    fprintf(stream, "[%02X:%02X:%02X:%02X:%02X:%02X]",
        Source[0],
        Source[1],
        Source[2],
        Source[3],
        Source[4],
        Source[5]);
}

void macHeader::PrintDestination(FILE* stream){
    fprintf(stream, "[%02X:%02X:%02X:%02X:%02X:%02X]",
        Destination[0],
        Destination[1],
        Destination[2],
        Destination[3],
        Destination[4],
        Destination[5]);
}