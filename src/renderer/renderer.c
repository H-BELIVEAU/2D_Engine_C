#include "eng2d/renderer/renderer.h"



Renderer* Renderer_Init(const char *title, int width, int height, int fps, SDL_WindowFlags f) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("--- SDL Init Video Failed ---\n");
        return NULL;
    }

    Renderer *r = malloc(sizeof(Renderer));
    if (!r) return NULL;
    
    r->w = SDL_CreateWindow(title, width, height, f);
    if (!r->w) {
        printf("--- SDL Window Init Failed ---\n");
        return NULL;
    }
    
    r->r = SDL_CreateRenderer(r->w, NULL);
    if (!r->r) {
        printf("--- SDL Renderer Init Failed ---\n");
        return NULL;
    }

    r->width = width;
    r->height = height;
    r->fps = fps;

    return r;
}

void Renderer_DrawLine(Renderer *rdr, RGBAColor c, int x1, int y1, int x2, int y2) {
    SDL_SetRenderDrawColor(rdr->r, c.r, c.g, c.b, c.a);
    SDL_RenderLine(rdr->r, x1, y1, x2, y2);
}

void Renderer_DrawCircle(Renderer *rdr, RGBAColor c, int x, int y, int r) {
    SDL_SetRenderDrawColor(rdr->r, c.r, c.g, c.b, c.a);

    if (r<=0) {
        SDL_RenderPoint(rdr->r, x, y);
        return;
    }

    float angle = 0.0f;
    float step = 1.0f/((float)r*2.0f);

    while (angle <= M_PI*2) {
        SDL_RenderPoint(rdr->r, x+r*cosf(angle), y+r*sinf(angle));

        angle += step;
    }
}

void Renderer_FillCircle(Renderer *rdr, RGBAColor c, int x, int y, int r) {
    for (int i=0; i<r; i++) {
        Renderer_DrawCircle(rdr, c, x, y, i);
    }
}

void Renderer_ClearScreen(Renderer *rdr, RGBAColor c) {
    SDL_SetRenderDrawColor(rdr->r, c.r, c.g, c.b, c.a);
    SDL_RenderClear(rdr->r);
}

void Renderer_UpdateScreen(Renderer *rdr) {
    SDL_RenderPresent(rdr->r);
}

void Renderer_Destroy(Renderer *rdr) {
    SDL_DestroyRenderer(rdr->r);
    SDL_DestroyWindow(rdr->w);
    SDL_Quit();
    free(rdr);
}
