/*
 * Simple implementation
 *
 * 15-122 Principles of Imperative Computation */

#include <limits.h>           // declares INT_MIN
#include "lib/contracts.h"    // declares REQUIRES and ENSURES
#include "simple.h"           // imports interface

int absval(int x) {
  REQUIRES(x > INT_MIN);
  int res = x < 0 ? -x : x;
  ENSURES(res >= 0);
  return res;
}
