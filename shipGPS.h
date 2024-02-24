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

class GPS
{
public:
   GPS() : pos(Position()),
           vel(Velocity()),
           acc(Acceleration()),
           rotation(0) {}
   GPS(Position &pos) : pos(pos),
                        vel(Velocity()),
                        acc(Acceleration()),
                        rotation(0) {}
   
   void setPosition(Position &pos)         { this->pos = pos; }
   void setVelocity(Velocity &vel)         { this->vel = vel; }
   void setAcceleration(Acceleration &acc) { this->acc = acc; }
   
   void rotate(bool clockwise = true) { rotation += clockwise ? 0.01 : -0.01; }
   void setRotation(double rotation) { this->rotation = rotation; }
   
   void update();
   void draw(ogstream &gout) const;
   
private:
   Position pos;
   Velocity vel;
   Acceleration acc;
   double rotation;
   
};
