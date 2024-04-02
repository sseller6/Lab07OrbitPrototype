/***********************************************************************
 * Header File:
 *    Satellite : The representation of a satellite, anything that
 *                is affected by gravity.
 * Author:
 *    Josh & Steven
 * Summary:
 *    Everything we need to know about the parent class, satellite.
 ************************************************************************/

#pragma once
#include <vector>
#include "uiDraw.h"
#include "uiInteract.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "direction.h"
#include "earth.h"

using namespace std;

class TestSatellite;

/***************************************************
 * SATELLITE
 * The code needed for the parent class, satellite.
 ***************************************************/
class Satellite
{
public:
   friend TestSatellite;

   // constructors
   Satellite()  { }
   Satellite(Position &pos, Velocity &vel, Direction &dir) : pos(pos), vel(vel), dir(dir) { }
   
   // getters
   virtual double getRadius() const { return radius; }
   Position getPosition() const { return pos; }
   
   // living state & collision
   bool isInside(Satellite& sat) const;
   bool isInside(Earth &earth)   const;
   bool isDead() const { return dead; }
   void kill()   { dead = true; }

   // misc   
   virtual void move(float time, Earth& earth);
   void setRotation(Direction rotation) { dir = rotation; }

   // virtuals
   virtual void rotate(bool clockwise = true) { }
   virtual void draw(ogstream &gout) const    { }
   virtual vector<Satellite*> breakApart()    { return vector<Satellite*>(); }
   virtual void destroy()                     { delete this; }
   virtual bool breaks() const { return breaksApart; }
   virtual int getLifetime() const { return lifetime; }
   virtual void decrementLife()    { lifetime--; if (lifetime == 0) kill(); }
   virtual bool canExpire() const  { return expires; }

   // operators
   void operator= (Satellite& rhs);

protected:
   Position pos;
   Velocity vel;
   Direction dir;
   bool dead = false;
   double radius = 0.0;
   bool breaksApart = true;
   bool expires = false;
   int lifetime = 0;

   class Physics
   {
   public:
      double heightFromPosition(Position& pos, Earth& e);
      double gravityFromHeight(double height, Earth& e);
      double directionOfGravity(Position& pos, Earth& e);
   };
};
