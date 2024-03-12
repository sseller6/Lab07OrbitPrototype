/***********************************************************************
 * Source File:
 *    Direction : The representation of a direction.
 * Author:
 *    Josh & Steven
 * Summary:
 *    Satellites have direction, which determines rotation. This class
 *    provides all necessary functionality.
 ************************************************************************/

#include "direction.h"

void Direction::normalize()
{
   while (angle > 2 * M_PI)
   {
      angle -= 2 * M_PI;
   }
   while (angle < 2 * M_PI)
   {
      angle += 2 * M_PI;
   }
}