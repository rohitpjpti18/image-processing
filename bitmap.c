#include<stdio.h>
#include "bitmap.h"

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


void loadBMPFile(char *filename, BITMAPINFOHEADER *bmInfoHeader){
    FILE *fileptr;

    BITMAPFILEHEADER bitmapFileHeader;
    unsigned char *bitmapImage;
    int imageIndex = 0;
    unsigned char tempRGB;


    fileptr = fopen(filename, "rb");
    if(fileptr == NULL){
        return;
    }

    loadBitmapFileHeader(&bitmapFileHeader, fileptr);

    if(isBitmapValid(&bitmapFileHeader) == 0){
        fclose(fileptr);
        return;
    }

    loadBitmapInfoHeader(bmInfoHeader, fileptr);
}

int main(){
    char* filename = "test.bmp";
    BITMAPINFOHEADER bmInfo;

    loadBMPFile(filename, &bmInfo);

    return 0;
}