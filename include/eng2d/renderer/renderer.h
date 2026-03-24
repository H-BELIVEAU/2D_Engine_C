#include "SDL3/SDL.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "color.h"


typedef struct Renderer {
    int width, height, fps;
    SDL_Window *w;
    SDL_Renderer *r;
} Renderer;


#ifndef H_RENDERER
#define H_RENDERER

Renderer* Renderer_Init(const char *title, int width, int height, int fps, SDL_WindowFlags f);
void Renderer_DrawLine(Renderer *rdr, RGBAColor c, int x1, int y1, int x2, int y2);
void Renderer_DrawCircle(Renderer *rdr, RGBAColor c, int x, int y, int r);
void Renderer_FillCircle(Renderer *rdr, RGBAColor c, int x, int y, int r);
void Renderer_ClearScreen(Renderer *rdr, RGBAColor c);
void Renderer_UpdateScreen(Renderer *rdr);
void Renderer_Destroy(Renderer *rdr);

#endif
