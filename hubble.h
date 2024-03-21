/***********************************************************************
 * Header File:
 *    Hubble : The representation of a child class, Hubble.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble inherits from the Whole class.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

#include "whole.h"

class Hubble : public Whole
{
public:
   // constructors
   Hubble() : Whole() {}
   Hubble(Position& pos, Velocity& vel, Direction& dir) : Whole(pos, vel, dir) {}

   // attributes
   void rotate(bool clockwise = true);
   void draw(ogstream& gout) const override;

   // operators
   Hubble& operator= (Hubble& rhs);

   // tempORARYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
   string getString() { return "Successfully Displayed Hubble"; }
};
