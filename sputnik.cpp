/***********************************************************************
 * Source File:
 *    Sputnik : The representation of a child class, Sputnik.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Sputnik inherits from the Whole class.
 ************************************************************************/

#include "sputnik.h"

Sputnik& Sputnik::operator= (Sputnik& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void Sputnik::rotate(bool clockwise)
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

void Sputnik::draw(ogstream& gout) const
{
   gout.drawSputnik(pos, dir.getAngle());
}