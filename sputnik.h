/***********************************************************************
 * Header File:
 *    Sputnik : The representation of a child class, Sputnik.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Sputnik inherits from the Whole class.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "whole.h"
#include "fragment.h"

class TestSputnik;

/***************************************************
 * SPUTNIK
 * The information for the child class, Sputnik.
 ***************************************************/
class Sputnik : public Whole
{
public:
   // constructors
   Sputnik() : Whole() {}
   Sputnik(Position& pos, Velocity& vel, Direction& dir) : Whole(pos, vel, dir) {}

   // attributes
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }
   
   // destroying
   vector<Satellite*> breakApart() override;
   void destroy() override { delete this; }

   // operators
   Sputnik& operator= (Sputnik& rhs);
   
private:
   double radius = 4.0;
};
