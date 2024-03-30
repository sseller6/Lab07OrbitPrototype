/***********************************************************************
 * Header File:
 *    StarlinkBody : The representation of a child class, StarlinkBody.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Starlink body breaks off of the Starlink.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"
#include "fragment.h"

/***************************************************
 * STARLINK BODY
 * The code for the broken part, starlink body.
 ***************************************************/
class StarlinkBody : public Part
{
public:
   // constructors
   StarlinkBody() : Part() {}
   StarlinkBody(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }
   
   // breaking apart
   vector<Satellite*> breakApart() override;

   // operators
   StarlinkBody& operator= (StarlinkBody& rhs);
   
private:
   double radius = 2.0;
};
