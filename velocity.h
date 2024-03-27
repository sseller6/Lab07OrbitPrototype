/***********************************************************************
 * Header File:
 *    Velocity
 * Author:
 *    Josh and Steven
 * Summary:
 *    The code for the header file, velocity.h.
 ************************************************************************/

#pragma once
#include <cmath>
#include "acceleration.h"

/***************************************************
 * VELOCITY
 * All the code needed for handling velocity.
 ***************************************************/
class Velocity
{
public:
   Velocity() : dx(0.0), dy(0.0) {}
   Velocity(double dx, double dy) : dx(dx), dy(dy) {}
   Velocity(const Velocity& v) : dx (v.dx), dy (v.dy){}
   
   double getDx() const { return dx; }
   double getDy() const { return dy; }
   double getAngle() const     { return atan2(dy, dy); }
   double getMagnitude() const { return sqrt(pow(dx, 2) + pow(dy, 2)); }
   
   void setDx(double dx) { this->dx = dx; }
   void setDy(double dy) { this->dy = dy; }
   void setAngleMag(double angle, double mag);
   
   void computeNewVel(Acceleration& acc, double time);
   
private:
   double dx;
   double dy;
   
};
