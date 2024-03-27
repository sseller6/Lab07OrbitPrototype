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