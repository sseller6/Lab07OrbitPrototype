/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#define _USE_MATH_DEFINES

#include <cassert>      // for ASSERT
#include <cmath>        // for Pies :) Yum
#include <random>       // we so random
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "test.h"
#include "position.h"   // for POINT
#include "physics.h"    // for PHYSICS
#include "earth.h"      // for EARTH
#include "GPS.h"        // for GPS
#include "star.h"       // for STAR

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) : ptUpperRight(ptUpperRight)
   {
      // GPS
      double speedGPS = 3100.0;
      double angleGPS = M_PI / 6.0;  // π/6
      Position posGPS = Position(42164000 * sin(angleGPS), 42164000 * cos(angleGPS));
      Velocity velGPS = Velocity();
      velGPS.setAngleMag(angleGPS - (M_PI / 2), speedGPS);
      Direction dirGPS = Direction();
      gps = GPS(posGPS, velGPS, dirGPS);

      // 200 stars
      double halfWidth =  ptUpperRight.getMetersX() / 2;
      double halfHeight = ptUpperRight.getMetersY() / 2;
      for (int i = 0; i < 200; i++)
      {
         double x = random(-halfWidth, halfWidth);
         double y = random(-halfHeight, halfHeight);
         Star newStar = Star(x, y);
         newStar.setPhase(random(0, 255));
         stars[i] = newStar;
      }

      // earth
      earth = Earth();
   }
   
   GPS gps;
   Star stars[200];
   Earth earth;
   Position ptUpperRight;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL.    
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move by a little
//   if (pUI->isUp())
//      pDemo->ptShip.addPixelsY(1.0);
//   if (pUI->isDown())
//      pDemo->ptShip.addPixelsY(-1.0);
//   if (pUI->isLeft())
//      pDemo->ptShip.addPixelsX(-1.0);
//   if (pUI->isRight())
//      pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //

   // rotate the earth
   pDemo->earth.rotate((2 * M_PI) / (double)1800);
   
   // rotate the satellites
   pDemo->gps.rotate();
   
   // phase up the stars
   for (int i = 0; i < 200; i++)
   {
      pDemo->stars[i].phaseUp();
   }
   
   // do physics stuff
   pDemo->gps.move(48);
   

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   pDemo->gps.draw(gout);

   // draw stars
   for (int i = 0; i < 200; i++)
   {
      pDemo->stars[i].draw(gout);
   }

   // draw the earth
   pDemo->earth.draw(gout);
}

// Good spot to set our static variables.
double Position::metersFromPixels = 40.0;

double Earth::gravity = -9.80665;
double Earth::radius = 6378000;
Position Earth::pos = Position(0.0, 0.0);

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
