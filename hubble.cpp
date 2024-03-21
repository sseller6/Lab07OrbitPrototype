/***********************************************************************
 * Source File:
 *    Hubble : The representation of a child class, Hubble.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble inherits from the Whole class.
 ************************************************************************/

#include "hubble.h"

Hubble& Hubble::operator= (Hubble& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void Hubble::rotate(bool clockwise)
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

void Hubble::draw(ogstream& gout) const
{
   gout.drawHubble(pos, dir.getAngle());
}