/***********************************************************************
 * Source File:
 *    TEST KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the knight
 ************************************************************************/

#define _USE_MATH_DEFINES

#include "testSatellite.h"
#include <cassert>
#include <cmath>

void TestSatellite::orbitCalc_topRight()
{
   // SETUP
   Satellite * s = new Satellite();
   Direction d = Direction(1, 1);
   
   s->pos.setMeters(42164000 * sin(d.getAngle()), 42164000 * cos(d.getAngle()));
   s->vel.setAngleMag(d.getAngle() - M_PI_2, 3100.0);

   // EXERCISE
   s->move(100);

   // VERIFY
   assertUnit(closeEnough(29594453.88, s->pos.getMetersX(), 1));
   assertUnit(closeEnough(30032868.08, s->pos.getMetersY(), 1));

   // TEARDOWN
   delete s;
}

void TestSatellite::orbitCalc_topLeft()
{
   //// SETUP
   //Satellite * s = new Satellite();
   //Direction d = Direction(-1, 1);

   //s->pos.setMeters(42164000 * sin(d.getAngle()), 42164000 * cos(d.getAngle()));
   //s->vel.setAngleMag(d.getAngle() - M_PI_2, 3100.0);

   //// EXERCISE
   //s->move(100);

   //// VERIFY

   //// TEARDOWN
   //delete s;
}

void TestSatellite::orbitCalc_bottomRight()
{
   //// SETUP
   //Satellite * s = new Satellite();
   //Direction d = Direction(1, -1);

   //s->pos.setMeters(42164000 * sin(d.getAngle()), 42164000 * cos(d.getAngle()));
   //s->vel.setAngleMag(d.getAngle() - M_PI_2, 3100.0);

   //// EXERCISE
   //s->move(100);

   //// VERIFY

   //// TEARDOWN
   //delete s;
}

void TestSatellite::orbitCalc_bottomLeft()
{
   //// SETUP
   //Satellite * s = new Satellite();
   //Direction d = Direction(-1, -1);

   //s->pos.setMeters(42164000 * sin(d.getAngle()), 42164000 * cos(d.getAngle()));
   //s->vel.setAngleMag(d.getAngle() - M_PI_2, 3100.0);

   //// EXERCISE
   //s->move(100);

   //// VERIFY

   //// TEARDOWN
   //delete s;
}

void TestSatellite::gravityDirection_moving()
{
   // SETUP

   // EXERCISE

   // VERIFY

   // TEARDOWN
}

void TestSatellite::gravityDirection_stationary()
{
   // SETUP

   // EXERCISE

   // VERIFY

   // TEARDOWN
}
