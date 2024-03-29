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
