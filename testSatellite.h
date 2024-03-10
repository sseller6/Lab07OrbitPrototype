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
#include "satellite.h"
#include "unitTest.h"

class TestSatellite : public UnitTest
{
public:
   void run()
   {
      // Testing a moving Satellite
      orbitCalc_topRight();
      //orbitCalc_topLeft();
      //orbitCalc_bottomRight();
      //orbitCalc_bottomLeft();
      //gravityDirection_moving();

      // Testing a Stationary Satellite
      //gravityDirection_stationary();

      report("Satellite");
   }


private:
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }

   void orbitCalc_topRight();
   void orbitCalc_topLeft();
   void orbitCalc_bottomRight();
   void orbitCalc_bottomLeft();
   void gravityDirection_moving();
   void gravityDirection_stationary();
};