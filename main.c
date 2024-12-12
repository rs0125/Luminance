#include <stdio.h>
#include "image.h"

int sepia(image kumar);
int blackandwhite(image kumar);
int negative(image kumar);

int main()
{
    image kumar;
    printf("hi kumar\n");
    kumar = loadPNG("kumar.png");
    printf("loaded kumar\n");
    negative(kumar);

    return 0;
}

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

int sepia(image kumar)
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

            int outputRed = (r * .393) + (g * .769) + (b * .189);
            int outputGreen = (r * .349) + (g * .686) + (b * .168);
            int outputBlue = (r * .272) + (g * .534) + (b * .131);

            if (outputRed > 255)
                outputRed = 255;
            if (outputGreen > 255)
                outputGreen = 255;
            if (outputBlue > 255)
                outputBlue = 255;

            pixels[i][j] = setPixelRGB(outputRed, outputGreen, outputBlue);
        }
    }

    image kumar2 = newImage(width, height);
    setImage2DArray(kumar2, width, height, pixels);

    printf("%d %d\n", width, height);

    savePNG(kumar2, "Test2.png");
    printf("saved as Sepia\n");
    return 0;
}

int negative(image kumar)
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

            int outputRed = 255 - r;
            int outputGreen = 255 - g;
            int outputBlue = 255 - b;

            pixels[i][j] = setPixelRGB(outputRed, outputGreen, outputBlue);
        }
    }

    image kumar2 = newImage(width, height);
    setImage2DArray(kumar2, width, height, pixels);

    printf("%d %d\n", width, height);

    savePNG(kumar2, "Test2.png");
    printf("saved as Negative\n");
    return 0;
}