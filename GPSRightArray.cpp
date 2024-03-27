/***********************************************************************
 * Source File:
 *    GPSRightArray : The representation of a child class, GPSRightArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The GPS right array breaks off of the GPS.
 ************************************************************************/

#include "GPSRightArray.h"

GPSRightArray& GPSRightArray::operator= (GPSRightArray& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void GPSRightArray::rotate(bool clockwise)
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

void GPSRightArray::draw(ogstream& gout) const
{
   gout.drawGPSRight(pos, dir.getAngle());
}
