/***********************************************************************
 * Source File:
 *    Test Satellite
 * Author:
 *    Josh and Steven
 * Summary:
 *    The unit tests for the Satellite.
 ************************************************************************/

#define _USE_MATH_DEFINES

#include "earth.h"
#include "testSatellite.h"
#include <cassert>
#include <cmath>

/***************************************************
 * TEST SATELLITE : MOVE ZERO SECONDS
 ***************************************************/
void TestSatellite::move_ZeroSeconds()
{
   // SETUP
   StubEarth e;
   Satellite * s = new Satellite();
   s->pos.setMetersX(100);
   s->pos.setMetersY(100);
   s->vel.setDx(50);
   s->vel.setDy(50);

   // EXERCISE
   s->move(0, e);

   // VERIFY
   assertUnit(closeEnough(s->pos.getMetersX(), 100.0, 0.01));
   assertUnit(closeEnough(s->pos.getMetersY(), 100.0, 0.01));

   // TEARDOWN
   delete s;
}

/***************************************************
 * TEST SATELLITE : MOVE ONE SECOND
 ***************************************************/
void TestSatellite::move_OneSecond()
{
   // SETUP
   StubEarth e;
   Satellite* s = new Satellite();
   s->pos.setMetersX(100);
   s->pos.setMetersY(100);
   s->vel.setDx(50);
   s->vel.setDy(50);

   // EXERCISE
   s->move(1.0, e);

   // VERIFY
   assertUnit(closeEnough(s->pos.getMetersX(), 150.0, 0.001));
   assertUnit(closeEnough(s->pos.getMetersY(), 150.0, 0.001));

   // TEARDOWN
   delete s;
}

/***************************************************
 * TEST SATELLITE : MOVE FORTY EIGHT SECONDS
 ***************************************************/
void TestSatellite::move_FortyEightSeconds()
{
   // SETUP
   StubEarth e;
   Satellite* s = new Satellite();
   s->pos.setMetersX(100);
   s->pos.setMetersY(100);
   s->vel.setDx(50);
   s->vel.setDy(50);

   // EXERCISE
   s->move(48.0, e);

   // VERIFY

   assertUnit(closeEnough(s->pos.getMetersX(), 2500.0, 0.001));
   assertUnit(closeEnough(s->pos.getMetersY(), 2500.0, 0.001));

   // TEARDOWN
   delete s;
}