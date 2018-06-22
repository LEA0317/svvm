#include "avx2svvm.h"

void test(ymm *x, ymm *y, ymm *z) {
  *z = (*x).f * *y;
}
