/***********************************************************************
 * Header File:
 *    Part : The representation of part of a satellite, or one
 *            that has been broken apart.
 * Author:
 *    Josh & Steven
 * Summary:
 *    Everything we need to know about the child & parent class, part.
 ************************************************************************/

#pragma once

#include "satellite.h"

/***************************************************
 * PART
 * The parent class which each part of a satelite 
 * derives from.
 ***************************************************/
class Part : public Satellite
{
public:
   // constructors
   Part() : Satellite() { }
   Part(Position &pos, Velocity &vel, Direction &dir) : Satellite(pos, vel, dir) { }

   // overrides
   void rotate(bool clockwise) override;
   
   // virtuals
   virtual void draw(ogstream &gout) const override { }

   // operators
   void operator= (Part& rhs);
};
