/***********************************************************************
 * Header File:
 *    Starlink : The representation of a child class, Starlink.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Starlink inherits from the Whole class.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "whole.h"

/***************************************************
 * STARLINK
 * All the code for the child class, starlink.
 ***************************************************/
class Starlink : public Whole
{
public:
   // constructors
   Starlink() : Whole() {}
   Starlink(Position& pos, Velocity& vel, Direction& dir) : Whole(pos, vel, dir) {}

   // attributes
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }
   
   // breaking apart
//   vector<Satellite*> breakApart() override;

   // operators
   Starlink& operator= (Starlink& rhs);
   
private:
   double radius = 6.0;
};
