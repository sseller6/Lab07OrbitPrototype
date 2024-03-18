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

class TestSatellite;

class Satellite
{
public:
   friend TestSatellite;

   // constructors
   Satellite()  { }
   Satellite(Position &pos, Velocity &vel, Direction &dir) : pos(pos), vel(vel), dir(dir) { }
   
   // getters
   //float getRadius() const { return radius; }
   Position getPosition() const { return pos; }
   
   // living state
   //bool isDead() const { return dead; }
   //void kill()   { dead = true; }

   // misc   
   void move(float time);
   void setRotation(Direction rotation) { dir = rotation; }

   // virtuals
   virtual void rotate(bool clockwise = true) { }
   virtual void draw(ogstream &gout)          { std::cout << "INCORRECT" << std::endl; }
   //virtual void breakApart()                  { }
   //virtual void input(ogstream &ui)           { }
   //virtual void destroy()                     { }

   // operators
   void operator= (Satellite& rhs);

   // temp
   string getString() { return "Hi"; }

protected:
   Position pos;
   Velocity vel;
   Direction dir;
   //bool dead;
   //float radius;

   class Physics
   {
   public:
      double heightFromPosition(Position& pos);
      double gravityFromHeight(double height);
      double directionOfGravity(Position& pos);
      double computeNewDx(Velocity& vel, Acceleration& acc, double time);
      double computeNewDy(Velocity& vel, Acceleration& acc, double time);
      double computeNewX(Position& pos, Velocity& vel, Acceleration& acc, double time);
      double computeNewY(Position& pos, Velocity& vel, Acceleration& acc, double time);
   };
};

class SatelliteFake : Satellite
{
public:


private:

};