/***********************************************************************
 * Source File:
 *    DragonRightArray : The representation of a child class, DragonRightArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon right array breaks off of the Dragon.
 ************************************************************************/

#include "dragonRightArray.h"

/***************************************************
 * DRAGON RIGHT ARRAY : OPERATOR = OVERLOAD
 ***************************************************/
DragonRightArray& DragonRightArray::operator= (DragonRightArray& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * DRAGON RIGHT ARRAY : ROTATE
 ***************************************************/
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

/***************************************************
 * DRAGON RIGHT ARRAY : DRAW
 ***************************************************/
void DragonRightArray::draw(ogstream& gout) const
{
   gout.drawCrewDragonRight(pos, dir.getAngle());
}
