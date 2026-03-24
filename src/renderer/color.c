#include "eng2d/renderer/color.h"


RGBAColor Color_InitRGBA(int r, int g, int b, int a) {
    RGBAColor c;
    c.r = r;
    c.g = g;
    c.b = b;
    c.a = a;

    return c;
}
