/***********************************************************************
 * Source File:
 *    DragonLeftArray : The representation of a child class, DragonLeftArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon left array breaks off of the Dragon.
 ************************************************************************/

#include "dragonLeftArray.h"

DragonLeftArray& DragonLeftArray::operator= (DragonLeftArray& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void DragonLeftArray::rotate(bool clockwise)
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

void DragonLeftArray::draw(ogstream& gout) const
{
   gout.drawCrewDragonLeft(pos, dir.getAngle());
}
