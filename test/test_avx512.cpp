#include "avx512svvm.h"

void test(zmm *x, zmm *y, zmm *z) {
  *z = (*x).f * *y;
}
