#include "image.h"
#include <gd.h>
#include <stdio.h>
#include <stdlib.h>

image loadPNG(char *filename)
{
    image img;
    
    FILE *in = fopen(filename, "rb");
    if (!in)
    {
        fprintf(stderr, "Can't open %s for reading\n", filename);
        exit(1);
    }
    
    img.gd = gdImageCreateFromPng(in);
    return img;
}

int getWidth(image img)
{
    return gdImageSX(img.gd);
}

int getHeight(image img)
{
    return gdImageSY(img.gd);
}

int getPixel(image img, int x, int y)
{
    int gdPixel = gdImageGetPixel(img.gd, x, y);
    int red = gdImageRed(img.gd, gdPixel);
    int green = gdImageGreen(img.gd, gdPixel);
    int blue = gdImageBlue(img.gd, gdPixel);
    int pixel = (red << 16) + (green << 8) + blue;
    return pixel;
}

int getPixelRed(int pixel)
{
    return (pixel & 0xff0000) >> 16;
}

int getPixelGreen(int pixel)
{
    return (pixel & 0xff00) >> 8;
}

int getPixelBlue(int pixel)
{
    return pixel & 0xff;
}

void getImageArray(image img, int pixels[])
{
    int width = getWidth(img);
    int height = getHeight(img);
    
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel = getPixel(img, x, y);
            pixels[y * width + x] = pixel;
        }
    }
}

void getImage2DArray(image img, int width, int height, int pixels[][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel = getPixel(img, x, y);
            pixels[y][x] = pixel;
        }
    }
}

int setPixelRed(int pixel, int red)
{
    red &= 0xff;
    pixel &= 0x00ffff;
    pixel |= (red << 16);
    return pixel;
}

int setPixelGreen(int pixel, int green)
{
    green &= 0xff;
    pixel &= 0xff00ff;
    pixel |= (green << 8);
    return pixel;
}

int setPixelBlue(int pixel, int blue)
{
    blue &= 0xff;
    pixel &= 0xffff00;
    pixel |= blue;
    return pixel;
}

int setPixelRGB(int red, int green, int blue)
{
    int pixel = RGB_BLACK;
    pixel = setPixelRed(pixel, red);
    pixel = setPixelGreen(pixel, green);
    pixel = setPixelBlue(pixel, blue);
    return pixel;
}

image newImage(int width, int height)
{
    image img;
    img.gd = gdImageCreateTrueColor(width, height);
    return img;
}

void setImageArray(image img, int pixels[])
{
    // Loop through pixels
    // Allocate colors as we go using gdImageColorExact to create
    // a color.
    // Then use gdImageSetPixel to write the pixel into the image
    int width = getWidth(img);
    int height = getHeight(img);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int p = pixels[y * width + x];
            int blue = getPixelBlue(p);
            int green = getPixelGreen(p);
            int red = getPixelRed(p);
            int color = gdImageColorExact(img.gd, red, green, blue);
            gdImageSetPixel(img.gd, x, y, color);
        }
    }
}

void setImage2DArray(image img, int width, int height, int pixels[][width])
{
    // Loop through pixels
    // Allocate colors as we go using gdImageColorExact to create
    // a color.
    // Then use gdImageSetPixel to write the pixel into the image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int p = pixels[y][x];
            int blue = getPixelBlue(p);
            int green = getPixelGreen(p);
            int red = getPixelRed(p);
            int color = gdImageColorExact(img.gd, red, green, blue);
            gdImageSetPixel(img.gd, x, y, color);
        }
    }
}

void savePNG(image img, char filename[])
{
    FILE *out = fopen(filename, "wb");
    gdImagePng(img.gd, out);
}