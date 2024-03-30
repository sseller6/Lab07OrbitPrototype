/***********************************************************************
 * Source File:
 *    Test Dragon
 * Author:
 *    Josh and Steven
 * Summary:
 *    The unit tests for the Dragon.
 ************************************************************************/

#define _USE_MATH_DEFINES

#include "earth.h"
#include "testDragon.h"
#include <cassert>
#include <cmath>

/***************************************************
 * TEST DRAGON : TOO FAR TOO COLlIDE
 ***************************************************/
void TestDragon::tooFarToCollide()
{
   // SETUP
   Dragon * d = new Dragon();
   d->pos.setMetersX(100);
   d->pos.getMetersY(100);
   // EXERCISE

   // VERIFY

   // TEARDOWN
}

/***************************************************
 * TEST DRAGON : COLLISION HAPPENS
 ***************************************************/
void TestDragon::collisionHappens()
{
   // SETUP

   // EXERCISE

   // VERIFY

   // TEARDOWN
}