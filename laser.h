#ifndef LASER_H
#define LASER_H

#include "graphics.h"

typedef struct {

    long rate;
    Point position;
    bool on;
  
} LaserState;

static LaserState LaserStateZero;

void Initialize(LaserState *state);
void RenderLine(LaserState *state, Point p0, Point p1);

#endif
