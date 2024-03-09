/***********************************************************************
 * Header File:
 *    Direction : The representation of the earth.
 * Author:
 *    Josh & Steven
 * Summary:
 *    A simple class representing a simple object.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "direction.h"

class Earth
{
public:
   Earth() : rotation(Direction(0.0)) { }

   // getters
   static double getRadius()  { return radius;  }
   static double getGravity() { return gravity; }
   static Position getPos()   { return pos;     }

   // Misc
   void rotate() { rotation.addAngle(0.01); }
   void draw(ogstream &gout) const { gout.drawEarth(pos, rotation.getAngle()); }

private:
   static Position pos;
   Direction rotation;
   static double radius;
   static double gravity;
};