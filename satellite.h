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
#include "direction.h"

class Satellite
{
public:
   // constructors
   Satellite()  { }
   
   // getters
   float getRadius() const { return radius; }
   Position getPosition() const { return pos; }
   
   // living state
   bool isDead() const { return dead; }
   void kill()   { dead = true; }

   // virtuals
   virtual void draw(ogstream &gout) { }
   virtual void move(float time)     { }
   virtual void input(ogstream &ui)  { }
   //virtual void destroy()            { }


private:
   Position pos;
   Velocity vel;
   Direction dir;
   //bool dead;
   //float radius;
};