#ifndef __GRAPHICS_H
#define __GRAPHICS_H

#include <stdbool.h>

typedef struct {

    double x;
    double y;
  
} Point;

static Point PointZero;

Point PointMake(double x, double y);
bool DoubleEqualToDouble(double a, double b, double epsilon);
bool PointEqualToPoint(Point p0, Point p1, double epsilon);
float DistanceFromPointToPoint(Point p0, Point p1);

#endif // __GRAPHICS_H
