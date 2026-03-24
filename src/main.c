#include "eng2d/eng2d.h"


// Objets
Ball ball;

// pixels / mètres
float ppm = 10.0f/0.3f;


void init() {
    ball = Ball_Init(7.5f, 7.5f, 0.3f, 5.0f);
    ball.dx = 3.0f;
}


void draw(Renderer *r) {
    Renderer_ClearScreen(r, Color_InitRGBA(0, 0, 0, 255));

    Renderer_DrawCircle(r, Color_InitRGBA(255, 255, 255, 255), ball.x*ppm, r->height-ball.y*ppm, ball.radius*ppm);

    Renderer_UpdateScreen(r);
}


void update(Renderer *r, float dt) {
    
    Ball_AddForce(&ball, 0.0f, -9.81f * ball.mass);

    Ball_Update(&ball, dt);

    if (ball.x < ball.radius) {
        ball.x = ball.radius;
        ball.dx *= -0.9f;
    }
    else if (ball.x*ppm > r->width - ball.radius*ppm) {
        ball.x = r->width/ppm - ball.radius;
        ball.dx *= -0.9f;
    }

    if (ball.y < ball.radius) {
        ball.y = ball.radius;
        ball.dy *= -0.9f;
    }
    else if (ball.y*ppm > r->height - ball.radius*ppm) {
        ball.y = r->height/ppm - ball.radius;
        ball.dy *= -0.9f;
    }
}



int main() {

    init();

    Renderer *r = Renderer_Init("2D Engine", 500, 500, 60, 0);

    Renderer_Run(
        r, 
        Renderer_BasicTreatEvents,
        draw,
        update
    );

    return EXIT_SUCCESS;
}
