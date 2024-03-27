/***********************************************************************
 * Source File:
 *    HubbleRightArray : The representation of a child class, HubbleRightArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble right array breaks off of the Hubble.
 ************************************************************************/

#include "hubbleRightArray.h"

HubbleRightArray& HubbleRightArray::operator= (HubbleRightArray& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void HubbleRightArray::rotate(bool clockwise)
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

void HubbleRightArray::draw(ogstream& gout) const
{
   gout.drawHubbleRight(pos, dir.getAngle());
}
