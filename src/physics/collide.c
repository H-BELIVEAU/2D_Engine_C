#include "eng2d/physics/collide.h"


int IsColliding_BallBall(Ball b1, Ball b2) {
    return Vector_Dist(Vector(b1.x, b1.y), Vector(b2.x, b2.y)) <= b1.radius+b2.radius;
}


int IsColliding_BallLine(Ball b, Line l) {
    return Vector_DotProduct(l.dir, Vector(b.x, b.y)) <= b.radius;
}
