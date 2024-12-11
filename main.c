#include <stdio.h>
#include "image.h"

int blackandwhite(image kumar)
{

    int width = getWidth(kumar);
    int height = getHeight(kumar);

    int pixels[width][height];

    getImage2DArray(kumar, width, height, pixels);

    printf("%d\n", getPixelRed(pixels[0][0]));
    printf("%d\n", getPixelGreen(pixels[0][0]));
    printf("%d\n", getPixelBlue(pixels[0][0]));

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int r = getPixelRed(pixels[i][j]);
            int g = getPixelGreen(pixels[i][j]);
            int b = getPixelBlue(pixels[i][j]);
            int avg = (r + b + g) / 3;
            pixels[i][j] = setPixelRGB(avg, avg, avg);
        }
    }

    image kumar2 = newImage(width, height);
    setImage2DArray(kumar2, width, height, pixels);

    printf("%d %d\n", width, height);

    savePNG(kumar2, "Test2.png");
    printf("saved as Black and White\n");
    return 0;
}

int main()
{
    image kumar;
    printf("hi kumar\n");
    kumar = loadPNG("scuba.png");
    printf("loaded kumar\n");
    blackandwhite(kumar);

    return 0;
}