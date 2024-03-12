//
//  shipGPS.cpp
//  Lab07
//
//  Created by Josh Hamilton on 2/23/24.
//

#include "GPS.h"

GPS& GPS::operator= (GPS& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void GPS::rotate(bool clockwise)
{
   if (clockwise)
   {
      dir += 0.01;
   }
   else
   {
      dir += -0.01;
   }
}

void GPS::draw(ogstream &gout) const
{
   gout.drawGPS(pos, dir.getAngle());
}
