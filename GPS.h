//
//  shipGPS.hpp
//  Lab07
//
//  Created by Josh Hamilton on 2/23/24.
//

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "physics.h"

#include "whole.h"

class GPS : public Whole
{
public:
   GPS() : Whole() {}
   GPS(Position &pos, Velocity &vel, Direction &dir) : Whole(pos, vel, dir) {}

   void rotate(bool clockwise = true);
   void draw(ogstream &gout) const;
};
