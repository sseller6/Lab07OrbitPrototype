/***********************************************************************
 * Source File:
 *    HubbleComputer : The representation of a child class, HubbleComputer.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble computer breaks off of the Hubble.
 ************************************************************************/

#include "hubbleComputer.h"

HubbleComputer& HubbleComputer::operator= (HubbleComputer& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

void HubbleComputer::rotate(bool clockwise)
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

void HubbleComputer::draw(ogstream& gout) const
{
   gout.drawHubbleComputer(pos, dir.getAngle());
}
