/***********************************************************************
 * Header File:
 *    HubbleRightArray : The representation of a child class, HubbleRightArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble right array breaks off of the Hubble.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"

class HubbleRightArray : public Part
{
public:
   // constructors
   HubbleRightArray() : Part() {}
   HubbleRightArray(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void rotate(bool clockwise = true);
   void draw(ogstream& gout) const override;

   // operators
   HubbleRightArray& operator= (HubbleRightArray& rhs);
   
private:
   double radius = 8.0;
};
