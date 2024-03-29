/***********************************************************************
 * Source File:
 *    DragonLeftArray : The representation of a child class, DragonLeftArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon left array breaks off of the Dragon.
 ************************************************************************/

#include "dragonLeftArray.h"
/***************************************************
 * DRAGON LEFT ARRAY : OPERATOR = OVERLOAD
 ***************************************************/
DragonLeftArray& DragonLeftArray::operator= (DragonLeftArray& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * DRAGON LEFT ARRAY : ROTATE
 ***************************************************/
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

/***************************************************
 * DRAGON LEFT ARRAY : DRAW
 ***************************************************/
void DragonLeftArray::draw(ogstream& gout) const
{
   gout.drawCrewDragonLeft(pos, dir.getAngle());
}
