/***********************************************************************
 * Source File:
 *    GPSBody : The representation of a child class, GPSBody.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The GPS body breaks off of the GPS.
 ************************************************************************/

#include "GPSBody.h"

GPSBody& GPSBody::operator= (GPSBody& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void GPSBody::rotate(bool clockwise)
{
   if (clockwise)
   {
      dir += 0.01;
   }
   else
   {
      dir += -0.01;
   }
}

void GPSBody::draw(ogstream& gout) const
{
   gout.drawGPSCenter(pos, dir.getAngle());
}
