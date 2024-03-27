/***********************************************************************
 * Header File:
 *    Test Satellite
 * Author:
 *    Josh & Steven
 * Summary:
 *    Everything for testing the parent class, satellite.
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

class TestShip : public UnitTest
{
public:
   void run()
   {
      rotate_left();
      rotate_right();
      thrust();

      report("Satellite");
   }


private:
   // utility function because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerance) const
   {
      double difference = value - test;
      return (difference >= -tolerance) && (difference <= tolerance);
   }

   void rotate_left();
   void rotate_right();
   void thrust();
};