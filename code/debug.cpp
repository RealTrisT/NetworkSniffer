#include <stdio.h>

#include "EthernetII/EthernetII.h"
#include "EthernetII/EtherTypes.h"
#include "IPv4/IPv4.h"

unsigned char me[6]        = {0x88, 0x53, 0x2e, 0xaa, 0x1a, 0xc2};
unsigned char router[6]    = {0x64, 0x70, 0x02, 0xDA, 0x20, 0xBB};
unsigned char broadcast[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define mac_noone 0
#define mac_me 1
#define mac_router 2

void debug(unsigned char* buffer, unsigned int buffersize){
		const char* source_ = 0, * destination_ = 0;
		macHeader* hdr = (macHeader*)buffer;

		if(hdr->CmpSource(me))source_ = KGRN;
		else if(hdr->CmpSource(router))source_ = KBLU;
		else if(hdr->CmpSource(broadcast))source_ = KRED;
		else source_ = KNRM;

		if(hdr->CmpDestination(me))destination_ = KGRN;
		else if(hdr->CmpDestination(router))destination_ = KBLU;
		else if(hdr->CmpDestination(broadcast))destination_ = KRED;
		else destination_ = KNRM;

        printf(source_);
        hdr->PrintSource(stdout);
        printf(KNRM);

		printf(">");

        printf(destination_);
        hdr->PrintDestination(stdout);
        printf(KNRM);

        /**/ if(__builtin_bswap16(hdr->EtherType) < 1536)			printf(" {size}");
        else if(__builtin_bswap16(hdr->EtherType) == ETHERTYPE_IPv4)printf(" {IPv4}");
        else if(__builtin_bswap16(hdr->EtherType) == ETHERTYPE_IPv6)printf(" {IPv6}");
        else if(__builtin_bswap16(hdr->EtherType) == ETHERTYPE_ARP) printf(" {ARP} ");
        else printf(" unknwn<0x%X>", hdr->EtherType);

        if(__builtin_bswap16(hdr->EtherType) == ETHERTYPE_IPv4){
        	char srcbuff[16] = {0};
        	char dstbuff[16] = {0};
        	IPv4Header* iph = (IPv4Header*)(buffer+14);
        	iph->SPrintSource(srcbuff, false);
        	iph->SPrintDestination(dstbuff, true);
        	printf("%s > %s", srcbuff, dstbuff);
        }

        printf("\n");
}