/***********************************************************************
 * Header File:
 *    Physics : All the calculations we need
 * Author:
 *    Steven and Josh
 * Summary:
 *    Whatever calculations we will need will be provided
 *    by this class.
 ************************************************************************/

#pragma once
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

class Physics
{
public:
   // physics equations
   static double heightFromPosition(Position &pos);
   static double gravityFromHeight(double height);
   static double directionOfGravity(Position &pos);
   static double computeNewDx(Velocity &vel, Acceleration &acc);
   static double computeNewDy(Velocity &vel, Acceleration &acc);
   static double computeNewX(Position &pos, Velocity &vel, Acceleration &acc);
   static double computeNewY(Position &pos, Velocity &vel, Acceleration &acc);
   
   // getters
   static double getEarthX() { return earthX; }
   static double getEarthY() { return earthY; }
   
private:
   static double t;
   static double g;
   static double r;
   static double earthX;
   static double earthY;
   
};
