/***********************************************************************
 * Header File:
 *    Acceleration
 * Author:
 *    Josh and Steven
 * Summary:
 *    The header file for acceleration.
 ************************************************************************/

#pragma once
#include <cmath>

/***************************************************
 * ACCELERATION
 * All the code needed for handling acceleration.
 ***************************************************/
class Acceleration
{
public:
   Acceleration() : ddx(0.0), ddy(0.0) {}
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) {}
   
   double getDdx() const { return ddx; }
   double getDdy() const { return ddy; }
   double getAngle() const     { return atan2(ddy, ddx); }
   double getMagnitude() const { return sqrt(pow(ddx , 2) + pow(ddy , 2)); }
   
   void setDdx(double ddx) { this->ddx = ddx; }
   void setDdy(double ddy) { this->ddx = ddy; }
   void setAngleMag(double angle, double mag);
   
   void reverse();

   // Operators
   Acceleration operator+ (const Acceleration& rhs) const;
   Acceleration& operator+= (const Acceleration& rhs);
   
private:
   double ddx;
   double ddy;
   
};
