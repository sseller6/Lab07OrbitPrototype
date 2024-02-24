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

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POINT
#include "physics.h"    // for PHYSICS

// Ship classes
#include "shipGPS.h"
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
      double speedGPS = 3100.0;
      double angleGPS = M_PI / 6.0;  // π/6
      Position posGPS = Position(42164000 * sin(angleGPS), 42164000 * cos(angleGPS));
      Velocity velGPS = Velocity();
      velGPS.setAngleMag(angleGPS - (M_PI / 2), speedGPS);
      shipGPS = new GPS();
      shipGPS->setPosition(posGPS);
      shipGPS->setVelocity(velGPS);

      ptStar.setMeters(posGPS.getMetersX(), posGPS.getMetersY());
      
      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;
   }
   
   GPS * shipGPS;
   Position ptStar;
   Position ptUpperRight;

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;
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
   
   // FOR FUTURE REFERENCE
   // Ships to add: Hubble, Sputnik, Starlink, CrewDragon, Ship
   
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
   pDemo->angleEarth -= 0.01;
   
   // rotate the ship
   pDemo->angleShip += 0.01;
//   pDemo->shipGPS->rotate(false);
   
   // phase up the star
   pDemo->phaseStar++;
   
   // do physics stuff
   pDemo->shipGPS->update();
   

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   pDemo->shipGPS->draw(gout);

   // draw a single star
   gout.drawStar(pDemo->ptStar, pDemo->phaseStar);

   // draw the earth
   pt.setMeters(Physics::getEarthX(), Physics::getEarthY());
   gout.drawEarth(pt, pDemo->angleEarth);
}

// Good spot to set our static variables.
double Position::metersFromPixels = 40.0;
double Physics::t = 48;
double Physics::g = -9.80665;
double Physics::r = 6378000;
double Physics::earthX = 0;
double Physics::earthY = 0;

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
