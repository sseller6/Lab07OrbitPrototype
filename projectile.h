/***********************************************************************
 * Header File:
 *    Projectile : The representation of a projetile, shot by the
 *                 DreamChaser.
 * Author:
 *    Josh & Steven
 * Summary:
 *    Everything we need to know about the child class, projectile.
 ************************************************************************/

#pragma once

#include "satellite.h"

/***************************************************
 * Projectile
 * The child class.
 ***************************************************/
class Projectile : public Satellite
{
public:
   // constructors
   Projectile() : Satellite() { }
   Projectile(Position &pos, Velocity &vel, Direction &dir) : Satellite(pos, vel, dir) { }
   
   // breaking & lifetime
   bool breaks() const override     { return breaksApart; }
   int getLifetime() const override { return lifetime; }
   void decrementLife() override    { lifetime--; if (lifetime == 0) kill(); }
   bool canExpire() const override  { return expires; }

   // overrides
   void draw(ogstream &gout) const override { gout.drawProjectile(pos); }
   double getRadius() const override { return radius; }

   // operators
   Projectile& operator= (Projectile& rhs);
   
private:
   double radius = 0.5;
   bool breaksApart = false;
   bool expires = true;
   int lifetime = 70;
};
