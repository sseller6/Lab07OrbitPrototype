/***********************************************************************
 * Source File:
 *    Starlink : The representation of a child class, Starlink.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Starlink inherits from the Whole class.
 ************************************************************************/

#include "starlink.h"

Starlink& Starlink::operator= (Starlink& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void Starlink::rotate(bool clockwise)
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

void Starlink::draw(ogstream& gout) const
{
   gout.drawStarlink(pos, dir.getAngle());
}