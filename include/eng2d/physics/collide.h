#include "ball.h"
#include "line.h"


#ifndef H_COLLIDER
#define H_COLLIDER

int IsColliding_BallBall(Ball b1, Ball b2);
int IsColliding_BallLine(Ball b, Line l);

#endif
