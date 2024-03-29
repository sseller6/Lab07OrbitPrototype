/***********************************************************************
 * Header File:
 *    DragonRightArray : The representation of a child class, DragonRightArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon right array breaks off of the Dragon.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"

/***************************************************
 * DRAGON RIGHT ARRAY
 * All the code needed for the dragon right array.
 * It is a child class of the Part class.
 ***************************************************/
class DragonRightArray : public Part
{
public:
   // constructors
   DragonRightArray() : Part() {}
   DragonRightArray(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void rotate(bool clockwise = true);
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }

   // operators
   DragonRightArray& operator= (DragonRightArray& rhs);
   
private:
   double radius = 6.0;
};
