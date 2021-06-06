#include <iostream>
#include <cstdlib>

#define cimg_use_png       // Do this if you want CImg to process PNGs itself without resorting to ImageMagick
#define cimg_use_jpeg      // Do this if you want CImg to process JPEGs itself without resorting to ImageMagick
#define cimg_use_tiff      // Do this if you want CImg to process TIFFs itself without resorting to ImageMagick
#define cimg_use_curl      // Do this if you want CImg to be able to load images via a URL
#define cimg_display 0     // Do this if you don't need a GUI and don't want to link to GDI32 or X11
#include "CImg.h"

using namespace cimg_library;
using namespace std;

int main() {
    // Load image
    CImg<unsigned char> img("C:/Users/purva/Pictures/red.jpg");

    // Get width, height, number of channels
    int w = img.width();
    int h = img.height();
    int c = img.spectrum();
    cout << "Dimensions: " << w << "x" << h << " " << c << " channels" << endl;

    // Dump all pixels
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char hex[16];
            sprintf(hex, "#%02x%02x%02x", img(x, y, 0), img(x, y, 1), img(x, y, 2));
            cout << y << "," << x << " " << hex << endl;
        }
    }
}