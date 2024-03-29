/***********************************************************************
 * Header File:
 *    DragonBody : The representation of a child class, DragonBody.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon body breaks off of the Dragon.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "part.h"

/***************************************************
 * DRAGON BODY
 * All the information for the dragon body.
 ***************************************************/
class DragonBody : public Part
{
public:
   // constructors
   DragonBody() : Part() {}
   DragonBody(Position& pos, Velocity& vel, Direction& dir) : Part(pos, vel, dir) {}

   // attributes
   void rotate(bool clockwise = true);
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }

   // operators
   DragonBody& operator= (DragonBody& rhs);
   
private:
   double radius = 6.0;
};
