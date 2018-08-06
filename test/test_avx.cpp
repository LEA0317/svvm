#include "avxsvvm.h"

void test(xmm *x, xmm *y, xmm *z) {
  mask m = (*x).d > (*y);
  *z = m._div((*x).d , (*y).d);
}
