/***********************************************************************
 * Header File:
 *    DreamChaser : The representation of a child class, DreamChaser.
 * Author:
 *    Josh & Steven
 * Summary:
 *    The DreamChaser inherits from the Whole class.
 ************************************************************************/

#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "earth.h"
#include "whole.h"

class TestDreamChaser;

/***************************************************
 * DREAM CHASER
 * The blueprints for the Dream Chaser.
 ***************************************************/
class DreamChaser : public Whole
{
public:
   // constructors
   DreamChaser() : Whole(), thrusting(false) {}
   DreamChaser(Position& pos, Velocity& vel, Direction& dir) : Whole(pos, vel, dir), thrusting(false) {}

   // methods
   void rotate(bool clockwise = true);
   void thrust(bool thrusting = true ) { this->thrusting = thrusting; }
   void move(float time, Earth& earth) override;
   void draw(ogstream& gout) const override;
   double getRadius() const override { return radius; }

   // operators
   DreamChaser& operator= (DreamChaser& rhs);

private:
   double radius = 10.0;
   bool thrusting;
};
