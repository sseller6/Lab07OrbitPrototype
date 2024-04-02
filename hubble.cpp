/***********************************************************************
 * Source File:
 *    Hubble : The representation of a child class, Hubble.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble inherits from the Whole class.
 ************************************************************************/

#define _USE_MATH_DEFINES
#include <cmath>
#include "hubble.h"

/***************************************************
 * HUBBLE : OPERATOR = OVERLOAD
 ***************************************************/
Hubble& Hubble::operator= (Hubble& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * HUBBLE : DRAW
 ***************************************************/
void Hubble::draw(ogstream& gout) const
{
   gout.drawHubble(pos, dir.getAngle());
}

/***************************************************
 * HUBBLE : BREAK APART
 ***************************************************/
vector<Satellite*> Hubble::breakApart()
{
   vector<Satellite*> frags = vector<Satellite*>();
   // spawn the telescope
   {
      double breakoffAngle = random(0.0, 360.0) / 360.0 * 2 * M_PI;
      double fragX = pos.getPixelsX() + (radius + 6.0) * sin(breakoffAngle);
      double fragY = pos.getPixelsY() + (radius + 6.0) * cos(breakoffAngle);
      Position fragPos = Position();
      fragPos.setPixelsX(fragX);
      fragPos.setPixelsY(fragY);
      
      double kick = random(5000, 9000);
      Velocity fragVel = vel + Velocity(kick * sin(breakoffAngle), kick * cos(breakoffAngle));
      
      Direction fragDir = Direction(breakoffAngle);
      
      HubbleTelescope * tele = new HubbleTelescope(fragPos, fragVel, fragDir);
      frags.push_back(tele);
   }
   
   // spawn the computer
   {
      double breakoffAngle = random(0.0, 360.0) / 360.0 * 2 * M_PI;
      double fragX = pos.getPixelsX() + (radius + 6.0) * sin(breakoffAngle);
      double fragY = pos.getPixelsY() + (radius + 6.0) * cos(breakoffAngle);
      Position fragPos = Position();
      fragPos.setPixelsX(fragX);
      fragPos.setPixelsY(fragY);
      
      double kick = random(5000, 9000);
      Velocity fragVel = vel + Velocity(kick * sin(breakoffAngle), kick * cos(breakoffAngle));
      
      Direction fragDir = Direction(breakoffAngle);
      
      HubbleComputer * comp = new HubbleComputer(fragPos, fragVel, fragDir);
      frags.push_back(comp);
   }
   
   // spawn the left array
   {
      double breakoffAngle = random(0.0, 360.0) / 360.0 * 2 * M_PI;
      double fragX = pos.getPixelsX() + (radius + 6.0) * sin(breakoffAngle);
      double fragY = pos.getPixelsY() + (radius + 6.0) * cos(breakoffAngle);
      Position fragPos = Position();
      fragPos.setPixelsX(fragX);
      fragPos.setPixelsY(fragY);
      
      double kick = random(5000, 9000);
      Velocity fragVel = vel + Velocity(kick * sin(breakoffAngle), kick * cos(breakoffAngle));
      
      Direction fragDir = Direction(breakoffAngle);
      
      HubbleLeftArray * left = new HubbleLeftArray(fragPos, fragVel, fragDir);
      frags.push_back(left);
   }
   
   // spawn the right array
   {
      double breakoffAngle = random(0.0, 360.0) / 360.0 * 2 * M_PI;
      double fragX = pos.getPixelsX() + (radius + 6.0) * sin(breakoffAngle);
      double fragY = pos.getPixelsY() + (radius + 6.0) * cos(breakoffAngle);
      Position fragPos = Position();
      fragPos.setPixelsX(fragX);
      fragPos.setPixelsY(fragY);
      
      double kick = random(5000, 9000);
      Velocity fragVel = vel + Velocity(kick * sin(breakoffAngle), kick * cos(breakoffAngle));
      
      Direction fragDir = Direction(breakoffAngle);
      
      HubbleRightArray * right = new HubbleRightArray(fragPos, fragVel, fragDir);
      frags.push_back(right);
   }
   
   return frags;
}

