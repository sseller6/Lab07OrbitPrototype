/***********************************************************************
 * Header File:
 *    DragonLeftArray : The representation of a child class, DragonLeftArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon left array breaks off of the Dragon.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"

class DragonLeftArray : public Part
{
public:
   // constructors
   DragonLeftArray() : Part() {}
   DragonLeftArray(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void rotate(bool clockwise = true);
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }

   // operators
   DragonLeftArray& operator= (DragonLeftArray& rhs);
   
private:
   double radius = 6.0;
};