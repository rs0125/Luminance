#include <gd.h>

typedef struct {
    gdImagePtr gd;
} image;

#define RGB_BLACK  0x000000
#define RGB_WHITE  0xffffff
#define RGB_RED    0xff0000
#define RGB_GREEN  0x00ff00
#define RGB_BLUE   0x0000ff


// Loads an image into memory. Returns the image.
image loadPNG(char *filename);

// Save an image as a PNG.
void savePNG(image img, char filename[]);

// Get width or height of an image
int getWidth(image img);
int getHeight(image img);

// Get a pixel from an image
int getPixel(image img, int x, int y);

// Get the red, green, or blue component from a pixel
int getPixelRed(int pixel);
int getPixelGreen(int pixel);
int getPixelBlue(int pixel);

// Get an array of pixels from an image.
// The array must be allocated by the caller.
void getImageArray(image img, int pixels[]);
void getImage2DArray(image img, int width, int height, int pixels[][width]);

// Given a pixel, set the red, green, or blue component.
// Returns the altered pixel.
int setPixelRed(int pixel, int red);
int setPixelGreen(int pixel, int green);
int setPixelBlue(int pixel, int blue);

// Create a pixel from its red, green, and blue components
int setPixelRGB(int red, int green, int blue);

// Create a new image
image newImage(int width, int height);

// Copy pixels into the image from an array of pixels
void setImageArray(image img, int pixels[]);
void setImage2DArray(image img, int width, int height, int pixels[][width]);
