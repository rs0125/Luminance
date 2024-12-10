#include <stdio.h>
#include "image.h"


int main(){
    image kumar;
    printf("hi kumar\n");
    kumar =  loadPNG("scuba.png");
    printf("loaded kumar\n");

    int width = getWidth(kumar);
    int height = getHeight(kumar);

    int pixels[width][height];

    getImage2DArray(kumar, width, height, pixels);

    image kumar2 = newImage(width, height);

    printf("%d %d\n", width, height);

    savePNG(kumar2, "Test.png");
    printf("saved kumar\n");

    return 0;
}