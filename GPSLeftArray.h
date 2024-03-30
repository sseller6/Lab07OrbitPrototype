/***********************************************************************
 * Header File:
 *    GPSLeftArray : The representation of a child class, GPSLeftArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The GPS left array breaks off of the GPS.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"
#include "fragment.h"

/***************************************************
 * GPS LEFT ARRAY
 * The information for creating the parts of the
 * GPS left array.
 ***************************************************/
class GPSLeftArray : public Part
{
public:
   // constructors
   GPSLeftArray() : Part() {}
   GPSLeftArray(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }
   
   // breaking apart
   vector<Satellite*> breakApart() override;

   // operators
   GPSLeftArray& operator= (GPSLeftArray& rhs);
   
private:
   double radius = 8.0;
};
