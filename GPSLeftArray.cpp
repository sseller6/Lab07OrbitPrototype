/***********************************************************************
 * Source File:
 *    GPSLeftArray : The representation of a child class, GPSLeftArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The GPS left array breaks off of the GPS.
 ************************************************************************/

#include "GPSLeftArray.h"

GPSLeftArray& GPSLeftArray::operator= (GPSLeftArray& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void GPSLeftArray::rotate(bool clockwise)
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

void GPSLeftArray::draw(ogstream& gout) const
{
   gout.drawGPSLeft(pos, dir.getAngle());
}
