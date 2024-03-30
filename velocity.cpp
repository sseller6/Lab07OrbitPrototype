/***********************************************************************
 * Source File:
 *    Velocity
 * Author:
 *    Josh and Steven
 * Summary:
 *    The code for the soruce file, velocity.cpp.
 ************************************************************************/

#include "velocity.h"

/***************************************************
 * VELOCITY : SET ANGLE MAG
 ***************************************************/
void Velocity::setAngleMag(double angle, double mag)
{
   dx = mag * sin(angle);
   dy = mag * cos(angle);
}

/***************************************************
 * VELOCITY : COMPUTE NEW VEL
 ***************************************************/
void Velocity::computeNewVel(Acceleration& acc, double time)
{
   dx += acc.getDdx() * time;
   dy += acc.getDdy() * time;
}

/***************************************************
 * VELOCITY : OPREATOR + OVERLOAD
 ***************************************************/
Velocity Velocity::operator+ (const Velocity & rhs) const
{
   return Velocity(rhs.dx + dx, rhs.dy + dy);
}

/***************************************************
 * VELOCITY : OPREATOR += OVERLOAD
 ***************************************************/
Velocity& Velocity::operator+= (const Velocity& rhs)
{
   dx += rhs.dx;
   dy += rhs.dy;
   return *this;
}
