#include "eng2d/physics/line.h"


Line Line_Init(float x1, float y1, float x2, float y2) {
    Line l;

    l.x1 = x1;
    l.x2 = x2;
    l.y1 = y1;
    l.y2 = y2;

    l.dir = Vector_Mul(Vector(x2-x1, y2-y1), 1.0f/Vector_Lenght(Vector(x2-x1, y2-y1)));
    l.normal = Vector(-l.dir.y, l.dir.x);

    return l;
}
