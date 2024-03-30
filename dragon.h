/***********************************************************************
 * Header File:
 *    Dragon : The representation of a child class, Dragon.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon inherits from the Whole class.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "dragonBody.h"
#include "dragonLeftArray.h"
#include "dragonRightArray.h"

#include "whole.h"

class TestDragon;

/***************************************************
 * DRAGON
 * All the information for the dragon.
 ***************************************************/
class Dragon : public Whole
{
public:
   // constructors
   Dragon() : Whole() {}
   Dragon(Position& pos, Velocity& vel, Direction& dir) : Whole(pos, vel, dir) {}

   // attributes
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }
   
   // breaking apart
   vector<Satellite*> breakApart() override;

   // operators
   Dragon& operator= (Dragon& rhs);
   
private:
   double radius = 7.0;
};
