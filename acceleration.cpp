/***********************************************************************
 * Source File:
 *    ACCELERATION
 * Author:
 *    Josh and Steven
 * Summary:
 *    The source code for acceleration.
 ************************************************************************/

#include "acceleration.h"

/***************************************************
 * ACCELERATION : SET ANGLE MAG
 ***************************************************/
void Acceleration::setAngleMag(double angle, double mag)
{
   ddx = mag * sin(angle);
   ddy = mag * cos(angle);
}

/***************************************************
 * ACCELERATION : REVERSE
 ***************************************************/
void Acceleration::reverse()
{
   ddx *= -1;
   ddy *= -1;
}

/***************************************************
 * ACCELERATION : OPREATOR + OVERLOAD
 ***************************************************/
Acceleration Acceleration::operator+ (const Acceleration & rhs) const
{
   return Acceleration(rhs.ddx + ddx, rhs.ddy + ddy);
}

/***************************************************
 * ACCELERATION : OPREATOR += OVERLOAD
 ***************************************************/
Acceleration& Acceleration::operator+= (const Acceleration& rhs)
{
   ddx += rhs.ddx;
   ddy += rhs.ddy;
   return *this;
}