/***********************************************************************
 * Header File:
 *    Direction : The representation of a direction.
 * Author:
 *    Josh & Steven
 * Summary:
 *    Satellites have direction, which determines rotation. This class
 *    provides all necessary functionality.
 ************************************************************************/

#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

/***************************************************
 * DIRECTION
 * All the code needed for direction 
 * in the simulation.
 ***************************************************/
class Direction
{
public:
   // Constructors
   Direction() : angle(0.0) { }
   Direction(double angle) : angle(angle)                 { normalize(); }
   Direction(double dx, double dy) { angle = atan2(dx, dy); normalize(); }
   Direction(const Direction & rhs) { this->angle = rhs.angle; normalize(); }

   // Getters
   double getAngle()  const { return     angle;  }
   double getUnitDx() const { return sin(angle); }
   double getUnitDy() const { return cos(angle); }

   // Setters
   void setAngle(double angle)         { this->angle = angle; normalize();   }
   void setAngle(double dx, double dy) { angle = atan2(dx, dy); normalize(); }

   // Misc
   void addAngle(double angle) { this->angle += angle; }

   // Operators
   Direction operator+ (const Direction &rhs) const { return Direction(rhs.angle + angle); }
   Direction operator+ (double &rhs) const { return Direction(rhs + angle); }
   void operator+= (const Direction & rhs) { angle += rhs.angle; }
   void operator+= (double & rhs)  { angle += rhs; }
   void operator= (Direction& rhs) { angle = rhs.angle; }
   void operator= (double& rhs)    { angle = rhs; }

private:
   void normalize();

   double angle;
};