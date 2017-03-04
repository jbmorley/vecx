#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "laser.h"

int main()
{
    Point p0 = { 10, 10 };
    Point p1 = { 10, 20 };
    Point p2 = { 20, 20 };
    Point p3 = { 20, 10 };

    Point p4 = { 30, 30 };
    Point p5 = { 30, 40 };
    Point p6 = { 40, 40 };
    Point p7 = { 40, 30 };

    LaserState state = LaserStateZero;

    Initialize(&state);

    RenderLine(&state, p0, p1);
    RenderLine(&state, p1, p2);
    RenderLine(&state, p2, p3);
    RenderLine(&state, p3, p0);

    RenderLine(&state, p4, p5);
    RenderLine(&state, p5, p6);
    RenderLine(&state, p6, p7);
    RenderLine(&state, p7, p4);

}
