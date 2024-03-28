/***********************************************************************
 * Header File:
 *    HubbleTelescope : The representation of a child class, HubbleTelescope.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble telescope breaks off of the Hubble.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"

class HubbleTelescope : public Part
{
public:
   // constructors
   HubbleTelescope() : Part() {}
   HubbleTelescope(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void rotate(bool clockwise = true);
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }

   // operators
   HubbleTelescope& operator= (HubbleTelescope& rhs);
   
private:
   double radius = 10.0;
};
