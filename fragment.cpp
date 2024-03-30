/***********************************************************************
 * Source File:
 *    Fragment : The representation of a child class, Fragment.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Fragment breaks off of Satellite and Parts.
 ************************************************************************/

#include "fragment.h"

/***************************************************
 * FRAGMENT: OPERATOR = OVERLOAD
 ***************************************************/
Fragment& Fragment::operator= (Fragment& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * FRAGMENT : ROTATE
 ***************************************************/
void Fragment::rotate(bool clockwise)
{
   if (clockwise)
   {
      dir += 1;
   }
   else
   {
      dir += -1;
   }
}

/***************************************************
 * FRAGMENT : DRAW
 ***************************************************/
void Fragment::draw(ogstream& gout) const
{
   gout.drawFragment(pos, dir.getAngle());
}
