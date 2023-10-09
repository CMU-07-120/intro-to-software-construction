/*
 * Simple test case
 *
 * 15-122 Principles of Imperative Computation */


#include <stdlib.h>      // declares 'malloc' and 'free'
#include "lib/xalloc.h"  // declares 'xmalloc'
#include "lib/contracts.h" // declares IF_DEBUG
#include <assert.h>      // declares 'assert'
#include <stdio.h>       // akin to <conio>
#include <stdbool.h>     // declares 'true'
#include "simple.h"      // for separate compilation

int main(void) {
  struct point2d* P = xmalloc(sizeof(struct point2d));
  P->x = -15;
  P->y = 0; // uninitialized without: P->y could contain an arbitrary value
  P->y = P->y + absval(P->x * 2);
  assert(P->y > P->x && true);   // if P->y uninitialized, may succeeed or fail

  // free(P);  // wrong!
  printf("x coord: %d\n", P->x);
  printf("y coord: %d\n", P->y);  // if P->y uninitialized, may print anything

  free(P);
  // free(P);  // wrong!

  IF_DEBUG(printf("All done\n"); printf("Really!\n"));

  return 0;
}
