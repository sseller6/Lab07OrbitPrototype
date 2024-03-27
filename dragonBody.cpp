/***********************************************************************
 * Source File:
 *    DragonBody : The representation of a child class, DragonBody.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon body breaks off of the Dragon.
 ************************************************************************/

#include "dragonBody.h"

DragonBody& DragonBody::operator= (DragonBody& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void DragonBody::rotate(bool clockwise)
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

void DragonBody::draw(ogstream& gout) const
{
   gout.drawCrewDragonCenter(pos, dir.getAngle());
}
