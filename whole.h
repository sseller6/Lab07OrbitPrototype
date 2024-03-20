/***********************************************************************
 * Header File:
 *    Whole : The representation of a whole satellite, or one
 *            that has not been broken apart yet.
 * Author:
 *    Josh & Steven
 * Summary:
 *    Everything we need to know about the child & parent class, whole.
 ************************************************************************/

#pragma once

#include "satellite.h"

class Whole : public Satellite
{
public:
   // constructors
   Whole() : Satellite() { }
   Whole(Position &pos, Velocity &vel, Direction &dir) : Satellite(pos, vel, dir) { }

   // virtuals
   virtual void draw(ogstream &gout) const override { }

   // operators
   void operator= (Whole& rhs);
};