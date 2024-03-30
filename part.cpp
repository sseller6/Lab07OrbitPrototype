/***********************************************************************
 * Source File:
 *    Part : The representation of a the parent & child class, part.
 * Author:
 *    Josh & Steven
 * Summary:
 *
 ************************************************************************/

#include "part.h"

/***************************************************
 * PART : OPERATOR = OVERLOAD
 ***************************************************/
void Part::operator= (Part& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;
}

/***************************************************
 * PART : ROTATE
 ***************************************************/
void Part::rotate(bool clockwise)
{
   if (clockwise)
   {
      dir += 0.1;
   }
   else
   {
      dir += -0.1;
   }
}
