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
   Earth() : pos(Position(0.0, 0.0)), rotation(Direction(0.0)) { }

   // getters
   double getRadius()  const { return radius;  }
   double getGravity() const { return gravity; }

   // Misc
   void rotate() { rotation.addAngle(0.01); }
   void draw(ogstream &gout) const { gout.drawEarth(pos, rotation.getAngle()); }

private:
   Position pos;
   Direction rotation;
   static double radius;
   static double gravity;
};