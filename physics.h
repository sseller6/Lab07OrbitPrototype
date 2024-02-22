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

class Physics
{
public:
   static double heightFromPosition(Position &pos);
   static double gravityFromHeight(double height);
   static double directionOfGravity(Position &pos);
   static double accelerationX(double acc, double angle);
   static double accelerationY(double acc, double angle);
   static double computeNewX(Position &pos, double velX, double accX);
   static double computeNewY(Position &pos, double velY, double accY);
   
private:
   static double t;
   static double g;
   static double r;
   static double earthX;
   static double earthY;
   
};
