﻿#ifndef _AVX2_SVVM_H_
#define _AVX2_SVVM_H_

typedef float                    v8f32 __attribute__((ext_vector_type(8)));
typedef int                      v8i32 __attribute__((ext_vector_type(8)));
typedef unsigned int            uv8i32 __attribute__((ext_vector_type(8)));
typedef long long int            v4i64 __attribute__((ext_vector_type(4)));
typedef unsigned long long int  uv4i64 __attribute__((ext_vector_type(4)));
typedef double                   v4f64 __attribute__((ext_vector_type(4)));

typedef int           maski8 __attribute__((ext_vector_type(8)));
typedef long long int maskl4 __attribute__((ext_vector_type(4)));
typedef float         maskf8 __attribute__((ext_vector_type(8)));
typedef double        maskd4 __attribute__((ext_vector_type(4)));

struct int8;
struct uint8;
struct float8;
struct long4;
struct ulong4;
struct double4;
struct mask;
union  uYMM;

struct int8
{
  int8()             { u.val = 0; }
  int8(v8i32 assign) { u.val = assign; }
  int8(int   assign) { u.val = assign; }  
  union U {
    v8i32 val;
    int   elem[8];
  } u;

  // set
  __inline void set(int pos, int set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(int8 dst, int pos, int set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(int8 *dst, int pos, int set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline int get(int pos)
  {
    return u.elem[pos];
  }
  __inline static int get(int8 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static int get(int8 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float8  _assign);
  __inline void operator=(uint8   _assign);
  __inline void operator=(long4   _assign);
  __inline void operator=(double4 _assign);
  __inline void operator=(ulong4  _assign);

  // add  
  __inline int8& operator+(uYMM _add);
  __inline int8 operator+(int8 _add)
  {
    return int8(u.val + _add.u.val);
  }
  __inline int8 operator+(int _add)
  {
    return int8(u.val + (int8(_add)).u.val);
  }
 
  // sub
  __inline int8& operator-(uYMM _sub);
  __inline int8 operator-(int8 _sub)
  {
    return int8(u.val - _sub.u.val);
  }
  __inline int8 operator-(int _sub)
  {
    return int8(u.val - (int8(_sub)).u.val);
  }

  // multiply
  __inline int8& operator*(uYMM _mul);
  __inline int8 operator*(int8 _mul)
  {
    return int8(u.val * _mul.u.val);
  }
  __inline int8 operator*(int _mul)
  {
    return int8(u.val * (int8(_mul)).u.val);
  }

  // divide
  __inline int8& operator/(uYMM _div);
  __inline int8 operator/(int8 _div)
  {
    return int8(u.val / _div.u.val);
  }
  __inline int8 operator/(int _div)
  {
    return int8(u.val / (int8(_div)).u.val);
  }

  // modulo (not SIMD)
  __inline int8& operator%(uYMM _mod);
  __inline int8 operator%(int8 _mod)
  {
    return int8(u.val % _mod.u.val);
  }
  __inline int8 operator%(int _mod)
  {
    return int8(u.val % (int8(_mod)).u.val);
  }

  // and
  __inline int8& operator&(uYMM _and);
  __inline int8 operator&(int8 _and)
  {
    return int8(u.val & _and.u.val);
  }
  __inline int8 operator&(int _and)
  {
    return int8(u.val & (int8(_and)).u.val);
  }

  // or
  __inline int8& operator|(uYMM _or);
  __inline int8 operator|(int8 _or)
  {
    return int8(u.val | _or.u.val);
  }
  __inline int8 operator|(int _or)
  {
    return int8(u.val | (int8(_or)).u.val);
  }

  // xor
  __inline int8& operator^(uYMM _xor);
  __inline int8 operator^(int8 _xor)
  {
    return int8(u.val ^ _xor.u.val);
  }
  __inline int8 operator^(int _xor)
  {
    return int8(u.val ^ (int8(_xor)).u.val);
  }

  // sll
  __inline int8& operator<<(uYMM _sll);
  __inline int8 operator<<(int8 _sll)
  {
    return int8(u.val << _sll.u.val);
  }
  __inline int8 operator<<(int _sll)
  {
    return int8(u.val << (int8(_sll)).u.val);
  }  

  // sra
  __inline int8& operator>>(uYMM _sra);
  __inline int8 operator>>(int8 _sra)
  {
    return int8(u.val >> _sra.u.val);
  }
  __inline int8 operator>>(int _sra)
  {
    return int8(u.val >> (int8(_sra)).u.val);
  }  

  // compare
  __inline mask operator<(int8  _lt);
  __inline mask operator<=(int8 _le);
  __inline mask operator>(int8  _gt);
  __inline mask operator>=(int8 _ge);
  __inline mask operator==(int8 _eq);
  __inline mask operator!=(int8 _ne);
  __inline mask operator<(uYMM  _lt);
  __inline mask operator<=(uYMM _le);
  __inline mask operator>(uYMM  _gt);
  __inline mask operator>=(uYMM _ge);
  __inline mask operator==(uYMM _eq);
  __inline mask operator!=(uYMM _ne);
};

struct uint8
{
  uint8()                    { u.val = 0; }
  uint8(uv8i32       assign) { u.val = assign; }
  uint8(unsigned int assign) { u.val = assign; }  
  union U {
    uv8i32       val;
    unsigned int elem[8];
  } u;

  // set
  __inline void set(int pos, unsigned int set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(uint8 dst, int pos, unsigned int set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(uint8 *dst, int pos, unsigned int set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline unsigned int get(int pos)
  {
    return u.elem[pos];
  }
  __inline static unsigned int get(uint8 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static unsigned int get(uint8 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float8  _assign);
  __inline void operator=(int8    _assign);
  __inline void operator=(long4   _assign);
  __inline void operator=(double4 _assign);
  __inline void operator=(ulong4  _assign);

  // add
  __inline uint8& operator+(uYMM _add);
  __inline uint8 operator+(uint8 _add)
  {
    return uint8(u.val + _add.u.val);
  }
  __inline uint8 operator+(unsigned int _add)
  {
    return uint8(u.val + (uint8(_add)).u.val);
  }
 
  // sub
  __inline uint8& operator-(uYMM _sub);  
  __inline uint8 operator-(uint8 _sub)
  {
    return uint8(u.val - _sub.u.val);
  }
  __inline uint8 operator-(unsigned int _sub)
  {
    return uint8(u.val - (uint8(_sub)).u.val);
  }

  // multiply
  __inline uint8& operator*(uYMM _mul);
  __inline uint8 operator*(uint8 _mul)
  {
    return uint8(u.val * _mul.u.val);
  }
  __inline uint8 operator*(unsigned int _mul)
  {
    return uint8(u.val * (uint8(_mul)).u.val);
  }

  // divide
  __inline uint8& operator/(uYMM _div);
  __inline uint8 operator/(uint8 _div)
  {
    return uint8(u.val / _div.u.val);
  }
  __inline uint8 operator/(unsigned int _div)
  {
    return uint8(u.val / (uint8(_div)).u.val);
  }

  // modulo (not SIMD)
  __inline uint8& operator%(uYMM _mod);  
  __inline uint8 operator%(uint8 _mod)
  {
    return uint8(u.val % _mod.u.val);
  }
  __inline uint8 operator%(unsigned int _mod)
  {
    return uint8(u.val % (uint8(_mod)).u.val);
  }

  // and
  __inline uint8& operator&(uYMM _and);  
  __inline uint8 operator&(uint8 _and)
  {
    return uint8(u.val & _and.u.val);
  }
  __inline uint8 operator&(unsigned int _and)
  {
    return uint8(u.val & (uint8(_and)).u.val);
  }

  // or
  __inline uint8& operator|(uYMM _or);  
  __inline uint8 operator|(uint8 _or)
  {
    return uint8(u.val | _or.u.val);
  }
  __inline uint8 operator|(unsigned int _or)
  {
    return uint8(u.val | (uint8(_or)).u.val);
  }

  // xor
  __inline uint8& operator^(uYMM _xor);
  __inline uint8 operator^(uint8 _xor)
  {
    return uint8(u.val ^ _xor.u.val);
  }
  __inline uint8 operator^(unsigned int _xor)
  {
    return uint8(u.val ^ (uint8(_xor)).u.val);
  }

  // sll
  __inline uint8& operator<<(uYMM _sll);  
  __inline uint8 operator<<(uint8 _sll)
  {
    return uint8(u.val << _sll.u.val);
  }
  __inline uint8 operator<<(unsigned int _sll)
  {
    return uint8(u.val << (uint8(_sll)).u.val);
  }  

  // srl
  __inline uint8& operator>>(uYMM _srl);
  __inline uint8 operator>>(uint8 _srl)
  {
    return uint8(u.val >> _srl.u.val);
  }
  __inline uint8 operator>>(unsigned int _srl)
  {
    return uint8(u.val >> (uint8(_srl)).u.val);
  }  

  // compare
  __inline mask operator<(uint8  _lt);
  __inline mask operator<=(uint8 _le);
  __inline mask operator>(uint8  _gt);
  __inline mask operator>=(uint8 _ge);
  __inline mask operator==(uint8 _eq);
  __inline mask operator!=(uint8 _ne);
  __inline mask operator<(uYMM  _lt);
  __inline mask operator<=(uYMM _le);
  __inline mask operator>(uYMM  _gt);
  __inline mask operator>=(uYMM _ge);
  __inline mask operator==(uYMM _eq);
  __inline mask operator!=(uYMM _ne);  
};

struct long4
{
  long4()             { u.val = 0; }
  long4(v4i64 assign) { u.val = assign; }
  long4(long  assign) { u.val = assign; }  
  union U {
    v4i64 val;
    long  elem[4];
  } u;

  // set
  __inline void set(int pos, long set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(long4 dst, int pos, long set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(long4 *dst, int pos, long set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline long get(int pos)
  {
    return u.elem[pos];
  }
  __inline static long get(long4 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static long get(long4 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float8  _assign);
  __inline void operator=(int8    _assign);
  __inline void operator=(uint8   _assign);
  __inline void operator=(double4 _assign);
  __inline void operator=(ulong4  _assign);

  // add  
  __inline long4& operator+(uYMM _add);
  __inline long4 operator+(long4 _add)
  {
    return long4(u.val + _add.u.val);
  }
  __inline long4 operator+(long _add)
  {
    return long4(u.val + (long4(_add)).u.val);
  }
 
  // sub
  __inline long4& operator-(uYMM _sub);
  __inline long4 operator-(long4 _sub)
  {
    return long4(u.val - _sub.u.val);
  }
  __inline long4 operator-(long _sub)
  {
    return long4(u.val - (long4(_sub)).u.val);
  }

  // multiply
  __inline long4& operator*(uYMM _mul);
  __inline long4 operator*(long4 _mul)
  {
    return long4(u.val * _mul.u.val);
  }
  __inline long4 operator*(long _mul)
  {
    return long4(u.val * (long4(_mul)).u.val);
  }

  // divide
  __inline long4& operator/(uYMM _div);
  __inline long4 operator/(long4 _div)
  {
    return long4(u.val / _div.u.val);
  }
  __inline long4 operator/(long _div)
  {
    return long4(u.val / (long4(_div)).u.val);
  }

  // modulo (not SIMD)
  __inline long4& operator%(uYMM _mod);
  __inline long4 operator%(long4 _mod)
  {
    return long4(u.val % _mod.u.val);
  }
  __inline long4 operator%(long _mod)
  {
    return long4(u.val % (long4(_mod)).u.val);
  }

  // and
  __inline long4& operator&(uYMM _and);
  __inline long4 operator&(long4 _and)
  {
    return long4(u.val & _and.u.val);
  }
  __inline long4 operator&(long _and)
  {
    return long4(u.val & (long4(_and)).u.val);
  }

  // or
  __inline long4& operator|(uYMM _or);
  __inline long4 operator|(long4 _or)
  {
    return long4(u.val | _or.u.val);
  }
  __inline long4 operator|(long _or)
  {
    return long4(u.val | (long4(_or)).u.val);
  }

  // xor
  __inline long4& operator^(uYMM _xor);
  __inline long4 operator^(long4 _xor)
  {
    return long4(u.val ^ _xor.u.val);
  }
  __inline long4 operator^(long _xor)
  {
    return long4(u.val ^ (long4(_xor)).u.val);
  }

  // sll
  __inline long4& operator<<(uYMM _sll);
  __inline long4 operator<<(long4 _sll)
  {
    return long4(u.val << _sll.u.val);
  }
  __inline long4 operator<<(long _sll)
  {
    return long4(u.val << (long4(_sll)).u.val);
  }  

  // sra
  __inline long4& operator>>(uYMM _sra);
  __inline long4 operator>>(long4 _sra)
  {
    return long4(u.val >> _sra.u.val);
  }
  __inline long4 operator>>(long _sra)
  {
    return long4(u.val >> (long4(_sra)).u.val);
  }  

  // compare
  __inline mask operator<(long4  _lt);
  __inline mask operator<=(long4 _le);
  __inline mask operator>(long4  _gt);
  __inline mask operator>=(long4 _ge);
  __inline mask operator==(long4 _eq);
  __inline mask operator!=(long4 _ne);
  __inline mask operator<(uYMM  _lt);
  __inline mask operator<=(uYMM _le);
  __inline mask operator>(uYMM  _gt);
  __inline mask operator>=(uYMM _ge);
  __inline mask operator==(uYMM _eq);
  __inline mask operator!=(uYMM _ne);  
};

struct ulong4
{
  ulong4()                     { u.val = 0; }
  ulong4(uv4i64        assign) { u.val = assign; }
  ulong4(unsigned long assign) { u.val = assign; }  
  union U {
    uv4i64        val;
    unsigned long elem[4];
  } u;

  // set
  __inline void set(int pos, unsigned long set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(ulong4 dst, int pos, unsigned long set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(ulong4 *dst, int pos, unsigned long set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline unsigned long get(int pos)
  {
    return u.elem[pos];
  }
  __inline static unsigned long get(ulong4 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static unsigned long get(ulong4 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float8  _assign);
  __inline void operator=(int8    _assign);
  __inline void operator=(uint8   _assign);
  __inline void operator=(long4   _assign);
  __inline void operator=(double4 _assign);

  // add
  __inline ulong4& operator+(uYMM _add);
  __inline ulong4 operator+(ulong4 _add)
  {
    return ulong4(u.val + _add.u.val);
  }
  __inline ulong4 operator+(unsigned long _add)
  {
    return ulong4(u.val + (ulong4(_add)).u.val);
  }
 
  // sub
  __inline ulong4& operator-(uYMM _sub);  
  __inline ulong4 operator-(ulong4 _sub)
  {
    return ulong4(u.val - _sub.u.val);
  }
  __inline ulong4 operator-(unsigned long _sub)
  {
    return ulong4(u.val - (ulong4(_sub)).u.val);
  }

  // multiply
  __inline ulong4& operator*(uYMM _mul);
  __inline ulong4 operator*(ulong4 _mul)
  {
    return ulong4(u.val * _mul.u.val);
  }
  __inline ulong4 operator*(unsigned long _mul)
  {
    return ulong4(u.val * (ulong4(_mul)).u.val);
  }

  // divide
  __inline ulong4& operator/(uYMM _div);
  __inline ulong4 operator/(ulong4 _div)
  {
    return ulong4(u.val / _div.u.val);
  }
  __inline ulong4 operator/(unsigned long _div)
  {
    return ulong4(u.val / (ulong4(_div)).u.val);
  }

  // modulo (not SIMD)
  __inline ulong4& operator%(uYMM _mod);  
  __inline ulong4 operator%(ulong4 _mod)
  {
    return ulong4(u.val % _mod.u.val);
  }
  __inline ulong4 operator%(unsigned long _mod)
  {
    return ulong4(u.val % (ulong4(_mod)).u.val);
  }

  // and
  __inline ulong4& operator&(uYMM _and);  
  __inline ulong4 operator&(ulong4 _and)
  {
    return ulong4(u.val & _and.u.val);
  }
  __inline ulong4 operator&(unsigned long _and)
  {
    return ulong4(u.val & (ulong4(_and)).u.val);
  }

  // or
  __inline ulong4& operator|(uYMM _or);  
  __inline ulong4 operator|(ulong4 _or)
  {
    return ulong4(u.val | _or.u.val);
  }
  __inline ulong4 operator|(unsigned long _or)
  {
    return ulong4(u.val | (ulong4(_or)).u.val);
  }

  // xor
  __inline ulong4& operator^(uYMM _xor);
  __inline ulong4 operator^(ulong4 _xor)
  {
    return ulong4(u.val ^ _xor.u.val);
  }
  __inline ulong4 operator^(unsigned long _xor)
  {
    return ulong4(u.val ^ (ulong4(_xor)).u.val);
  }

  // sll
  __inline ulong4& operator<<(uYMM _sll);  
  __inline ulong4 operator<<(ulong4 _sll)
  {
    return ulong4(u.val << _sll.u.val);
  }
  __inline ulong4 operator<<(unsigned long _sll)
  {
    return ulong4(u.val << (ulong4(_sll)).u.val);
  }  

  // srl
  __inline ulong4& operator>>(uYMM _srl);
  __inline ulong4 operator>>(ulong4 _srl)
  {
    return ulong4(u.val >> _srl.u.val);
  }
  __inline ulong4 operator>>(unsigned long _srl)
  {
    return ulong4(u.val >> (ulong4(_srl)).u.val);
  }  

  // compare
  __inline mask operator<(ulong4  _lt);
  __inline mask operator<=(ulong4 _le);
  __inline mask operator>(ulong4  _gt);
  __inline mask operator>=(ulong4 _ge);
  __inline mask operator==(ulong4 _eq);
  __inline mask operator!=(ulong4 _ne);
  __inline mask operator<(uYMM  _lt);
  __inline mask operator<=(uYMM _le);
  __inline mask operator>(uYMM  _gt);
  __inline mask operator>=(uYMM _ge);
  __inline mask operator==(uYMM _eq);
  __inline mask operator!=(uYMM _ne);  
};

struct float8
{
  float8()             { u.val = 0.0f; }
  float8(v8f32 assign) { u.val = assign; }
  float8(float assign) { u.val = assign; }  
  union U {
    v8f32 val;
    float elem[8];
  } u;

  // set
  __inline void set(int pos, float set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(float8 dst, int pos, float set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(float8 *dst, int pos, float set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline float get(int pos)
  {
    return u.elem[pos];
  }
  __inline static float get(float8 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static float get(float8 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(int8    _assign);
  __inline void operator=(uint8   _assign);
  __inline void operator=(long4   _assign);
  __inline void operator=(double4 _assign);
  __inline void operator=(ulong4  _assign);

  // add
  __inline float8& operator+(uYMM _add);
  __inline float8 operator+(float8 _add)
  {
    return float8(u.val + _add.u.val);
  }
  __inline float8 operator+(float _add)
  {
    return float8(u.val + (float8(_add)).u.val);
  }
 
  // sub
  __inline float8& operator-(uYMM _sub);  
  __inline float8 operator-(float8 _sub)
  {
    return float8(u.val - _sub.u.val);
  }
  __inline float8 operator-(float _sub)
  {
    return float8(u.val - (float8(_sub)).u.val);
  }

  // multiply
  __inline float8& operator*(uYMM _mul);
  __inline float8 operator*(float8 _mul)
  {
    return float8(u.val * _mul.u.val);
  }
  __inline float8 operator*(float _mul)
  {
    return float8(u.val * (float8(_mul)).u.val);
  }

  // divide
  __inline float8& operator/(uYMM _div); 
  __inline float8 operator/(float8 _div)
  {
    return float8(u.val / _div.u.val);
  }
  __inline float8 operator/(float _div)
  {
    return float8(u.val / (float8(_div)).u.val);
  }

  // sqrt
  __inline float8 sqrt(void)
  {
    return float8(__builtin_ia32_sqrtps256(u.val));
  }

  // rsqrt
  __inline float8 rsqrt(void)
  {
    return float8(__builtin_ia32_rsqrtps256(u.val));
  }

  // rcp
  __inline float8 rcp(void)
  {
    return float8(__builtin_ia32_rcpps256(u.val));
  }

  // div with rcp
  __inline float8 rcp_div(float8 _rcp_div)
  {
    float8 rcp       = float8(__builtin_ia32_rcpps256(_rcp_div.u.val));
    float8 minus_one = float8(-1.0f);
    float8 tmp       = minus_one.fma_as_add(rcp, _rcp_div);
    tmp              = tmp.fma_as_mul(rcp, rcp);
    return float8(u.val * tmp.u.val);
  }

  // fma3
  __inline float8 fma_as_mul(float8 _src_mul, float8 _src_add)
  {
    return float8(u.val * _src_mul.u.val + _src_add.u.val);
  }
  __inline float8 fma_as_add(float8 _src_mul1, float8 _src_mul2)
  {
    return float8(_src_mul1.u.val * _src_mul2.u.val + u.val);
  }

  // max (should rename?)
   __inline float8 max(float8 _max)
  {
    return float8(__builtin_ia32_maxps256(u.val, _max.u.val));
  }
  // max
  __inline static float8 max(float8 _max1, float8 _max2)
  {
    return float8(__builtin_ia32_maxps256(_max1.u.val, _max2.u.val));
  }
  // min (should rename?)
  __inline float8 min(float8 _min)
  {
    return float8(__builtin_ia32_minps256(u.val, _min.u.val));
  }
  // min
  __inline static float8 min(float8 _min1, float8 _min2)
  {
    return float8(__builtin_ia32_minps256(_min1.u.val, _min2.u.val));
  }

  // compare
  __inline mask operator<(float8  _lt);
  __inline mask operator<=(float8 _le);
  __inline mask operator>(float8  _gt);
  __inline mask operator>=(float8 _ge);
  __inline mask operator==(float8 _eq);
  __inline mask operator!=(float8 _ne);
  __inline mask operator<(uYMM  _lt);
  __inline mask operator<=(uYMM _le);
  __inline mask operator>(uYMM  _gt);
  __inline mask operator>=(uYMM _ge);
  __inline mask operator==(uYMM _eq);
  __inline mask operator!=(uYMM _ne);  

  __inline float8 operator&(int8 _and)
  {
    return float8(reinterpret_cast<v8f32>((reinterpret_cast<v8i32>(u.val) & _and.u.val)));
  }
  __inline float8 operator|(float8 _or)
  {
    return float8(reinterpret_cast<v8f32>(reinterpret_cast<v8i32>(u.val) | reinterpret_cast<v8i32>(_or.u.val)));
  }
};

struct double4
{
  double4()              { u.val = 0.0; }
  double4(v4f64  assign) { u.val = assign; }
  double4(double assign) { u.val = assign; }  
  union U {
    v4f64  val;
    double elem[4];
  } u;

  // set
  __inline void set(int pos, double set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(double4 dst, int pos, double set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(double4 *dst, int pos, double set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline double get(int pos)
  {
    return u.elem[pos];
  }
  __inline static double get(double4 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static double get(double4 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float8  _assign);
  __inline void operator=(int8    _assign);
  __inline void operator=(uint8   _assign);
  __inline void operator=(long4   _assign);
  __inline void operator=(ulong4  _assign);

  // add
  __inline double4& operator+(uYMM _add);
  __inline double4 operator+(double4 _add)
  {
    return double4(u.val + _add.u.val);
  }
  __inline double4 operator+(double _add)
  {
    return double4(u.val + (double4(_add)).u.val);
  }
 
  // sub
  __inline double4& operator-(uYMM _sub);  
  __inline double4 operator-(double4 _sub)
  {
    return double4(u.val - _sub.u.val);
  }
  __inline double4 operator-(double _sub)
  {
    return double4(u.val - (double4(_sub)).u.val);
  }

  // multiply
  __inline double4& operator*(uYMM _mul);
  __inline double4 operator*(double4 _mul)
  {
    return double4(u.val * _mul.u.val);
  }
  __inline double4 operator*(double _mul)
  {
    return double4(u.val * (double4(_mul)).u.val);
  }

  // divide
  __inline double4& operator/(uYMM _div); 
  __inline double4 operator/(double4 _div)
  {
    return double4(u.val / _div.u.val);
  }
  __inline double4 operator/(double _div)
  {
    return double4(u.val / (double4(_div)).u.val);
  }

  // sqrt
  __inline double4 sqrt(void)
  {
    return double4(__builtin_ia32_sqrtpd256(u.val));
  }
  
  // fma3
  __inline double4 fma_as_mul(double4 _src_mul, double4 _src_add)
  {
    return double4(u.val * _src_mul.u.val + _src_add.u.val);
  }
  __inline double4 fma_as_add(double4 _src_mul1, double4 _src_mul2)
  {
    return double4(_src_mul1.u.val * _src_mul2.u.val + u.val);
  }

  // max (should rename?)
  __inline double4 max(double4 _max)
  {
    return double4(__builtin_ia32_maxpd256(u.val, _max.u.val));
  }
  // max
  __inline static double4 max(double4 _max1, double4 _max2)
  {
    return double4(__builtin_ia32_maxpd256(_max1.u.val, _max2.u.val));
  }
  // min (should rename?)
  __inline double4 min(double4 _min)
  {
    return double4(__builtin_ia32_minpd256(u.val, _min.u.val));
  }
  // min
  __inline static double4 min(double4 _min1, double4 _min2)
  {
    return double4(__builtin_ia32_minpd256(_min1.u.val, _min2.u.val));
  }

  // compare
  __inline mask operator<(double4  _lt);
  __inline mask operator<=(double4 _le);
  __inline mask operator>(double4  _gt);
  __inline mask operator>=(double4 _ge);
  __inline mask operator==(double4 _eq);
  __inline mask operator!=(double4 _ne);
  __inline mask operator<(uYMM  _lt);
  __inline mask operator<=(uYMM _le);
  __inline mask operator>(uYMM  _gt);
  __inline mask operator>=(uYMM _ge);
  __inline mask operator==(uYMM _eq);
  __inline mask operator!=(uYMM _ne);  
};

struct mask {
  mask() {}
  mask(maskl4 m) { mr.ml4 = m; }
  mask(maskd4 m) { mr.md4 = m; }  
  mask(maski8 m) { mr.mi8 = m; }
  mask(maskf8 m) { mr.mf8 = m; }    
  union maskReg {
    maskl4 ml4; // mask v4i64
    maskd4 md4; // mask v4f64  
    maski8 mi8; // mask v8i32
    maskf8 mf8; // mask v8f32    
  } mr;

  // predicate patterns
  __inline float8 _add(float8 _add1, float8 _add2)
  {
    float8 tmp = _add1 + _add2;
    return (tmp & mr.mi8) | (_add1 & (~mr.mi8));
  }
  __inline float8 _mul(float8 _mul1, float8 _mul2)
  {
    float8 tmp = _mul1 * _mul2;
    return (tmp & mr.mi8) | (_mul1 & (~mr.mi8));
  }
  __inline float8 _div(float8 _div1, float8 _div2)
  {
    float8 tmp = _div1 / _div2;
    return (tmp & mr.mi8) | (_div1 & (~mr.mi8));
  }
  __inline float8 _sub(float8 _sub1, float8 _sub2)
  {
    float8 tmp = _sub1 - _sub2;
    return (tmp & mr.mi8) | (_sub1 & (~mr.mi8));
  }

  __inline int8 _add(int8 _add1, int8 _add2)
  {
    int8 tmp = _add1 + _add2;
    return (tmp & mr.mi8) | (_add1 & (~mr.mi8));
  }
  __inline int8 _mul(int8 _mul1, int8 _mul2)
  {
    int8 tmp = _mul1 * _mul2;
    return (tmp & mr.mi8) | (_mul1 & (~mr.mi8));
  }
  __inline int8 _div(int8 _div1, int8 _div2)
  {
    int8 tmp = _div1 / _div2;
    return (tmp & mr.mi8) | (_div1 & (~mr.mi8));
  }
  __inline int8 _sub(int8 _sub1, int8 _sub2)
  {
    int8 tmp = _sub1 - _sub2;
    return (tmp & mr.mi8) | (_sub1 & (~mr.mi8));
  }
  __inline int8 _sll(int8 _sll1, int8 _sll2)
  {
    int8 tmp = _sll1 << _sll2;
    return (tmp & mr.mi8) | (_sll1 & (~mr.mi8));
  }
  __inline int8 _sra(int8 _sra1, int8 _sra2)
  {
    int8 tmp = _sra1 << _sra2;
    return (tmp & mr.mi8) | (_sra1 & (~mr.mi8));
  }

  __inline long4 _add(long4 _add1, long4 _add2)
  {
    long4 tmp = _add1 + _add2;
    return (tmp & mr.ml4) | (_add1 & (~mr.ml4));
  }
  __inline long4 _mul(long4 _mul1, long4 _mul2)
  {
    long4 tmp = _mul1 * _mul2;
    return (tmp & mr.ml4) | (_mul1 & (~mr.ml4));
  }
  __inline long4 _div(long4 _div1, long4 _div2)
  {
    long4 tmp = _div1 / _div2;
    return (tmp & mr.ml4) | (_div1 & (~mr.ml4));
  }
  __inline long4 _sub(long4 _sub1, long4 _sub2)
  {
    long4 tmp = _sub1 - _sub2;
    return (tmp & mr.ml4) | (_sub1 & (~mr.ml4));
  }
  __inline long4 _sll(long4 _sll1, long4 _sll2)
  {
    long4 tmp = _sll1 << _sll2;
    return (tmp & mr.ml4) | (_sll1 & (~mr.ml4));
  }
  __inline long4 _sra(long4 _sra1, long4 _sra2)
  {
    long4 tmp = _sra1 << _sra2;
    return (tmp & mr.ml4) | (_sra1 & (~mr.ml4));
  }
};

// int8
mask int8::operator<(int8 _lt) {
  return mask((maski8)(u.val < _lt.u.val));
}
mask int8::operator<=(int8 _le) {
  return mask((maski8)(u.val <= _le.u.val));
}
mask int8::operator>(int8 _gt) {
  return mask((maski8)(u.val > _gt.u.val));
}
mask int8::operator>=(int8 _ge) {
  return mask((maski8)(u.val >= _ge.u.val));
}
mask int8::operator==(int8 _eq) {
  return mask((maski8)(u.val == _eq.u.val));
}
mask int8::operator!=(int8 _ne) {
  return mask((maski8)(u.val != _ne.u.val));
}
// uint8
mask uint8::operator<(uint8 _lt) {
  return mask((maski8)(u.val < _lt.u.val));
}
mask uint8::operator<=(uint8 _le) {
  return mask((maski8)(u.val <= _le.u.val));
}
mask uint8::operator>(uint8 _gt) {
  return mask((maski8)(u.val > _gt.u.val));
}
mask uint8::operator>=(uint8 _ge) {
  return mask((maski8)(u.val >= _ge.u.val));
}
mask uint8::operator==(uint8 _eq) {
  return mask((maski8)(u.val == _eq.u.val));
}
mask uint8::operator!=(uint8 _ne) {
  return mask((maski8)(u.val != _ne.u.val));
}
// long4
mask long4::operator<(long4 _lt) {
  return mask((maskl4)(u.val < _lt.u.val));
}
mask long4::operator<=(long4 _le) {
  return mask((maskl4)(u.val <= _le.u.val));
}
mask long4::operator>(long4 _gt) {
  return mask((maskl4)(u.val > _gt.u.val));
}
mask long4::operator>=(long4 _ge) {
  return mask((maskl4)(u.val >= _ge.u.val));
}
mask long4::operator==(long4 _eq) {
  return mask((maskl4)(u.val == _eq.u.val));
}
mask long4::operator!=(long4 _ne) {
  return mask((maskl4)(u.val != _ne.u.val));
}
// ulong4
mask ulong4::operator<(ulong4 _lt) {
  return mask((maskl4)(u.val < _lt.u.val));
}
mask ulong4::operator<=(ulong4 _le) {
  return mask((maskl4)(u.val <= _le.u.val));
}
mask ulong4::operator>(ulong4 _gt) {
  return mask((maskl4)(u.val > _gt.u.val));
}
mask ulong4::operator>=(ulong4 _ge) {
  return mask((maskl4)(u.val >= _ge.u.val));
}
mask ulong4::operator==(ulong4 _eq) {
  return mask((maskl4)(u.val == _eq.u.val));
}
mask ulong4::operator!=(ulong4 _ne) {
  return mask((maskl4)(u.val != _ne.u.val));
}
// float8
mask float8::operator<(float8 _lt) {
  return mask((maskf8)(u.val < _lt.u.val));
}
mask float8::operator<=(float8 _le) {
  return mask((maskf8)(u.val <= _le.u.val));
}
mask float8::operator>(float8 _gt) {
  return mask((maskf8)(u.val > _gt.u.val));
}
mask float8::operator>=(float8 _ge) {
  return mask((maskf8)(u.val >= _ge.u.val));
}
mask float8::operator==(float8 _eq) {
  return mask((maskf8)(u.val == _eq.u.val));
}
mask float8::operator!=(float8 _ne) {
  return mask((maskf8)(u.val != _ne.u.val));
}
// double4
mask double4::operator<(double4 _lt) {
  return mask((maskd4)(u.val < _lt.u.val));
}
mask double4::operator<=(double4 _le) {
  return mask((maskd4)(u.val <= _le.u.val));
}
mask double4::operator>(double4 _gt) {
  return mask((maskd4)(u.val > _gt.u.val));
}
mask double4::operator>=(double4 _ge) {
  return mask((maskd4)(u.val >= _ge.u.val));
}
mask double4::operator==(double4 _eq) {
  return mask((maskd4)(u.val == _eq.u.val));
}
mask double4::operator!=(double4 _ne) {
  return mask((maskd4)(u.val != _ne.u.val));
}

//////////////////////
//// ymm register ////
//////////////////////
union uYMM {
  uYMM() : i() {}
  int8     i;
  uint8   ui;
  long4    l;
  ulong4  ul;    
  float8   f;
  double4  d;

  __inline void operator=(double4 _assign);
  __inline void operator=(float8  _assign);
  __inline void operator=(int8    _assign);
  __inline void operator=(uint8   _assign);
  __inline void operator=(long4   _assign);
  __inline void operator=(ulong4  _assign);
};

using ymm   = uYMM;
using ymmf  = float8;
using ymmd  = double4;
using ymmi  = int8;
using ymmui = uint8;
using ymml  = long4;
using ymmul = ulong4;

////////////////////////////////
//// signed int8 operations ////
////////////////////////////////
int8& int8::operator+(uYMM _add) {
  u.val = u.val + _add.i.u.val;
  return *this;
}
int8& int8::operator-(uYMM _sub) {
  u.val = u.val - _sub.i.u.val;
  return *this;
}
int8& int8::operator*(uYMM _mul) {
  u.val = u.val * _mul.i.u.val;
  return *this;
}
int8& int8::operator/(uYMM _div) {
  u.val = u.val / _div.i.u.val;
  return *this;
}
int8& int8::operator%(uYMM _mod) {
  u.val = u.val % _mod.i.u.val;
  return *this;
}
int8& int8::operator&(uYMM _and) {
  u.val = u.val & _and.i.u.val;
  return *this;
}
int8& int8::operator|(uYMM _or) {
  u.val = u.val | _or.i.u.val;
  return *this;
}
int8& int8::operator^(uYMM _xor) {
  u.val = u.val ^ _xor.i.u.val;
  return *this;
}
int8& int8::operator<<(uYMM _sll) {
  u.val = u.val << _sll.i.u.val;
  return *this;
}
int8& int8::operator>>(uYMM _sra) {
  u.val = u.val >> _sra.i.u.val;
  return *this;
}
//////////////////////////////////
//// unsigned int8 operations ////
//////////////////////////////////
uint8& uint8::operator+(uYMM _add) {
  u.val = u.val + _add.ui.u.val;
  return *this;
}
uint8& uint8::operator-(uYMM _sub) {
  u.val = u.val - _sub.ui.u.val;
  return *this;
}
uint8& uint8::operator*(uYMM _mul) {
  u.val = u.val * _mul.ui.u.val;
  return *this;
}
uint8& uint8::operator/(uYMM _div) {
  u.val = u.val / _div.ui.u.val;
  return *this;
}
uint8& uint8::operator%(uYMM _mod) {
  u.val = u.val % _mod.ui.u.val;
  return *this;
}
uint8& uint8::operator&(uYMM _and) {
  u.val = u.val & _and.ui.u.val;
  return *this;
}
uint8& uint8::operator|(uYMM _or) {
  u.val = u.val | _or.ui.u.val;
  return *this;
}
uint8& uint8::operator^(uYMM _xor) {
  u.val = u.val ^ _xor.ui.u.val;
  return *this;
}
uint8& uint8::operator<<(uYMM _sll) {
  u.val = u.val << _sll.ui.u.val;
  return *this;
}
uint8& uint8::operator>>(uYMM _srl) {
  u.val = u.val >> _srl.ui.u.val;
  return *this;
}
/////////////////////////////////
//// signed long4 operations ////
/////////////////////////////////
long4& long4::operator+(uYMM _add) {
  u.val = u.val + _add.l.u.val;
  return *this;
}
long4& long4::operator-(uYMM _sub) {
  u.val = u.val - _sub.l.u.val;
  return *this;
}
long4& long4::operator*(uYMM _mul) {
  u.val = u.val * _mul.l.u.val;
  return *this;
}
long4& long4::operator/(uYMM _div) {
  u.val = u.val / _div.l.u.val;
  return *this;
}
long4& long4::operator%(uYMM _mod) {
  u.val = u.val % _mod.l.u.val;
  return *this;
}
long4& long4::operator&(uYMM _and) {
  u.val = u.val & _and.l.u.val;
  return *this;
}
long4& long4::operator|(uYMM _or) {
  u.val = u.val | _or.l.u.val;
  return *this;
}
long4& long4::operator^(uYMM _xor) {
  u.val = u.val ^ _xor.l.u.val;
  return *this;
}
long4& long4::operator<<(uYMM _sll) {
  u.val = u.val << _sll.l.u.val;
  return *this;
}
long4& long4::operator>>(uYMM _sra) {
  u.val = u.val >> _sra.l.u.val;
  return *this;
}
//////////////////////////////////
//// unsigned long4 operations ////
//////////////////////////////////
ulong4& ulong4::operator+(uYMM _add) {
  u.val = u.val + _add.ul.u.val;
  return *this;
}
ulong4& ulong4::operator-(uYMM _sub) {
  u.val = u.val - _sub.ul.u.val;
  return *this;
}
ulong4& ulong4::operator*(uYMM _mul) {
  u.val = u.val * _mul.ul.u.val;
  return *this;
}
ulong4& ulong4::operator/(uYMM _div) {
  u.val = u.val / _div.ul.u.val;
  return *this;
}
ulong4& ulong4::operator%(uYMM _mod) {
  u.val = u.val % _mod.ul.u.val;
  return *this;
}
ulong4& ulong4::operator&(uYMM _and) {
  u.val = u.val & _and.ul.u.val;
  return *this;
}
ulong4& ulong4::operator|(uYMM _or) {
  u.val = u.val | _or.ul.u.val;
  return *this;
}
ulong4& ulong4::operator^(uYMM _xor) {
  u.val = u.val ^ _xor.ul.u.val;
  return *this;
}
ulong4& ulong4::operator<<(uYMM _sll) {
  u.val = u.val << _sll.ul.u.val;
  return *this;
}
ulong4& ulong4::operator>>(uYMM _srl) {
  u.val = u.val >> _srl.ul.u.val;
  return *this;
}
///////////////////////////
//// float8 operations ////
///////////////////////////
float8& float8::operator+(uYMM _add) {
  u.val = u.val + _add.f.u.val;
  return *this;
}
float8& float8::operator-(uYMM _sub) {
  u.val = u.val - _sub.f.u.val;
  return *this;
}
float8& float8::operator*(uYMM _mul) {
  u.val = u.val * _mul.f.u.val;
  return *this;
}
float8& float8::operator/(uYMM _div) {
  u.val = u.val / _div.f.u.val;
  return *this;
}
////////////////////////////
//// double4 operations ////
////////////////////////////
double4& double4::operator+(uYMM _add) {
  u.val = u.val + _add.d.u.val;
  return *this;
}
double4& double4::operator-(uYMM _sub) {
  u.val = u.val - _sub.d.u.val;
  return *this;
}
double4& double4::operator*(uYMM _mul) {
  u.val = u.val * _mul.d.u.val;
  return *this;
}
double4& double4::operator/(uYMM _div) {
  u.val = u.val / _div.d.u.val;
  return *this;
}

///////////////////////////////
//// assignment operations ////
///////////////////////////////
void float8::operator=(double4 _assign) {
  u.val = reinterpret_cast<v8f32>(_assign.u.val); 
}
void float8::operator=(int8 _assign) {
  u.val = reinterpret_cast<v8f32>(_assign.u.val); 
}
void float8::operator=(uint8 _assign) {
  u.val = reinterpret_cast<v8f32>(_assign.u.val); 
}
void float8::operator=(long4 _assign) {
  u.val = reinterpret_cast<v8f32>(_assign.u.val); 
}
void float8::operator=(ulong4 _assign) {
  u.val = reinterpret_cast<v8f32>(_assign.u.val); 
}

void double4::operator=(float8 _assign) {
  u.val = reinterpret_cast<v4f64>(_assign.u.val); 
}
void double4::operator=(int8 _assign) {
  u.val = reinterpret_cast<v4f64>(_assign.u.val); 
}
void double4::operator=(uint8 _assign) {
  u.val = reinterpret_cast<v4f64>(_assign.u.val); 
}
void double4::operator=(long4 _assign) {
  u.val = reinterpret_cast<v4f64>(_assign.u.val); 
}
void double4::operator=(ulong4 _assign) {
  u.val = reinterpret_cast<v4f64>(_assign.u.val); 
}

void ulong4::operator=(float8 _assign) {
  u.val = reinterpret_cast<uv4i64>(_assign.u.val); 
}
void ulong4::operator=(int8 _assign) {
  u.val = reinterpret_cast<uv4i64>(_assign.u.val); 
}
void ulong4::operator=(uint8 _assign) {
  u.val = reinterpret_cast<uv4i64>(_assign.u.val);
}
void ulong4::operator=(long4 _assign) {
  u.val = reinterpret_cast<uv4i64>(_assign.u.val); 
}
void ulong4::operator=(double4 _assign) {
  u.val = reinterpret_cast<uv4i64>(_assign.u.val); 
}

void long4::operator=(float8 _assign) {
  u.val = reinterpret_cast<v4i64>(_assign.u.val); 
}
void long4::operator=(int8 _assign) {
  u.val = reinterpret_cast<v4i64>(_assign.u.val); 
}
void long4::operator=(uint8 _assign) {
  u.val = reinterpret_cast<v4i64>(_assign.u.val); 
}
void long4::operator=(ulong4 _assign) {
  u.val = reinterpret_cast<v4i64>(_assign.u.val); 
}
void long4::operator=(double4 _assign) {
  u.val = reinterpret_cast<v4i64>(_assign.u.val); 
}

void int8::operator=(float8 _assign) {
  u.val = reinterpret_cast<v8i32>(_assign.u.val); 
}
void int8::operator=(ulong4 _assign) {
  u.val = reinterpret_cast<v8i32>(_assign.u.val); 
}
void int8::operator=(uint8 _assign) {
  u.val = reinterpret_cast<v8i32>(_assign.u.val); 
}
void int8::operator=(long4 _assign) {
  u.val = reinterpret_cast<v8i32>(_assign.u.val); 
}
void int8::operator=(double4 _assign) {
  u.val = reinterpret_cast<v8i32>(_assign.u.val);
}

void uint8::operator=(float8 _assign) {
  u.val = reinterpret_cast<uv8i32>(_assign.u.val); 
}
void uint8::operator=(ulong4 _assign) {
  u.val = reinterpret_cast<uv8i32>(_assign.u.val); 
}
void uint8::operator=(int8 _assign) {
  u.val = reinterpret_cast<uv8i32>(_assign.u.val); 
}
void uint8::operator=(long4 _assign) {
  u.val = reinterpret_cast<uv8i32>(_assign.u.val); 
}
void uint8::operator=(double4 _assign) {
  u.val = reinterpret_cast<uv8i32>(_assign.u.val); 
}

void uYMM::operator=(float8 _assign) {
  f = _assign; 
}
void uYMM::operator=(ulong4 _assign) {
  ul = _assign;
}
void uYMM::operator=(int8 _assign) {
  i = _assign;
}
void uYMM::operator=(uint8 _assign) {
  ui = _assign;
}
void uYMM::operator=(long4 _assign) {
  ul = _assign;
}
void uYMM::operator=(double4 _assign) {
  d = _assign;
}

////////////////////////////
//// compare operations ////
////////////////////////////
mask int8::operator<(uYMM _lt) {
  return mask((maski8)(u.val < _lt.i.u.val));
}
mask int8::operator<=(uYMM _le) {
  return mask((maski8)(u.val <= _le.i.u.val));
}
mask int8::operator>(uYMM _gt) {
  return mask((maski8)(u.val > _gt.i.u.val));
}
mask int8::operator>=(uYMM _ge) {
  return mask((maski8)(u.val >= _ge.i.u.val));
}
mask int8::operator==(uYMM _eq) {
  return mask((maski8)(u.val == _eq.i.u.val));
}
mask int8::operator!=(uYMM _ne) {
  return mask((maski8)(u.val != _ne.i.u.val));
}
mask uint8::operator<(uYMM _lt) {
  return mask((maski8)(u.val < _lt.i.u.val));
}
mask uint8::operator<=(uYMM _le) {
  return mask((maski8)(u.val <= _le.i.u.val));
}
mask uint8::operator>(uYMM _gt) {
  return mask((maski8)(u.val > _gt.i.u.val));
}
mask uint8::operator>=(uYMM _ge) {
  return mask((maski8)(u.val >= _ge.i.u.val));
}
mask uint8::operator==(uYMM _eq) {
  return mask((maski8)(u.val == _eq.i.u.val));
}
mask uint8::operator!=(uYMM _ne) {
  return mask((maski8)(u.val != _ne.i.u.val));
}
mask long4::operator<(uYMM _lt) {
  return mask((maskl4)(u.val < _lt.l.u.val));
}
mask long4::operator<=(uYMM _le) {
  return mask((maskl4)(u.val <= _le.l.u.val));
}
mask long4::operator>(uYMM _gt) {
  return mask((maskl4)(u.val > _gt.l.u.val));
}
mask long4::operator>=(uYMM _ge) {
  return mask((maskl4)(u.val >= _ge.l.u.val));
}
mask long4::operator==(uYMM _eq) {
  return mask((maskl4)(u.val == _eq.l.u.val));
}
mask long4::operator!=(uYMM _ne) {
  return mask((maskl4)(u.val != _ne.l.u.val));
}
mask ulong4::operator<(uYMM _lt) {
  return mask((maskl4)(u.val < _lt.ul.u.val));
}
mask ulong4::operator<=(uYMM _le) {
  return mask((maskl4)(u.val <= _le.ul.u.val));
}
mask ulong4::operator>(uYMM _gt) {
  return mask((maskl4)(u.val > _gt.ul.u.val));
}
mask ulong4::operator>=(uYMM _ge) {
  return mask((maskl4)(u.val >= _ge.ul.u.val));
}
mask ulong4::operator==(uYMM _eq) {
  return mask((maskl4)(u.val == _eq.ul.u.val));
}
mask ulong4::operator!=(uYMM _ne) {
  return mask((maskl4)(u.val != _ne.ul.u.val));
}
mask float8::operator<(uYMM _lt) {
  return mask((maskf8)(u.val < _lt.f.u.val));
}
mask float8::operator<=(uYMM _le) {
  return mask((maskf8)(u.val <= _le.f.u.val));
}
mask float8::operator>(uYMM _gt) {
  return mask((maskf8)(u.val > _gt.f.u.val));
}
mask float8::operator>=(uYMM _ge) {
  return mask((maskf8)(u.val >= _ge.f.u.val));
}
mask float8::operator==(uYMM _eq) {
  return mask((maskf8)(u.val == _eq.f.u.val));
}
mask float8::operator!=(uYMM _ne) {
  return mask((maskf8)(u.val != _ne.f.u.val));
}
mask double4::operator<(uYMM _lt) {
  return mask((maskd4)(u.val < _lt.d.u.val));
}
mask double4::operator<=(uYMM _le) {
  return mask((maskd4)(u.val <= _le.d.u.val));
}
mask double4::operator>(uYMM _gt) {
  return mask((maskd4)(u.val > _gt.d.u.val));
}
mask double4::operator>=(uYMM _ge) {
  return mask((maskd4)(u.val >= _ge.d.u.val));
}
mask double4::operator==(uYMM _eq) {
  return mask((maskd4)(u.val == _eq.d.u.val));
}
mask double4::operator!=(uYMM _ne) {
  return mask((maskd4)(u.val != _ne.d.u.val));
}

#endif
