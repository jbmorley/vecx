#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "laser.h"

int main()
{
    Point p0 = PointMake(10, 10);
    Point p1 = PointMake(10, 20);
    Point p2 = PointMake(20, 20);
    Point p3 = PointMake(20, 10);

    Point p4 = PointMake(30, 30);
    Point p5 = PointMake(30, 40);
    Point p6 = PointMake(40, 40);
    Point p7 = PointMake(40, 30);

    LaserState state = LaserStateZero;

    LaserInitialize(&state);

    LaserRenderLine(&state, p0, p1);
    LaserRenderLine(&state, p1, p2);
    LaserRenderLine(&state, p2, p3);
    LaserRenderLine(&state, p3, p0);

    LaserRenderLine(&state, p4, p5);
    LaserRenderLine(&state, p5, p6);
    LaserRenderLine(&state, p6, p7);
    LaserRenderLine(&state, p7, p4);

}
