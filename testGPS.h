/***********************************************************************
 * Header File:
 *    Test GPS
 * Author:
 *    Josh & Steven
 * Summary:
 *    Everything for testing the child class, GPS.
 ************************************************************************/

#pragma once

#include "uiDraw.h"
#include "uiInteract.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "direction.h"
#include "GPS.h"
#include "unitTest.h"

 /***************************************************
  * TEST GPS
  * The tests for testing GPS.
  ***************************************************/
class TestGPS : public UnitTest
{
public:
   void run()
   {
      //move_ZeroSeconds();
      //move_OneSecond();
      //move_FortyEightSeconds();

      report("GPS");
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
