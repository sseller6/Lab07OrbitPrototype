/***********************************************************************
 * Header File:
 *    DragonLeftArray : The representation of a child class, DragonLeftArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon left array breaks off of the Dragon.
 ************************************************************************/

#pragma once
#include <vector>
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"
#include "fragment.h"

/***************************************************
 * DRAGON LEFT ARRAY
 * All the code needed for the dragon left array.
 * It is a child class of the Part class.
 ***************************************************/
class DragonLeftArray : public Part
{
public:
   // constructors
   DragonLeftArray() : Part() {}
   DragonLeftArray(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }
   
   // breaking apart
   vector<Satellite*> breakApart() override;

   // operators
   DragonLeftArray& operator= (DragonLeftArray& rhs);
   
private:
   double radius = 6.0;
};
