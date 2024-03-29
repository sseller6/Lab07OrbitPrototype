/***********************************************************************
 * Header File:
 *    GPSBody : The representation of a child class, GPSBody.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The GPS body breaks off of the GPS.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"

/***************************************************
 * GPS BODY
 * The information for creating the parts of the 
 * GPS body.
 ***************************************************/
class GPSBody : public Part
{
public:
   // constructors
   GPSBody() : Part() {}
   GPSBody(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void rotate(bool clockwise = true);
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }

   // operators
   GPSBody& operator= (GPSBody& rhs);
   
private:
   double radius = 7.0;
};
