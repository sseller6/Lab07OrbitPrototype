/***********************************************************************
 * Source File:
 *    TEST KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the knight
 ************************************************************************/

#define _USE_MATH_DEFINES

#include "earth.h"
#include "testSatellite.h"
#include <cassert>
#include <cmath>

void TestSatellite::move_ZeroSeconds()
{
   // SETUP
   Satellite * s = new Satellite();
   s->pos.setMetersX(100);
   s->pos.setMetersY(100);
   s->vel.setDx(50);
   s->vel.setDy(50);

   // EXERCISE
   s->move(0);

   // VERIFY
   assertUnit(closeEnough(s->pos.getMetersX(), 100.0, 0.01));
   assertUnit(closeEnough(s->pos.getMetersY(), 100.0, 0.01));

   // TEARDOWN
   delete s;
}

void TestSatellite::move_OneSecond()
{
   // SETUP
   Satellite* s = new Satellite();
   s->pos.setMetersX(100);
   s->pos.setMetersY(100);
   s->vel.setDx(50);
   s->vel.setDy(50);

   // EXERCISE
   s->move(1.0);

   // VERIFY
   std::cout << s->pos.getMetersX() << std::endl;
   std::cout << s->pos.getMetersY() << std::endl;
   assertUnit(closeEnough(s->pos.getMetersX(), 150.0, 0.1));
   assertUnit(closeEnough(s->pos.getMetersY(), 150.0, 0.1));

   // TEARDOWN
   delete s;
}