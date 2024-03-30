/***********************************************************************
 * Header File:
 *    Test Sputnik
 * Author:
 *    Josh & Steven
 * Summary:
 *    Everything for testing the child class, Sputnik.
 ************************************************************************/

#pragma once

#include "uiDraw.h"
#include "uiInteract.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "direction.h"
#include "sputnik.h"
#include "unitTest.h"

 /***************************************************
  * TEST SPUTNIK
  * The tests for testing Sputnik.
  ***************************************************/
class TestSputnik : public UnitTest
{
public:
   void run()
   {
      //move_ZeroSeconds();
      //move_OneSecond();
      //move_FortyEightSeconds();

      report("Sputnik");
   }

private:
   // utility function because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerance) const
   {
      double difference = value - test;
      return (difference >= -tolerance) && (difference <= tolerance);
   }

   //void move_ZeroSeconds();
   //void move_OneSecond();
   //void move_FortyEightSeconds();
};
