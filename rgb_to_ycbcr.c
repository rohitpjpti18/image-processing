#include<malloc.h>

void convertRGBToYCBCR(unsigned char* RGBArray, long length, unsigned char* YCBCRArray){
    YCBCRArray = (unsigned char*)malloc(length*sizeof(unsigned char));
    
    for(int i = 0; i<length; i += 3){
        YCBCRArray[i] = 16 + ((65.738*RGBArray[i])/256) + ((129.057*RGBArray[i+1])/256) + ((25.064*RGBArray[i+2])/256);
        YCBCRArray[i+1] = 128 - ((37.945*RGBArray[i]/256)) - ((74.494*RGBArray[i+1])/256) + ((112.439*RGBArray[i+2])/256);
        YCBCRArray[i+2] = 128 + ((112.439*RGBArray[i])/256) - ((94.154*RGBArray[i+1])/256) - ((18.285*RGBArray[i+2])/256);

        printf("%d %d %d\n", YCBCRArray[i], YCBCRArray[i+1], YCBCRArray[i+2]);
    }
}