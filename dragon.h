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

#include "whole.h"

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
   void rotate(bool clockwise = true);
   void draw(ogstream& gout) const override;

   // operators
   Dragon& operator= (Dragon& rhs);

   // tempORARYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
   string getString() { return "Successfully Displayed Dragon"; }
   
private:
   double radius = 7.0;
};
