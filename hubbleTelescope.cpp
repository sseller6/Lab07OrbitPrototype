/***********************************************************************
 * Source File:
 *    HubbleTelescope : The representation of a child class, HubbleTelescope.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble telescope breaks off of the Hubble.
 ************************************************************************/

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
 * HUBBLE TELESCOPE: ROTATE
 ***************************************************/
void HubbleTelescope::rotate(bool clockwise)
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
 * HUBBLE TELESCOPE: DRAW
 ***************************************************/
void HubbleTelescope::draw(ogstream& gout) const
{
   gout.drawHubbleTelescope(pos, dir.getAngle());
}
