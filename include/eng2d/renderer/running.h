#include "renderer.h"
#include "stdlib.h"


#ifndef H_RENDERER_RUNNING
#define H_RENDERER_RUNNING

bool Renderer_BasicTreatEvents(Renderer *r);
void Renderer_Run(
    Renderer *r,
    bool (*treat_events_f)(Renderer *r),
    void (*draw_f)(Renderer *r),
    void (*update_f)(Renderer *r, float dt)
);

#endif
