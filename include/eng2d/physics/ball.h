#include "vector2d.h"


#ifndef H_BALL
#define H_BALL


typedef struct Ball {
    float x, y;
    float dx, dy;
    float ax, ay;

    float radius;
    float mass;
} Ball;


Ball Ball_Init(float x, float y, float r, float m);
void Ball_AddForce(Ball *b, float fx, float fy);
void Ball_Update(Ball *b, float dt);


#endif
