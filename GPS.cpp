//
//  shipGPS.cpp
//  Lab07
//
//  Created by Josh Hamilton on 2/23/24.
//

#include "GPS.h"

void GPS::draw(ogstream &gout) const
{
   gout.drawGPS(pos, rotation);
}
