
typedef struct RGBAColor {
    int r, g, b, a;
} RGBAColor;

#ifndef H_RENDERER_COLOR
#define H_RENDERER_COLOR

RGBAColor Color_InitRGBA(int r, int g, int b, int a);

#endif
