/***********************************************************************
 * Source File:
 *    GPSRightArray : The representation of a child class, GPSRightArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The GPS right array breaks off of the GPS.
 ************************************************************************/

#define _USE_MATH_DEFINES
#include <cmath>
#include "GPSRightArray.h"

/***************************************************
 * GPS LEFT ARRAY : OPERATOR = OVERLOAD
 ***************************************************/
GPSRightArray& GPSRightArray::operator= (GPSRightArray& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * GPS LEFT ARRAY : DRAW
 ***************************************************/
void GPSRightArray::draw(ogstream& gout) const
{
   gout.drawGPSRight(pos, dir.getAngle());
}

/***************************************************
 * GPS RIGHT ARRAY : BREAK APART
 ***************************************************/
vector<Satellite*> GPSRightArray::breakApart()
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
