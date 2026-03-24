#include "vector2d.h"


typedef struct Line {
    float x1, y1, x2, y2;
    Vector2D normal, dir;
} Line;


#ifndef H_LINE
#define H_LINE

Line Line_Init(float x1, float y1, float x2, float y2);

#endif
