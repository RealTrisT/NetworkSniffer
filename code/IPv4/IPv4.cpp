#include "IPv4.h"

unsigned char IPv4Header::GetVersion(){
	return Version_IHL >> 4;
}

unsigned char  IPv4Header::GetIHL(){
	return Version_IHL & 0xf;
}

unsigned char  IPv4Header::GetDSCP(){
	return DSCP_ECN >> 2;
}

unsigned char  IPv4Header::GetECN(){
	return DSCP_ECN & 3;
}

unsigned char  IPv4Header::GetFlags(){
	return Flags_FragmentOffset >> 13;
}

unsigned short IPv4Header::GetFragmentOffset(){
	return Flags_FragmentOffset & 0x1FFF;
}

bool IPv4Header::CmpSource(unsigned int* ip){
	return *ip == Source;
}

bool IPv4Header::CmpDestination(unsigned int* ip){
	return *ip == Destination;
}

void IPv4Header::PrintSource(FILE* stream){
											//it's in little endian so do it "upside down"
	fprintf(stream, "%d.%d.%d.%d", Source&0xFF, (Source>>8)&0xFF, (Source>>16)&0xFF, Source>>24);
}

void IPv4Header::PrintDestination(FILE* stream){
								 			//it's in little endian so do it "upside down"
	fprintf(stream, "%d.%d.%d.%d", Destination&0xFF, (Destination>>8)&0xFF, (Destination>>16)&0xFF, Destination>>24);
}

void IPv4Header::SPrintSource(char* buffer, bool AlignRight){
	int written = snprintf(buffer, 16, "%d.%d.%d.%d", Source&0xFF, (Source>>8)&0xFF, (Source>>16)&0xFF, Source>>24);
	
	if(written < 15){//if doesn't fill buffer
		if(AlignRight){//if we want it to be on the right
			for (int i = 14; i >= (15-written); --i){		//pull buffer to the right side
				buffer[i] = buffer[i-(15-written)];
			}
			for (int i = 0; i < (15-written); ++i){			//fill with spaces till the start
				buffer[i] = ' ';
			}
		}else{
			buffer[15] = 0;
			for (int i = written; i < 15; ++i){				//fill with spaces till the end
				buffer[i] = ' ';
			}
		}
	}
}

void IPv4Header::SPrintDestination(char* buffer, bool AlignRight){
	int written = snprintf(buffer, 16, "%d.%d.%d.%d", Destination&0xFF, (Destination>>8)&0xFF, (Destination>>16)&0xFF, Destination>>24);
	
	if(written < 15){//if doesn't fill buffer
		if(AlignRight){//if we want it to be on the right
			for (int i = 14; i >= (15-written); --i){		//pull buffer to the right side
				buffer[i] = buffer[i-(15-written)];
			}
			for (int i = 0; i < (15-written); ++i){			//fill with spaces till the start
				buffer[i] = ' ';
			}
		}else{
			buffer[15] = 0;
			for (int i = written; i < 15; ++i){				//fill with spaces till the end
				buffer[i] = ' ';
			}
		}
	}
}

void* IPv4Header::GetUnderlyingProtocolAddr(){
	return (void*)(((unsigned int*)this) + GetIHL());
}