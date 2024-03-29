/***********************************************************************
 * Source File:
 *    DragonBody : The representation of a child class, DragonBody.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon body breaks off of the Dragon.
 ************************************************************************/

#include "dragonBody.h"

/***************************************************
 * DRAGON BODY : OPERATOR = OVERLOAD
 ***************************************************/
DragonBody& DragonBody::operator= (DragonBody& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * DRAGON BODY : ROTATE
 ***************************************************/
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

/***************************************************
 * DRAGON BODY : DRAW
 ***************************************************/
void DragonBody::draw(ogstream& gout) const
{
   gout.drawCrewDragonCenter(pos, dir.getAngle());
}
