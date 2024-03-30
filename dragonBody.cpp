/***********************************************************************
 * Source File:
 *    DragonBody : The representation of a child class, DragonBody.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon body breaks off of the Dragon.
 ************************************************************************/

#include "dragonBody.h"

/***************************************************
 * DRAGON BODY : OPERATOR = OVERLOAD
 ***************************************************/
DragonBody& DragonBody::operator= (DragonBody& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * DRAGON BODY : DRAW
 ***************************************************/
void DragonBody::draw(ogstream& gout) const
{
   gout.drawCrewDragonCenter(pos, dir.getAngle());
}

/***************************************************
 * DRAGON BODY : BREAK APART
 ***************************************************/
vector<Satellite*> DragonBody::breakApart()
{
   /* spawn 4 fragments with:
    - between 5,000 - 9,000 m/s added to parent
    - random direction from parent
    - 4 pixels away from edge of parent
    - lifetime between 50-100 frames
    - 2 px radius
   */
   vector<Satellite*> frags = vector<Satellite*>();
   for (int i = 0; i < 4; i++)
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
