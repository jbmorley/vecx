#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdbool.h>

typedef struct {

    double x;
    double y;
  
} Point;

static Point PointZero;

bool DoubleEqualToDouble(double a, double b, double epsilon);
bool PointEqualToPoint(Point p0, Point p1, double epsilon);
float DistanceFromPointToPoint(Point p0, Point p1);

#endif // GRAPHICS_H
