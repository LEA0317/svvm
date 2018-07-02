# svvm ver0.2
SIMD class wrapper for clang

You can write the code to generate SIMD as follows.

```
void test(ymm *ymm0, ymm *ymm1, ymm *ymm2) {
  *ymm2 = ((*ymm0).i + *ymm1) + *ymm2;
  *ymm2 = ((*ymm2).f).sqrt();
}
```

Compile as follows.

```
with avxsvvm.h
$ clang++ -O3 -mavx     test.cpp -std=c++11

with avx2svvm.h
$ clang++ -O3 -mavx2    test.cpp -std=c++11

with avx512svvm.h
$ clang++ -O3 -mavx512f test.cpp -std=c++11
```

I will update this wrapper (predicate instructions etc.).

The idea of this wrapper can also be applied to super wide SIMD.
