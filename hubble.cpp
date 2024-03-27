/***********************************************************************
 * Source File:
 *    Hubble : The representation of a child class, Hubble.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble inherits from the Whole class.
 ************************************************************************/

#include "hubble.h"

/***************************************************
 * HUBBLE : OPERATOR = OVERLOAD
 ***************************************************/
Hubble& Hubble::operator= (Hubble& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * HUBBLE : ROTATE
 ***************************************************/
void Hubble::rotate(bool clockwise)
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
 * HUBBLE : DRAW
 ***************************************************/
void Hubble::draw(ogstream& gout) const
{
   gout.drawHubble(pos, dir.getAngle());
}