//
//  physics.cpp
//  Lab07
//
//  Created by Josh Hamilton on 2/22/24.
//

#include "physics.h"

// The height of the spacecraft is the distance between it and the surface of the earth.
double Physics::heightFromPosition(Position &pos)
{
   return sqrt(pow(pos.getMetersX(), 2) + pow(pos.getMetersY(), 2)) - r;
}

// Use "big g" to calculate the pull of gravity at the height of the spacecraft.
double Physics::gravityFromHeight(double height)
{
   return g * pow(r / (r + height), 2);
}

// tan(theta) = y / x, so theta = atan(y / x).
double Physics::directionOfGravity(Position &pos)
{
   return atan2(earthX - pos.getMetersX(), earthY - pos.getMetersY());
}

double Physics::computeNewDx(Velocity &vel, Acceleration &acc)
{
   return vel.getDx() + acc.getDdx() * t;
}

double Physics::computeNewDy(Velocity &vel, Acceleration &acc)
{
   return vel.getDy() + acc.getDdy() * t;
}

// s = s0 + vt + 1/2at^2
double Physics::computeNewX(Position &pos, Velocity &vel, Acceleration &acc)
{
   return pos.getMetersX() + vel.getDx() * t + 0.5 * acc.getDdx() * pow(t, 2);
}

// See above
double Physics::computeNewY(Position &pos, Velocity &vel, Acceleration &acc)
{
   return pos.getMetersY() + vel.getDy() * t + 0.5 * acc.getDdy() * pow(t, 2);
}
