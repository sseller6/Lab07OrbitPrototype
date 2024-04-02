/***********************************************************************
 * Source File:
 *    Dragon : The representation of a child class, Dragon.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The Dragon inherits from the Whole class.
 ************************************************************************/

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "dragon.h"

/***************************************************
 * DRAGON : OPERATOR = OVERLOAD
 ***************************************************/
Dragon& Dragon::operator= (Dragon& rhs)
{
   pos = rhs.pos;
   vel = rhs.vel;
   dir = rhs.dir;

   return *this;
}

/***************************************************
 * DRAGON : DRAW
 ***************************************************/
void Dragon::draw(ogstream& gout) const
{
   gout.drawCrewDragon(pos, dir.getAngle());
}

/***************************************************
 * DRAGON : BREAK APART
 ***************************************************/
vector<Satellite*> Dragon::breakApart()
{
   /* spawn 4 fragments with:
    - between 5,000 - 9,000 m/s added to parent
    - random direction from parent
    - 4 pixels away from edge of parent
    - lifetime between 50-100 frames
    - 2 px radius
   */
   vector<Satellite*> frags = vector<Satellite*>();
   for (int i = 0; i < 2; i++)
   {
      double breakoffAngle = random(0.0, 360.0) / 360.0 * 2 * M_PI;
      double fragX = pos.getPixelsX() + (radius + 4.0) * sin(breakoffAngle);
      double fragY = pos.getPixelsY() + (radius + 4.0) * cos(breakoffAngle);
      Position fragPos = Position();
      fragPos.setPixelsX(fragX);
      fragPos.setPixelsY(fragY);
      
      double kick = random(5000, 9000);
      Velocity fragVel = vel + Velocity(kick * sin(breakoffAngle), kick * cos(breakoffAngle));
      
      Direction fragDir = Direction(breakoffAngle);
      
      Fragment * frag = new Fragment(fragPos, fragVel, fragDir);
      frags.push_back(frag);
   }
   
   // spawn the body
   {
      double breakoffAngle = random(0.0, 360.0) / 360.0 * 2 * M_PI;
      double fragX = pos.getPixelsX() + (radius + 4.0) * sin(breakoffAngle);
      double fragY = pos.getPixelsY() + (radius + 4.0) * cos(breakoffAngle);
      Position fragPos = Position();
      fragPos.setPixelsX(fragX);
      fragPos.setPixelsY(fragY);
      
      double kick = random(5000, 9000);
      Velocity fragVel = vel + Velocity(kick * sin(breakoffAngle), kick * cos(breakoffAngle));
      
      Direction fragDir = Direction(breakoffAngle);
      
      DragonBody * body = new DragonBody(fragPos, fragVel, fragDir);
      frags.push_back(body);
   }
   
   // spawn the left array
   {
      double breakoffAngle = random(0.0, 360.0) / 360.0 * 2 * M_PI;
      double fragX = pos.getPixelsX() + (radius + 4.0) * sin(breakoffAngle);
      double fragY = pos.getPixelsY() + (radius + 4.0) * cos(breakoffAngle);
      Position fragPos = Position();
      fragPos.setPixelsX(fragX);
      fragPos.setPixelsY(fragY);
      
      double kick = random(5000, 9000);
      Velocity fragVel = vel + Velocity(kick * sin(breakoffAngle), kick * cos(breakoffAngle));
      
      Direction fragDir = Direction(breakoffAngle);
      
      DragonLeftArray * left = new DragonLeftArray(fragPos, fragVel, fragDir);
      frags.push_back(left);
   }
   
   // spawn the right array
   {
      double breakoffAngle = random(0.0, 360.0) / 360.0 * 2 * M_PI;
      double fragX = pos.getPixelsX() + (radius + 4.0) * sin(breakoffAngle);
      double fragY = pos.getPixelsY() + (radius + 4.0) * cos(breakoffAngle);
      Position fragPos = Position();
      fragPos.setPixelsX(fragX);
      fragPos.setPixelsY(fragY);
      
      double kick = random(5000, 9000);
      Velocity fragVel = vel + Velocity(kick * sin(breakoffAngle), kick * cos(breakoffAngle));
      
      Direction fragDir = Direction(breakoffAngle);
      
      DragonRightArray * right = new DragonRightArray(fragPos, fragVel, fragDir);
      frags.push_back(right);
   }
   
   return frags;
}
