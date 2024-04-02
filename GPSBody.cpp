/***********************************************************************
 * Source File:
 *    GPSBody : The representation of a child class, GPSBody.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The GPS body breaks off of the GPS.
 ************************************************************************/

#define _USE_MATH_DEFINES
#include <cmath>
#include "GPSBody.h"

/***************************************************
 * GPS BODY : OPERATOR = OVERLOAD
 ***************************************************/
GPSBody& GPSBody::operator= (GPSBody& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * GPS BODY : DRAW
 ***************************************************/
void GPSBody::draw(ogstream& gout) const
{
   gout.drawGPSCenter(pos, dir.getAngle());
}

/***************************************************
 * GPS BODY : BREAK APART
 ***************************************************/
vector<Satellite*> GPSBody::breakApart()
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
