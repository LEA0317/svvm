#include "avxsvvm.h"

void test(xmm *x, xmm *y, xmm *z) {
  *z = (*x).f * *y;
}
