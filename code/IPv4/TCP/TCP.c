#include "TCP.h"


bool TCPHeader::GetFlag(unsigned char flag){
	if(flag < 8) return (Flags >> flag) & 0x1;
	else         return DataOffset_Res_NS & 0x1;
}

unsigned char TCPHeader::GetDataOffset(){
	return (DataOffset_Res_NS >> 0x4);
}