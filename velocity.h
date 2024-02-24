//
//  velocity.hpp
//  Lab07
//
//  Created by Josh Hamilton on 2/23/24.
//

#pragma once
#include <cmath>

class Velocity
{
public:
   Velocity() : dx(0.0), dy(0.0) {}
   Velocity(double dx, double dy) : dx(dx), dy(dy) {}
   
   double getDx() const { return dx; }
   double getDy() const { return dy; }
   double getAngle() const     { return atan2(dy, dy); }
   double getMagnitude() const { return sqrt(pow(dx, 2) + pow(dy, 2)); }
   
   void setDx(double dx) { this->dx = dx; }
   void setDy(double dy) { this->dy = dy; }
   void setAngleMag(double angle, double mag);
   
private:
   double dx;
   double dy;
   
};
