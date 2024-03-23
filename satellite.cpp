/***********************************************************************
 * Source File:
 *    Satellite : The representation of a the parent class, satellite.
 * Author:
 *    Josh & Steven
 * Summary:
 *    All of our orbiting things will inherit from this class.
 ************************************************************************/

#include "satellite.h"

void Satellite::operator= (Satellite& rhs) 
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir; 
}


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

   double newDx = p.computeNewDx(vel, acc, time);
   double newDy = p.computeNewDy(vel, acc, time);
   vel.setDx(newDx);
   vel.setDy(newDy);

   double newX = p.computeNewX(pos, vel, acc, time);
   double newY = p.computeNewY(pos, vel, acc, time);

   pos.setMeters(newX, newY);
}


// Physics methods
double Satellite::Physics::heightFromPosition(Position& pos, Earth& e)
{
   double r = e.getRadius();
   double posX = pos.getMetersX();
   double posY = pos.getMetersY();
   return sqrt(pow(posX, 2) + pow(posY, 2)) - r;
}

double Satellite::Physics::gravityFromHeight(double height, Earth& e)
{
   double r = e.getRadius();
   double g = e.getGravity();
   return g * pow(r / (r + height), 2);
}

double Satellite::Physics::directionOfGravity(Position& pos, Earth& e)
{
   double earthX = e.getPos().getMetersX();
   double earthY = e.getPos().getMetersY();
   return atan2(earthX - pos.getMetersX(), earthY - pos.getMetersY());
}

double Satellite::Physics::computeNewDx(Velocity& vel, Acceleration& acc, double time)
{
   return vel.getDx() + acc.getDdx() * time;
}

double Satellite::Physics::computeNewDy(Velocity& vel, Acceleration& acc, double time)
{
   return vel.getDy() + acc.getDdy() * time;
}

double Satellite::Physics::computeNewX(Position& pos, Velocity& vel, Acceleration& acc, double time)
{
   return pos.getMetersX() + vel.getDx() * time + 0.5 * acc.getDdx() * pow(time, 2);
}

double Satellite::Physics::computeNewY(Position& pos, Velocity& vel, Acceleration& acc, double time)
{
   return pos.getMetersY() + vel.getDy() * time + 0.5 * acc.getDdy() * pow(time, 2);
}
