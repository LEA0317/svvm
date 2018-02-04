# svvm ver0.1
SIMD class wrapper for clang

You can write the code to generate SIMD as follows.

```
void test(ymm *ymm0, ymm *ymm1, ymm *ymm2) {
  (*ymm2).i = ((*ymm0).i + *ymm1) + *ymm2;
  (*ymm2).f = ymmf::sqrt((*ymm2).f);
}
```

Compile as follows.

```
$ clang++ -O3 -mavx2 test.cpp
```

I will update this wrapper (predicate instructions etc.) and implement AVX512 version.
The idea of this wrapper can also be applied to super wide SIMD.