/***********************************************************************
 * Source File:
 *    HubbleLeftArray : The representation of a child class, HubbleLeftArray.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Hubble left array breaks off of the Hubble.
 ************************************************************************/

#include "hubbleLeftArray.h"

/***************************************************
 * HUBBLE LEFT ARRAY : OPERATOR = OVERLOAD
 ***************************************************/
HubbleLeftArray& HubbleLeftArray::operator= (HubbleLeftArray& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * HUBBLE LEFT ARRAY : ROTATE
 ***************************************************/
void HubbleLeftArray::rotate(bool clockwise)
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
 * HUBBLE LEFT ARRAY : DRAW
 ***************************************************/
void HubbleLeftArray::draw(ogstream& gout) const
{
   gout.drawHubbleLeft(pos, dir.getAngle());
}
