#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "laser.h"

#define LASER_FULL_POWER 4095
#define LASER_CYCLES_TO_OFF 4
#define LASER_CYCLES_TO_ON 4
#define LASER_CYCLES_TO_STABLE_ON 2
#define LASER_CYCLES_TO_STABLE_OFF 1
#define LASER_MAX_DISTANCE_PER_CYCLE_ON 5
#define LASER_MAX_DISTANCE_PER_CYCLE_OFF 10

static LaserState LaserStateZero = { 0 };

void RenderPoint(Point point, bool on)
{
    long multiplier = on ? 1 : 0;

    printf("s=%ld,%ld,%ld,%ld,%ld,%ld\n",
           (long)point.x, (long)point.y,
           LASER_FULL_POWER * multiplier, LASER_FULL_POWER * multiplier,
           multiplier, multiplier);
}

void LaserStateSetRate(LaserState *state, long rate)
{
    if (state->rate == rate) {
        return;
    }

    printf("r=%ld\n", rate);
    (*state).rate = rate;
}

void RenderPause(LaserState *state, long cycles)
{
    int i;
    for (i = 0; i < cycles; i++) {
        RenderPoint(state->position, state->on);
    }
}

void LaserStateSetOn(LaserState *state, bool on)
{
    int i;

    if (state->on == on) {
        return;
    }

    (*state).on = on;

    if (on) {
        RenderPause(state, LASER_CYCLES_TO_ON);
    } else {
        RenderPause(state, LASER_CYCLES_TO_OFF);
    }
}

void LaserStateSetPosition(LaserState *state, Point position)
{
    int i;

    // Look up the maximum move distance for current state.
    float max_distance = state->on ? LASER_MAX_DISTANCE_PER_CYCLE_ON : LASER_MAX_DISTANCE_PER_CYCLE_OFF;

    // Determine the distance to the point.
    double distance = DistanceFromPointToPoint(state->position, position);
    float steps = ceil(distance / max_distance);
    double moveX = (position.x - state->position.x) / steps;
    double moveY = (position.y - state->position.y) / steps;

    for (i = 0; i < steps; i++) {
        Point intermediate = PointZero;
        intermediate.x = state->position.x + (i * moveX);
        intermediate.y = state->position.y + (i * moveY);
        RenderPoint(intermediate, state->on);
    }

    (*state).position = position;
    RenderPause(state, state->on ? LASER_CYCLES_TO_STABLE_ON : LASER_MAX_DISTANCE_PER_CYCLE_OFF);
}

void RenderLine(LaserState *state, Point p0, Point p1)
{
    // Switch the laser off if the line is discontinuous.
    if (!PointEqualToPoint(state->position, p0, 0.1)) {
        LaserStateSetOn(state, false);
        LaserStateSetPosition(state, p0);
        LaserStateSetOn(state, true);
    }

    // Draw the line.
    LaserStateSetPosition(state, p1);
}

void Initialize(LaserState *state)
{
    LaserStateSetRate(state, 20000);
    printf("e=1\n");
}

