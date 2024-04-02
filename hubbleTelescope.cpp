/***********************************************************************
 * Source File:
 *    HubbleTelescope : The representation of a child class, HubbleTelescope.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble telescope breaks off of the Hubble.
 ************************************************************************/

#define _USE_MATH_DEFINES
#include <cmath>
#include "hubbleTelescope.h"

/***************************************************
 * HUBBLE TELESCOPE: OPERATOR = OVERLOAD
 ***************************************************/
HubbleTelescope& HubbleTelescope::operator= (HubbleTelescope& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * HUBBLE TELESCOPE: DRAW
 ***************************************************/
void HubbleTelescope::draw(ogstream& gout) const
{
   gout.drawHubbleTelescope(pos, dir.getAngle());
}

/***************************************************
 * HUBBLE TELESCOPE : BREAK APART
 ***************************************************/
vector<Satellite*> HubbleTelescope::breakApart()
{
   /* spawn 4 fragments with:
    - between 5,000 - 9,000 m/s added to parent
    - random direction from parent
    - 4 pixels away from edge of parent
    - lifetime between 50-100 frames
    - 2 px radius
   */
   vector<Satellite*> frags = vector<Satellite*>();
   for (int i = 0; i < 3; i++)
   {
      double breakoffAngle = random(0.0, 360.0) / 360.0 * 2 * M_PI;
      double fragX = pos.getPixelsX() + (radius + 4.0) * sin(breakoffAngle);
      double fragY = pos.getPixelsY() + (radius + 4.0) * cos(breakoffAngle);
      Position fragPos = Position(fragX, fragY);
      
      double kick = random(5000, 9000);
      Velocity fragVel = vel + Velocity(kick * sin(breakoffAngle), kick * cos(breakoffAngle));
      
      Direction fragDir = Direction(breakoffAngle);
      
      Fragment * frag = new Fragment(fragPos, fragVel, fragDir);
      frags.push_back(frag);
   }
   return frags;
}
