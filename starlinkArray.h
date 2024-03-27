/***********************************************************************
 * Header File:
 *    StarlinkArray : The representation of a child class, StarlinkArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Starlink array breaks off of the Starlink.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"

class StarlinkArray : public Part
{
public:
   // constructors
   StarlinkArray() : Part() {}
   StarlinkArray(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void rotate(bool clockwise = true);
   void draw(ogstream& gout) const override;

   // operators
   StarlinkArray& operator= (StarlinkArray& rhs);
   
private:
   double radius = 4.0;
};
