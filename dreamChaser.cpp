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

void DreamChaser::move(float time)
{
   Physics p;

   // Every calculation is affected by gravity.

   // FIGURE OUT THRUSTING
   double height = p.heightFromPosition(pos);
   double grav = p.gravityFromHeight(height);
   double dirGrav = p.directionOfGravity(pos);

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
