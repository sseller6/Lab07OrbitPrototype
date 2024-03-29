/***********************************************************************
 * Source File:
 *    StarlinkArray : The representation of a child class, StarlinkArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Starlink array breaks off of the Starlink.
 ************************************************************************/

#include "starlinkArray.h"

/***************************************************
 * STARLINK ARRAY: OPERATOR = OVERLOAD
 ***************************************************/
StarlinkArray& StarlinkArray::operator= (StarlinkArray& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * STARLINK ARRAY: ROTATE
 ***************************************************/
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

/***************************************************
 * STARLINK ARRAY: DRAW
 ***************************************************/
void StarlinkArray::draw(ogstream& gout) const
{
   gout.drawStarlinkArray(pos, dir.getAngle());
}
