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

/***************************************************
 * EARTH
 * The earth class is pretty simple.
 ***************************************************/
class Earth
{
public:
   Earth() : pos(Position(0.0, 0.0)), rotation(Direction(0.0)), radius(6378000), gravity(-9.80665) { }

   // getters
   virtual double getRadius()  const { return radius;  }
   virtual double getGravity() const { return gravity; }
   virtual Position getPos()   const { return pos;     }

   // Misc
   void rotate(double amount) { rotation += amount; }
   void draw(ogstream &gout) const { gout.drawEarth(pos, rotation.getAngle()); }

private:
   Position pos;
   Direction rotation;
   double radius;
   double gravity;
};


/***************************************************
 * STUB EARTH
 * Always returns simple, pre-specified values.
 ***************************************************/
class StubEarth : public Earth
{
public:
   double getRadius()  const override { return 6371000.0;  }
   double getGravity() const override { return 0.0;       }
   Position getPos()   const override { return Position(); }
};