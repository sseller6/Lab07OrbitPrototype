/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testSatellite.h"
#include "testGPS.h"
#include "testDragon.h"
#include "testDreamChaser.h"
#include "testHubble.h"
#include "testSputnik.h"
#include "testStarLink.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   TestPosition().run();
   TestSatellite().run();
   TestGPS().run();
   TestDragon().run();
   TestDreamChaser().run();
   TestHubble().run();
   TestSputnik().run();
   TestStarLink().run();
}
