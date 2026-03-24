#include "math.h"


#ifndef H_VECTOR2D
#define H_VECTOR2D

typedef struct Vector2D {
    float x;
    float y;
} Vector2D;

Vector2D Vector(float x, float y);
Vector2D Vector_Add(Vector2D a, Vector2D b);
Vector2D Vector_Sub(Vector2D a, Vector2D b);
Vector2D Vector_Mul(Vector2D a, float m);
float Vector_DotProduct(Vector2D a, Vector2D b);
float Vector_Lenght(Vector2D v);
float Vector_Dist(Vector2D u, Vector2D v);

#endif
