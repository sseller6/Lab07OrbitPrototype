/***********************************************************************
 * Source File:
 *    TEST SHIP
 * Author:
 *    Josh & Steven
 * Summary:
 *    The unit tests for the controllable ship.
 ************************************************************************/

#define _USE_MATH_DEFINES

#include "testShip.h"
#include <cassert>
#include <cmath>

void TestShip::rotate_left()
{
   // SETUP
   DreamChaser * d = new DreamChaser();
   d->pos.setMetersX(0.0);
   d->pos.setMetersY(0.0);
   d->vel.setAngleMag(0.0, 0.0);
   d->dir.setAngle(0.0);

   // EXERCISE
   d->rotate(false);

   // VERIFY
   assertUnit(d->dir.getAngle() == 0.0 - 0.1);

   // TEARDOWN
   delete d;
}

void TestShip::rotate_right()
{
   // SETUP

   // EXERCISE

   // VERIFY

   // TEARDOWN
}

void TestShip::thrust()
{
   // SETUP

   // EXERCISE

   // VERIFY

   // TEARDOWN
}