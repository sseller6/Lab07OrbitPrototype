/***********************************************************************
 * Header File:
 *    Test Dragon
 * Author:
 *    Josh & Steven
 * Summary:
 *    Everything for testing the child class, dragon.
 ************************************************************************/

#pragma once

#include "uiDraw.h"
#include "uiInteract.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "direction.h"
#include "dragon.h"
#include "unitTest.h"

/***************************************************
 * TEST DRAGON
 * The tests for testing dragon.
 ***************************************************/
class TestDragon : public UnitTest
{
public:
   void run()
   {
      tooFarToCollide();
      collisionHappens();

      report("Dragon");
   }

private:
   // utility function because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerance) const
   {
      double difference = value - test;
      return (difference >= -tolerance) && (difference <= tolerance);
   }

   // Test Methods
   void tooFarToCollide();
   void collisionHappens();

};
