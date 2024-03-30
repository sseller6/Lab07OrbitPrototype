/***********************************************************************
 * Source File:
 *    Whole : The representation of a the parent & child class, whole.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The source code for whole.cpp.
 ************************************************************************/

#include "whole.h"

/***************************************************
 * WHOLE : OPERATOR = OVERLOAD
 ***************************************************/
void Whole::operator= (Whole& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;
}

/***************************************************
 * WHOLE : ROTATE
 ***************************************************/
void Whole::rotate(bool clockwise)
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
