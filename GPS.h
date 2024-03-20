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

class GPS : public Whole
{
public:
   // constructors
   GPS() : Whole() {}
   GPS(Position &pos, Velocity &vel, Direction &dir) : Whole(pos, vel, dir) {}

   // attributes
   void rotate(bool clockwise = true);
   void draw(ogstream &gout) const override;

   // operators
   GPS& operator= (GPS& rhs);
};
