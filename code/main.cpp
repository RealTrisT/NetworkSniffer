/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <linux/if_ether.h>

#include "debug.h"

void error(char *msg){
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[]){
	int sock_r = 0;
    unsigned int buflen = 0;

	sock_r = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

    unsigned char *buffer = (unsigned char *) malloc(65536); //to receive data
    memset(buffer,0,65536);
    struct sockaddr saddr;
    int saddr_len = sizeof(saddr);
     
    //Receive a network packet and copy in to buffer
    
    while((buflen=recvfrom(sock_r,buffer,65536,0,&saddr,(socklen_t *)&saddr_len)) >= 0){
        debug(buffer, buflen);
    }
    printf("rip\n");

	return 0; 
}