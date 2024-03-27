/***********************************************************************
 * Source File:
 *    Satellite : The representation of a the parent class, satellite.
 * Author:
 *    Josh & Steven
 * Summary:
 *    All of our orbiting things will inherit from this class.
 ************************************************************************/

#include "satellite.h"

/***************************************************
 * SATELLITE : OPERATOR = OVERLOAD
 ***************************************************/
void Satellite::operator= (Satellite& rhs) 
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir; 
}

/***************************************************
 * SATELLITE : MOVE
 ***************************************************/
void Satellite::move(float time, Earth& earth)
{
   Physics p;

   // Every calculation is affected by gravity.
   double height = p.heightFromPosition(pos, earth);
   double grav = p.gravityFromHeight(height, earth);
   double dirGrav = p.directionOfGravity(pos, earth);

   Acceleration acc = Acceleration();
   acc.setAngleMag(dirGrav, grav);
   acc.reverse();

   vel.computeNewVel(acc, time);

   pos.computeNewPos(vel, acc, time);
}

/***************************************************
 * SATELLITE : PHYSICS : HEIGHT FROM POSITION
 ***************************************************/
double Satellite::Physics::heightFromPosition(Position& pos, Earth& e)
{
   double r = e.getRadius();
   double posX = pos.getMetersX();
   double posY = pos.getMetersY();
   return sqrt(posX * posX + posY * posY) - r;
}

/***************************************************
 * SATELLITE : PHYSICS : GRAVITY FROM HEIGHT
 ***************************************************/
double Satellite::Physics::gravityFromHeight(double height, Earth& e)
{
   double r = e.getRadius();
   double g = e.getGravity();
   return g * (r / (r + height)) * (r / (r + height));
}

/***************************************************
 * SATELLITE : PHYSICS : DIRECTION OF GRAVITY
 ***************************************************/ 
double Satellite::Physics::directionOfGravity(Position& pos, Earth& e)
{
   double earthX = e.getPos().getMetersX();
   double earthY = e.getPos().getMetersY();
   return atan2(earthX - pos.getMetersX(), earthY - pos.getMetersY());
}
