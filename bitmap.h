struct BITMAPFILEHEADER{
    char bmFileType[2];
    int bmFileSize;
    short reserved1;
    short reserved2;
    int bmOffset;
};


struct BITMAPINFOHEADER{
    unsigned int headerSize;
    signed int bmwidth;
    signed int bmheight;
    unsigned short nOfColorPlanes;
    unsigned short nOfBitsPerPixel;
    unsigned int compressionMethod;
    unsigned int imageSize;
    unsigned int horizontalRes;
    unsigned int veticalRes;
    unsigned int nOfColors;
    unsigned int nOfImpColors;
};





