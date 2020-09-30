#include<stdio.h>
#include<malloc.h>

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

void loadBitmapFileHeader(BITMAPFILEHEADER *bitmapFileHeader, FILE *fileptr){
    fread(&bitmapFileHeader->bmFileType, sizeof(bitmapFileHeader->bmFileType), 1, fileptr);
    fread(&bitmapFileHeader->bmFileSize, sizeof(bitmapFileHeader->bmFileSize), 1, fileptr);
    fread(&bitmapFileHeader->reserved1, sizeof(bitmapFileHeader->reserved1), 1, fileptr);
    fread(&bitmapFileHeader->reserved2, sizeof(bitmapFileHeader->reserved2), 1, fileptr);
    fread(&bitmapFileHeader->bmOffset, sizeof(bitmapFileHeader->bmOffset), 1, fileptr);
}

void loadBitmapInfoHeader(BITMAPINFOHEADER *bmInfoHeader, FILE *fileptr){
    fread(bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, fileptr);
}

int isBitmapValid(BITMAPFILEHEADER *bitmapFileHeader){
    if(bitmapFileHeader->bmFileType == 0x4d42){
        return 1;
    }else{
        return 0;
    }
}


unsigned char* loadBMPFile(char *filename, BITMAPINFOHEADER *bmInfoHeader){
    FILE *fileptr;

    BITMAPFILEHEADER bitmapFileHeader;
    unsigned char *bitmapImage;
    unsigned char tempRGB;


    fileptr = fopen(filename, "rb");
    if(fileptr == NULL){
        return NULL;
    }

    loadBitmapFileHeader(&bitmapFileHeader, fileptr);

    if(isBitmapValid(&bitmapFileHeader) == 0){
        fclose(fileptr);
        return NULL;
    }

    loadBitmapInfoHeader(bmInfoHeader, fileptr);

    bitmapImage = (char*)malloc((bmInfoHeader->imageSize)*sizeof(char));

    fread(bitmapImage, bmInfoHeader->imageSize, 1, fileptr);


    //make sure bitmap image data was read
    if (bitmapImage == NULL){
        fclose(fileptr);
        return NULL;
    }

    // BMP stores image data in BGR format.
    // For best processing covert into RGB 
    for(int imageIndex = 0; imageIndex < bmInfoHeader->imageSize; imageIndex+=3){
        tempRGB = bitmapImage[imageIndex];
        bitmapImage[imageIndex] = bitmapImage[imageIndex + 2];
        bitmapImage[imageIndex + 2] = tempRGB;

        //printf("%d %d %d\n", bitmapImage[imageIndex], bitmapImage[imageIndex+1], bitmapImage[imageIndex+2]);
    }

    //printf("%d %d %d\n", bitmapImage[0], bitmapImage[1], bitmapImage[2]);

    return bitmapImage;
}



