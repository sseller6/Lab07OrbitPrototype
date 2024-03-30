/***********************************************************************
 * Header File:
 *    Test Dream Chaser
 * Author:
 *    Josh & Steven
 * Summary:
 *    Everything for testing the child class, Dream Chaser.
 ************************************************************************/

#pragma once

#include "uiDraw.h"
#include "uiInteract.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "direction.h"
#include "dreamChaser.h"
#include "unitTest.h"

 /***************************************************
  * TEST DREAM CHASER
  * The tests for testing Dream Chaser.
  ***************************************************/
class TestDreamChaser : public UnitTest
{
public:
   void run()
   {
      //move_ZeroSeconds();
      //move_OneSecond();
      //move_FortyEightSeconds();

      report("Dragon");
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
