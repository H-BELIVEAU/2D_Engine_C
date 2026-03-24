#include "eng2d/physics/ball.h"


Ball Ball_Init(float x, float y, float r, float m) {
    Ball b;

    b.x = x;
    b.y = y;
    b.dx = 0.0f;
    b.dy = 0.0f;
    b.ax = 0.0f;
    b.ay = 0.0f;

    b.radius = r;
    b.mass = m;

    return b;
}


void Ball_AddForce(Ball *b, float fx, float fy) {
    b->ax += fx/b->mass;
    b->ay += fy/b->mass;
}

void Ball_Update(Ball *b, float dt) {
    b->dx += b->ax*dt;
    b->dy += b->ay*dt;

    b->x += b->dx*dt;
    b->y += b->dy*dt;

    b->ax = 0.0f;
    b->ay = 0.0f;
}

