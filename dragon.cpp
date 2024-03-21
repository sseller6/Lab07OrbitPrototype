/***********************************************************************
 * Source File:
 *    Dragon : The representation of a child class, Dragon.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon inherits from the Whole class.
 ************************************************************************/

#include "dragon.h"

Dragon& Dragon::operator= (Dragon& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void Dragon::rotate(bool clockwise)
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

void Dragon::draw(ogstream& gout) const
{
   gout.drawCrewDragon(pos, dir.getAngle());
}