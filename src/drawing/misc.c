#include "misc.h"




Color ZiCreateColor(int r, int g, int b, int a){
    Color clr = {r,g,b,a};
    return clr;
}


unsigned int ZiColorToHex(Color color) {
    unsigned int hexValue = (color.r << 24) | (color.g << 16) | (color.b << 8) | color.a;
    return hexValue;
}