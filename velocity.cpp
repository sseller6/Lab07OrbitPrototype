//
//  velocity.cpp
//  Lab07
//
//  Created by Josh Hamilton on 2/23/24.
//

#include "velocity.h"

void Velocity::setAngleMag(double angle, double mag)
{
   dx = mag * sin(angle);
   dy = mag * cos(angle);
}
