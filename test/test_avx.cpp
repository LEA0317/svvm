#include "avxsvvm.h"

void test(xmm *x, xmm *y, xmm *z) {
  mask m = (*x).f > (*y).f;
  *z = m._div((*x).f , (*y).f);
}
