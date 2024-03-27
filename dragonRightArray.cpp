/***********************************************************************
 * Source File:
 *    DragonRightArray : The representation of a child class, DragonRightArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon right array breaks off of the Dragon.
 ************************************************************************/

#include "dragonRightArray.h"

DragonRightArray& DragonRightArray::operator= (DragonRightArray& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void DragonRightArray::rotate(bool clockwise)
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

void DragonRightArray::draw(ogstream& gout) const
{
   gout.drawCrewDragonRight(pos, dir.getAngle());
}
