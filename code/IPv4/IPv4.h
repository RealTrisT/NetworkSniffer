#include <stdio.h>

//maximum IP packet length is 65,535 bytes with the header length included (65,528 + 20 = 65,548 bytes).
struct IPv4Header{
	unsigned char Version_IHL;			//Version: always 4
										//Internet Header Length : size of this header in 32-bit words - minimum 5 - maximum 15
	unsigned char DSCP_ECN;			//DSCP: Diferentiated Services Code Point : basically type of service
										//ECN:  Explicit Congestion Notification
	unsigned short TotalLength;			//Packet size in bytes of header+data
	unsigned short Identification; 		//identifies the group of fragments of a single IP datagram
	unsigned short Flags_FragmentOffset;//Flags: 0 - reserved, 1 - Don't fragment, 2 - More Fragments
										//FragmentOffset: measured in 8-byte blocks 
	unsigned char TTL;					//Time to Live: limits a datagram's lifetime, preventing it from going around in circles on the internet
	unsigned char Protocol;				//pretty fucking self-explanatory
	unsigned short HeaderChecksum;		//used for error-checking of the header. When a packet arrives at a router, the router calculates the checksum of the header and compares it to the checksum field. If the values do not match, the router discards the packet.
	unsigned int Source;
	unsigned int Destination;
	unsigned char Options[0];			//if IHL > 5

	unsigned char  GetVersion();
	unsigned char  GetIHL();
	unsigned char  GetDSCP();
	unsigned char  GetECN();
	unsigned char  GetFlags();
	unsigned short GetFragmentOffset();
	bool CmpSource(unsigned int* ip);
	bool CmpDestination(unsigned int* ip);
	void PrintSource(FILE* stream);
	void PrintDestination(FILE* stream);
	void SPrintSource(char* buffer, bool PadRight);
	void SPrintDestination(char* buffer, bool PadRight);
}__attribute__((packed));