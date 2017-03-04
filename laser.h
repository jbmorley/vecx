#ifndef __LASER_H
#define __LASER_H

#include "graphics.h"

typedef struct {

    long rate;
    Point position;
    bool on;
  
} LaserState;

static LaserState LaserStateZero;

void LaserInitialize(LaserState *state);
void LaserRenderLine(LaserState *state, Point p0, Point p1);

#endif // __LASER_H
