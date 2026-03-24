#include "eng2d/physics/vector2d.h"


Vector2D Vector(float x, float y) {
    Vector2D v;
    v.x = x;
    v.y = y;

    return v;
}

Vector2D Vector_Add(Vector2D a, Vector2D b) {
    return Vector(a.x+b.x, a.y+b.y);
}

Vector2D Vector_Sub(Vector2D a, Vector2D b) {
    return Vector(a.x-b.x, a.y-b.y);
}

Vector2D Vector_Mul(Vector2D a, float m) {
    return Vector(a.x*m, a.y*m);
}

float Vector_DotProduct(Vector2D a, Vector2D b) {
    return a.x*b.x + a.y*b.y;
}

float Vector_Lenght(Vector2D v) {
    return sqrtf(v.x*v.x + v.y*v.y);
}

float Vector_Dist(Vector2D u, Vector2D v) {
    return sqrtf((u.x-v.x)*(u.x-v.x) + (u.y-v.y)*(u.y-v.y));
}
