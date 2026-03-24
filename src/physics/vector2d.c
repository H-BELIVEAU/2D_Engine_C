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
