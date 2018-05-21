
#define TCP_FLAG_NS  8;
#define TCP_FLAG_CRW 7;
#define TCP_FLAG_ECE 6;
#define TCP_FLAG_URG 5;
#define TCP_FLAG_ACK 4;
#define TCP_FLAG_PSH 3;
#define TCP_FLAG_RST 2;
#define TCP_FLAG_SYN 1;
#define TCP_FLAG_FIN 0;

struct TCPHeader{
	unsigned short Source;				//source port
	unsigned short Destination;			//destination port
	unsigned int   SequenceNumber;		//If the SYN flag is set (1), then this is the initial sequence number. The sequence number of the actual first data byte and the acknowledged number in the corresponding ACK are then this sequence number plus 1.
										//If the SYN flag is clear (0), then this is the accumulated sequence number of the first data byte of this segment for the current session.
	unsigned int   AcknowledgmentNumber;//
	unsigned char  DataOffset_Res_NS;	//DataOffset, Reserved and ENC-nonce
	unsigned char  Flags;				//
	unsigned short WindowSize;			//
	unsigned short Checksum;			//
	unsigned short UrgentPtr;			//
	unsigned char  Options[0];			//

	bool GetFlag(unsigned char flag);
	unsigned char GetDataOffset();
}__attribute__((packed));