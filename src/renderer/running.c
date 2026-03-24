#include "eng2d/renderer/running.h"


bool Renderer_BasicTreatEvents(Renderer *r) {
    SDL_Event e;

    while (SDL_PollEvent(&e) == true) {
        if (e.type == SDL_EVENT_QUIT) {
            return false;
        }
    }

    return true;
}


void Renderer_Run(
    Renderer *r,
    bool (*treat_events_f)(Renderer *r),
    void (*draw_f)(Renderer *r),
    void (*update_f)(Renderer *r, float dt)
) {
    Uint64 t_last = SDL_GetPerformanceCounter();
    Uint64 freq = SDL_GetPerformanceFrequency();
    Uint64 t_now;

    bool running = true;
    double dt;

    while (running) {
        t_now = SDL_GetPerformanceCounter();
        dt = (double)(t_now - t_last) / (double)freq;

        (*update_f)(r, dt);
        (*draw_f)(r);
        running = (*treat_events_f)(r);

        t_last = t_now;
    }

    Renderer_Destroy(r);
}
