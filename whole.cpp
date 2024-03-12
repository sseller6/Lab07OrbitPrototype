/***********************************************************************
 * Source File:
 *    Whole : The representation of a the parent & child class, whole.
 * Author:
 *    Josh & Steven
 * Summary:
 *    
 ************************************************************************/

#include "whole.h"

void Whole::operator= (Whole& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;
}