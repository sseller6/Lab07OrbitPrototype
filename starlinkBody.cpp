/***********************************************************************
 * Source File:
 *    StarlinkBody : The representation of a child class, StarlinkBody.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Starlink body breaks off of the Starlink.
 ************************************************************************/

#include "starlinkBody.h"

StarlinkBody& StarlinkBody::operator= (StarlinkBody& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void StarlinkBody::rotate(bool clockwise)
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

void StarlinkBody::draw(ogstream& gout) const
{
   gout.drawStarlinkBody(pos, dir.getAngle());
}
