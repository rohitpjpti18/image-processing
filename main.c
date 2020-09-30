#include <stdio.h>
#include "bitmap.c"
#include "rgb_to_ycbcr.c"

int main(){
    char* filename = "test8X8.bmp";
    BITMAPINFOHEADER bmInfo;

    unsigned char *imageData;
    unsigned char *YCBCRArray;

    imageData = loadBMPFile(filename, &bmInfo);

    printf("image loaded \n");

    convertRGBToYCBCR(imageData, 192, YCBCRArray);

    return 0;
}