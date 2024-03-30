/***********************************************************************
 * Source File:
 *    Starlink : The representation of a child class, Starlink.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Starlink inherits from the Whole class.
 ************************************************************************/

#include "starlink.h"

/***************************************************
 * STARLINK : OPERATOR = OVERLOAD
 ***************************************************/
Starlink& Starlink::operator= (Starlink& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * STARLINK : DRAW
 ***************************************************/
void Starlink::draw(ogstream& gout) const
{
   gout.drawStarlink(pos, dir.getAngle());
}
