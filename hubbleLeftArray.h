/***********************************************************************
 * Header File:
 *    HubbleLeftArray : The representation of a child class, HubbleLeftArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble left array breaks off of the Hubble.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"

class HubbleLeftArray : public Part
{
public:
   // constructors
   HubbleLeftArray() : Part() {}
   HubbleLeftArray(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void rotate(bool clockwise = true);
   void draw(ogstream& gout) const override;

   // operators
   HubbleLeftArray& operator= (HubbleLeftArray& rhs);
   
private:
   double radius = 8.0;
};
