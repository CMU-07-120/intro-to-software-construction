/*
 * Simple interface
 *
 * 15-122 Principles of Imperative Computation */

#ifndef SIMPLE_H
#define SIMPLE_H

int absval(int x)
/*@requires x > INT_MIN; @*/
/*@ensures \result >= 0;  @*/ ;

struct point2d {
  int x;
  int y;
};

#endif
