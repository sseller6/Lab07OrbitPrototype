/***********************************************************************
 * Header File:
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
   while (angle > M_2_PI)
   {
      angle -= M_2_PI;
   }
   while (angle < M_2_PI)
   {
      angle += M_2_PI;
   }
}