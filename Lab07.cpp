/*************************************************************
 * 1. Name:
 *      Josh and Steven
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
#include <vector>       // vectors are better :)
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "test.h"
#include "position.h"   // for POINT
#include "earth.h"      // for EARTH
#include "GPS.h"        // for GPS
#include "sputnik.h"    // for Sputnik
#include "hubble.h"     // for Hubble
#include "dragon.h"     // for Dragon
#include "starlink.h"   // for Starlink
#include "dreamChaser.h"// for DreamChaser
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
      // GPS's
      double GPSValues[6][4] = {
         //      POS_X,     POS_Y, VEL_X,    VEL_Y
         {           0,  26560000, -3880,        0},
         { 23001634.72,  13280000, -1940,  3360.18},
         { 23001634.72, -13280000,  1940,  3360.18},
         {           0, -26560000,  3880,        0},
         {-23001634.72, -13280000,  1940, -3360.18},
         {-23001634.72,  13280000, -1940, -3360.18}
      };

      for (int i = 0; i < 6; i++)
      {
         Position posGPS(GPSValues[i][0], GPSValues[i][1]);
         Velocity velGPS(GPSValues[i][2], GPSValues[i][3]);
         Direction dirGPS(random(0.0, 2 * M_PI));
         GPS * g = new GPS(posGPS, velGPS, dirGPS);
         sats.push_back(g);
      }
      
      // Sputnik
      Position posSputnik(-36515095.13, 21082000);
      Velocity velSputnik(2050, 2684.68);
      Direction dirSputnik(random(0.0, 2 * M_PI));
      Sputnik * s = new Sputnik(posSputnik, velSputnik, dirSputnik);
      sats.push_back(s);

      // Hubble
      Position posHubble(0, -42164000);
      Velocity velHubble(3100, 0);
      Direction dirHubble(random(0.0, 2 * M_PI));
      Hubble* h = new Hubble(posHubble, velHubble, dirHubble);
      sats.push_back(h);

      // Dragon
      Position posDragon(0, 8000000);
      Velocity velDragon(-7900, 0);
      Direction dirDragon(random(0.0, 2 * M_PI));
      Dragon* d = new Dragon(posDragon, velDragon, dirDragon);
      sats.push_back(d);
      
      // Starlink
      Position posStarlink(0, -13020000);
      Velocity velStarlink(5800, 0);
      Direction dirStarlink(random(0.0, 2 * M_PI));
      Starlink* sl = new Starlink(posStarlink, velStarlink, dirStarlink);
      sats.push_back(sl);

      // DreamChaser
      Position posDreamChaser;
      posDreamChaser.setPixelsX(-450);
      posDreamChaser.setPixelsY(450);
      Velocity velDreamChaser(0, -2000);
      Direction dirDreamChaser(-M_PI);
      ship = new DreamChaser(posDreamChaser, velDreamChaser, dirDreamChaser);

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
   }
   
   vector<Satellite*> sats;
   DreamChaser * ship;
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
   if (pUI->isDown())
      pDemo->ship->thrust();
   if (pUI->isLeft())
      pDemo->ship->rotate(false);
   if (pUI->isRight())
      pDemo->ship->rotate();


   //
   // perform all the game logic
   //

   // rotate the earth
   pDemo->earth.rotate((2 * M_PI) / (double)1800);
   
   // rotate the satellites
   for (int i = 0; i < pDemo->sats.size(); i++)
      pDemo->sats[i]->rotate();
   
   // phase up the stars
   for (int i = 0; i < 200; i++)
   {
      pDemo->stars[i].phaseUp();
   }
   
   // do physics stuff
   for (int i = 0; i < pDemo->sats.size(); i++)
      pDemo->sats[i]->move(48, pDemo->earth); // t = 48s

   pDemo->ship->move(48, pDemo->earth);
   

   //
   // check for collisions
   //
   for (Satellite * satCheck : pDemo->sats)
   {
      std::cout << "START" << std::endl;
      // check against each other satellite
      for (Satellite * sat : pDemo->sats)
      {
         if (sat != satCheck)
         {
            if (satCheck->isInside(*sat))
            {
               std::cout << "DESTROY" << std::endl;
               satCheck->destroy();
               sat->destroy();
            }
         }
      }

      // check against the earth
      
   }


   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   for (int i = 0; i < pDemo->sats.size(); i++)
      pDemo->sats[i]->draw(gout);
   
   pDemo->ship->draw(gout);
   pDemo->ship->thrust(false);

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
