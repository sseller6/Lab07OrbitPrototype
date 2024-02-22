//
//  physics.cpp
//  Lab07
//
//  Created by Josh Hamilton on 2/22/24.
//

#include "physics.h"

double Physics::heightFromPosition(Position &pos)
{
   return sqrt(pow(pos.getMetersX(), 2) + pow(pos.getMetersY(), 2)) - r;
}

double Physics::gravityFromHeight(double height)
{
   return g * pow(r / (r + height), 2);
}

double Physics::directionOfGravity(Position &pos)
{
   return atan2(earthX - pos.getMetersX(), earthY - pos.getMetersY());
}

double Physics::accelerationX(double acc, double angle)
{
   return acc * sin(angle);
}

double Physics::accelerationY(double acc, double angle)
{
   return acc * cos(angle);
}

double Physics::computeNewX(Position &pos, double velX, double accX)
{
   return pos.getMetersX() + velX * t + 0.5 * accX * pow(t, 2);
}

double Physics::computeNewY(Position &pos, double velY, double accY)
{
   return pos.getMetersY() + velY * t + 0.5 * accY * pow(t, 2);
}
