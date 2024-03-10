/***********************************************************************
 * Header File:
 *    Star : The representation of stars.
 * Author:
 *    Josh & Steven
 * Summary:
 *    A simple class representing a star object.
 ************************************************************************/

#pragma once

#include "uiDraw.h"
#include "position.h"

class Star
{
public:
   // constructor
   Star() : pos(Position(0.0, 0.0)), phase(0) { }
   Star(Position &pos) : pos(pos) { }
   Star(double x, double y) : pos(Position(x, y)), phase(0) { }
   
   // setters
   void setPhase(unsigned char phase) { this->phase = phase; }

   // misc
   void phaseUp() { phase++; if (phase == 256) phase = 0; }
   void draw(ogstream &gout) const { gout.drawStar(pos, phase); }

private:
   Position pos;
   unsigned char phase;
};