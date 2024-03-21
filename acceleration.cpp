//
//  acceleration.cpp
//  Lab07
//
//  Created by Josh Hamilton on 2/23/24.
//

#include "acceleration.h"

void Acceleration::setAngleMag(double angle, double mag)
{
   ddx = mag * sin(angle);
   ddy = mag * cos(angle);
}

void Acceleration::reverse()
{
   ddx *= -1;
   ddy *= -1;
}

Acceleration Acceleration::operator+ (const Acceleration & rhs) const
{
   return Acceleration(rhs.ddx + ddx, rhs.ddy + ddy);
}

Acceleration& Acceleration::operator+= (const Acceleration& rhs)
{
   ddx += rhs.ddx;
   ddy += rhs.ddy;
   return *this;
}