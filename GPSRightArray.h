/***********************************************************************
 * Header File:
 *    GPSRightArray : The representation of a child class, GPSRightArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The GPS right array breaks off of the GPS.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"

/***************************************************
 * GPS RIGHT ARRAY
 * The information for creating the parts of the
 * GPS right array.
 ***************************************************/
class GPSRightArray : public Part
{
public:
   // constructors
   GPSRightArray() : Part() {}
   GPSRightArray(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void rotate(bool clockwise = true);
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }

   // operators
   GPSRightArray& operator= (GPSRightArray& rhs);
   
private:
   double radius = 8.0;
};
