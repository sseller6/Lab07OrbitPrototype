/***********************************************************************
 * Source File:
 *    StarlinkArray : The representation of a child class, StarlinkArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Starlink array breaks off of the Starlink.
 ************************************************************************/

#include "starlinkArray.h"

StarlinkArray& StarlinkArray::operator= (StarlinkArray& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void StarlinkArray::rotate(bool clockwise)
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

void StarlinkArray::draw(ogstream& gout) const
{
   gout.drawStarlinkArray(pos, dir.getAngle());
}
