//
//  shipGPS.cpp
//  Lab07
//
//  Created by Josh Hamilton on 2/23/24.
//

#include "shipGPS.h"

void GPS::update()
{
   // Every calculation is affected by gravity.
   double height = Physics::heightFromPosition(pos);
   double grav = Physics::gravityFromHeight(height);
   double dir = Physics::directionOfGravity(pos);
   
   acc.setAngleMag(dir, grav);
   acc.reverse();
   
   double newDx = Physics::computeNewDx(vel, acc);
   double newDy = Physics::computeNewDy(vel, acc);
   vel.setDx(newDx);
   vel.setDy(newDy);
   
   double newX = Physics::computeNewX(pos, vel, acc);
   double newY = Physics::computeNewY(pos, vel, acc);
   
   pos.setMeters(newX, newY);
}

void GPS::draw(ogstream &gout) const
{
   gout.drawGPS(pos, rotation);
}
