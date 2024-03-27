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

#include "uiDraw.h"
#include "uiInteract.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "direction.h"
#include "earth.h"

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
   Satellite(Position &pos, Velocity &vel, Direction &dir) : pos(pos), vel(vel), dir(dir), radius(0.0) { }
   
   // getters
   float getRadius() const { return radius; }
   Position getPosition() const { return pos; }
   
   // living state
   //bool isDead() const { return dead; }
   //void kill()   { dead = true; }

   // misc   
   virtual void move(float time, Earth& earth);
   void setRotation(Direction rotation) { dir = rotation; }

   // virtuals
   virtual void rotate(bool clockwise = true) { }
   virtual void draw(ogstream &gout) const    { }
   //virtual void breakApart()                  { }
   //virtual void destroy()                     { }

   // operators
   void operator= (Satellite& rhs);

   // tempORARY
   virtual string getString() { return "Satellite"; }

protected:
   Position pos;
   Velocity vel;
   Direction dir;
   //bool dead;
   float radius;

   class Physics
   {
   public:
      double heightFromPosition(Position& pos, Earth& e);
      double gravityFromHeight(double height, Earth& e);
      double directionOfGravity(Position& pos, Earth& e);
   };
};
