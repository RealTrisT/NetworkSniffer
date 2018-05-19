
struct macHeader{
    unsigned char Destination[6];
    unsigned char Source[6];
    unsigned short EtherType;

    bool CmpSource(unsigned char* mac);
    bool CmpDestination(unsigned char* mac);
    void PrintSource(FILE* stream);
    void PrintDestination(FILE* stream);
};