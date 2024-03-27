/***********************************************************************
 * Header File:
 *    Test Position : Test the Position class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/


#pragma once

#include <iostream>
#include "position.h"
#include "unitTest.h"
#include <cassert>

using namespace std;

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestPosition : public UnitTest
{
public:
   void run()
   {
      Position().setZoom(1000.0 /* 1km equals 1 pixel */);
      defaultConstructor();
      nonDefaultConstructor();
      copyConstructor();
      assignment();
 
      setPixels();
      setMeters();
      
      addPixels();
      addMeters();
      
      report("Position");
   }
   
private:
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }

   /***************************************************
    * TESTPOSITION : DEFAULT CONSTRUCTOR
    ***************************************************/
   void defaultConstructor()
   {  // setup
      // exercise
      Position pos;
      // verify
      assertUnit(pos.x == 0.0);
      assertUnit(pos.y == 0.0);
   }  // teardown

   /***************************************************
    * TESTPOSITION : NON-DEFAULT CONSTRUCTOR
    ***************************************************/
   void nonDefaultConstructor()
   {  // setup
      // exercise
      Position pos(3000.0, 9000.0);
      // verify
      assertUnit(pos.x == 3000.0);
      assertUnit(pos.y == 9000.0);
   }  // teardown

   /***************************************************
    * TESTPOSITION : COPY CONSTRUCTOR
    ***************************************************/
   void copyConstructor()
   {  // setup
      Position pos1;
      pos1.x = 4000.0;
      pos1.y = 2000.0;
      // exercise
      Position pos2(pos1);
      // verify
      assertUnit(pos1.x == 4000.0);
      assertUnit(pos1.y == 2000.0);
      assertUnit(pos2.x == 4000.0);
      assertUnit(pos2.y == 2000.0);
   }  // teardown

   /***************************************************
    * TESTPOSITION : ASSIGNMENT
    ***************************************************/
   void assignment()
   {  // setup
      Position pos1;
      pos1.x = 4000.0;
      pos1.y = 2000.0;
      // exercise
      Position pos2 = pos1;
      // verify
      assertUnit(pos1.x == 4000.0);
      assertUnit(pos1.y == 2000.0);
      assertUnit(pos2.x == 4000.0);
      assertUnit(pos2.y == 2000.0);
   }  // teardown

   /***************************************************
    * TESTPOSITION : SET METERS
    ***************************************************/
   void setMeters()
   {  // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      // exercise
      pos.setMetersX(5000.0);
      pos.setMetersY(3000.0);
      // verify
      assertUnit(pos.x == 5000.0);
      assertUnit(pos.y == 3000.0);
   }  // teardown

   /***************************************************
    * TESTPOSITION : SET PIXELS
    ***************************************************/
   void setPixels()
   {  // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      // exercise
      pos.setPixelsX(6.0);
      pos.setPixelsY(12.0);
      // verify
      assertUnit(pos.x == 6000.0);
      assertUnit(pos.y == 12000.0);
   }  // teardown

   /***************************************************
    * TESTPOSITION : ADD METERS
    ***************************************************/
   void addMeters()
   {  // setup
      Position pos;
      pos.x = 800.0;
      pos.y = 1600.0;
      // exercise
      pos.addMetersX(-400.0);
      pos.addMetersY(800.0);
      // verify
      assertUnit(pos.x == 400.0);
      assertUnit(pos.y == 2400.0);
   }  // teardown

   /***************************************************
    * TESTPOSITION : ADD PIXELS
    ***************************************************/
   void addPixels()
   {  // setup
      Position pos;
      pos.x = 2000.0;
      pos.y = 4000.0;
      // exercise
      pos.addPixelsX(2);
      pos.addPixelsY(3);
      // verify
      assertUnit(pos.x == 4000.0);
      assertUnit(pos.y == 7000.0);
   }  // teardown
};
