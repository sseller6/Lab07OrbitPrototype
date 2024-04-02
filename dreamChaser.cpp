/***********************************************************************
 * Source File:
 *    DreamChaser : The representation of a child class, DreamChaser.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The DreamChaser inherits from the Whole class.
 ************************************************************************/

#include "dreamChaser.h"

 /***************************************************
  * DREAM CHASER : OPERATOR = OVERLOAD
  ***************************************************/
DreamChaser& DreamChaser::operator= (DreamChaser& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * DREAM CHASER : MOVE
 ***************************************************/
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
   vel.computeNewVel(acc, time);
   
   // Calculate new position based on velocity and acceleration.
   pos.computeNewPos(vel, acc, time);
}

/***************************************************
 * DREAM CHASER : ROTATE
 ***************************************************/
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

/***************************************************
 * DREAM CHASER : SHOOT
 ***************************************************/
Satellite* DreamChaser::shoot() const
{
   // calculate starting position
   double shipXPx = pos.getPixelsX();
   double shipYPx = pos.getPixelsY();
   double projXPx = shipXPx + 19 * sin(dir.getAngle());
   double projYPx = shipYPx + 19 * cos(dir.getAngle());
   Position projPos = Position();
   projPos.setPixelsX(projXPx);
   projPos.setPixelsY(projYPx);
   
   // calculate velocity
   Velocity projVel = vel + Velocity(9000 * sin(dir.getAngle()), 9000 * cos(dir.getAngle()));
   
   // dummy direction
   Direction projDir = Direction(0.0);
   
   Projectile * proj = new Projectile(projPos, projVel, projDir);
   return proj;
}

/***************************************************
 * DREAM CHASER : DRAW
 ***************************************************/
void DreamChaser::draw(ogstream& gout) const
{
   gout.drawShip(pos, dir.getAngle(), thrusting);
}
