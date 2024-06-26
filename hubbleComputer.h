/***********************************************************************
 * Header File:
 *    HubbleComputer : The representation of a child class, HubbleComputer.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble computer breaks off of the Hubble.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"
#include "fragment.h"

/***************************************************
 * HUBBLE COMPUTER
 * The computer part of the hubble telescope.
 ***************************************************/
class HubbleComputer : public Part
{
public:
   // constructors
   HubbleComputer() : Part() {}
   HubbleComputer(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }
   
   // breaking apart
   vector<Satellite*> breakApart() override;

   // operators
   HubbleComputer& operator= (HubbleComputer& rhs);
   
private:
   double radius = 7.0;
};
