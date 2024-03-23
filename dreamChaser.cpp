/***********************************************************************
 * Source File:
 *    DreamChaser : The representation of a child class, DreamChaser.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The DreamChaser inherits from the Whole class.
 ************************************************************************/

#include "dreamChaser.h"

DreamChaser& DreamChaser::operator= (DreamChaser& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void DreamChaser::move(float time, Earth& earth)
{
   Physics p;
   
   // Calculate acceleration due to gravity.
   double height = p.heightFromPosition(pos, earth);
   double grav = p.gravityFromHeight(height, earth);
   double dirGrav = p.directionOfGravity(pos, earth);
   
   Acceleration acc = Acceleration();
   acc.setAngleMag(dirGrav, grav);
   acc.reverse();
   
   // Calculate acceleration due to thrust.
   if (thrusting)
   {
      Acceleration thrust = Acceleration();
      thrust.setAngleMag(dir.getAngle(), 2.0);
      acc += thrust;
   }
   
   // Calculate new velocity based on acceleration.
   double newDx = p.computeNewDx(vel, acc, time);
   double newDy = p.computeNewDy(vel, acc, time);
   vel.setDx(newDx);
   vel.setDy(newDy);
   
   // Calculate new position based on velocity and acceleration.
   double newX = p.computeNewX(pos, vel, acc, time);
   double newY = p.computeNewY(pos, vel, acc, time);
   
   pos.setMeters(newX, newY);
}

// Rotate the DreamChaser.
void DreamChaser::rotate(bool clockwise)
{
   if (clockwise)
   {
      dir += 0.1;
   }
   else
   {
      dir += -0.1;
   }
}

void DreamChaser::draw(ogstream& gout) const
{
   gout.drawShip(pos, dir.getAngle(), thrusting);
}
