/***********************************************************************
 * Header File:
 *    Fragment : The representation of a fragment in space, or one
 *            that has broken off of a satellite.
 * Author:
 *    Josh & Steven
 * Summary:
 *    Everything we need to know about the child class, fragment.
 ************************************************************************/

#pragma once

#include "satellite.h"

/***************************************************
 * FRAGMENT
 * The child class which each fragment derives from.
 ***************************************************/
class Fragment : public Satellite
{
public:
   // constructors
   Fragment() : Satellite() { }
   Fragment(Position &pos, Velocity &vel, Direction &dir) : Satellite(pos, vel, dir) { }
   
   // breaking & lifetime
   bool breaks() const override     { return breaksApart; }
   int getLifetime() const override { return lifetime; }
   void decrementLife() override    { lifetime--; if (lifetime == 0) kill(); }
   bool canExpire() const override  { return expires; }

   // overrides
   void rotate(bool clockwise) override;
   void draw(ogstream &gout) const override;
   double getRadius() const override { return radius; }

   // operators
   Fragment& operator= (Fragment& rhs);
   
private:
   double radius = 2.0;
   bool breaksApart = false;
   bool expires = true;
   int lifetime = random(50, 100);
};
