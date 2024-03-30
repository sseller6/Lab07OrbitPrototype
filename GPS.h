/***********************************************************************
 * Header File:
 *    GPS : The representation of a child class, GPS.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The GPS inherits from the Whole class.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "whole.h"
#include "GPSBody.h"
#include "GPSLeftArray.h"
#include "GPSRightArray.h"
#include "fragment.h"

/***************************************************
 * GPS
 * The blueprints for creaing a GPS.
 ***************************************************/
class GPS : public Whole
{
public:
   // constructors
   GPS() : Whole() {}
   GPS(Position &pos, Velocity &vel, Direction &dir) : Whole(pos, vel, dir) {}

   // attributes
   void draw(ogstream &gout) const override;
   double getRadius() const override { return radius; }
   
   // breaking apart
   vector<Satellite*> breakApart() override;

   // operators
   GPS& operator= (GPS& rhs);
   
private:
   double radius = 12.0;
};
