
typedef struct structBITMAPFILEHEADER{
    short bmFileType;
    unsigned int bmFileSize;
    short reserved1;
    short reserved2;
    unsigned int bmOffset;
} BITMAPFILEHEADER;


typedef struct structBITMAPINFOHEADER{
    unsigned int headerSize;
    int bmwidth;
    int bmheight;
    short nOfColorPlanes;
    short nOfBitsPerPixel;
    unsigned int compressionMethod;
    unsigned int imageSize;
    int horizontalRes;
    int veticalRes;
    unsigned int nOfColors;
    unsigned int nOfImpColors;
} BITMAPINFOHEADER;


unsigned char* loadBMPFile(char *filename, BITMAPINFOHEADER *bmInfoHeader);


