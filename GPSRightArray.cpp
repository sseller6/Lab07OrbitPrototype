/***********************************************************************
 * Source File:
 *    GPSRightArray : The representation of a child class, GPSRightArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The GPS right array breaks off of the GPS.
 ************************************************************************/

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
 * GPS LEFT ARRAY : ROTATE
 ***************************************************/
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

/***************************************************
 * GPS LEFT ARRAY : DRAW
 ***************************************************/
void GPSRightArray::draw(ogstream& gout) const
{
   gout.drawGPSRight(pos, dir.getAngle());
}
