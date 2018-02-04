#ifndef _AVX2_SVVM_H_
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

  // put
  __inline static void put(int8 dst, int pos, int put)
  {
    dst.u.elem[pos] = put;
  }
  __inline static void put(int8 *dst, int pos, int put)
  {
    dst->u.elem[pos] = put;
  }
  
  // get
  __inline static int get(int8 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static int get(int8 *src, int pos)
  {
    return src->u.elem[pos];
  } 

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

  // modulo
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

  // put
  __inline static void put(uint8 dst, int pos, unsigned int put)
  {
    dst.u.elem[pos] = put;
  }
  __inline static void put(uint8 *dst, int pos, unsigned int put)
  {
    dst->u.elem[pos] = put;
  }
  
  // get
  __inline static unsigned int get(uint8 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static unsigned int get(uint8 *src, int pos)
  {
    return src->u.elem[pos];
  } 

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

  // modulo
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

  // put
  __inline static void put(long4 dst, int pos, long put)
  {
    dst.u.elem[pos] = put;
  }
  __inline static void put(long4 *dst, int pos, long put)
  {
    dst->u.elem[pos] = put;
  }
  
  // get
  __inline static long get(long4 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static long get(long4 *src, int pos)
  {
    return src->u.elem[pos];
  } 

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

  // modulo
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

  // put
  __inline static void put(ulong4 dst, int pos, unsigned long put)
  {
    dst.u.elem[pos] = put;
  }
  __inline static void put(ulong4 *dst, int pos, unsigned long put)
  {
    dst->u.elem[pos] = put;
  }
  
  // get
  __inline static unsigned long get(ulong4 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static unsigned long get(ulong4 *src, int pos)
  {
    return src->u.elem[pos];
  } 

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

  // modulo
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

  // put
  __inline static void put(float8 dst, int pos, float put)
  {
    dst.u.elem[pos] = put;
  }
  __inline static void put(float8 *dst, int pos, float put)
  {
    dst->u.elem[pos] = put;
  }
  
  // get
  __inline static float get(float8 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static float get(float8 *src, int pos)
  {
    return src->u.elem[pos];
  } 

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
  __inline static float8 sqrt(float8 _sqrt)
  {
    return float8(__builtin_ia32_sqrtps256(_sqrt.u.val));
  }

  // rsqrt
  __inline static float8 rsqrt(float8 _rsqrt)
  {
    return float8(__builtin_ia32_rsqrtps256(_rsqrt.u.val));
  }

  // rcp
  __inline static float8 rcp(float8 _rcp)
  {
    return float8(__builtin_ia32_rcpps256(_rcp.u.val));
  }

  // div with rcp
  __inline float8 rcp_div(float8 _rcp_div)
  {
    float8 rcp = float8(__builtin_ia32_rcpps256(_rcp_div.u.val));
    float8 one = float8(1.0f);
    float8 tmp = rcp * _rcp_div;
    tmp = tmp - one;
    tmp = tmp * rcp;
    tmp = tmp + rcp;
    return float8(u.val * tmp.u.val);
  }      

  // compare
  __inline mask operator<(float8  _lt);
  __inline mask operator<=(float8 _le);
  __inline mask operator>(float8  _gt);
  __inline mask operator>=(float8 _ge);
  __inline mask operator==(float8 _eq);
  __inline mask operator!=(float8 _ne);
};

struct double4
{
  double4()              { u.val = 0.0; }
  double4(v4f64 assign)  { u.val = assign; }
  double4(double assign) { u.val = assign; }  
  union U {
    v4f64 val;
    double elem[4];
  } u;

  // put
  __inline static void put(double4 dst, int pos, double put)
  {
    dst.u.elem[pos] = put;
  }
  __inline static void put(double4 *dst, int pos, double put)
  {
    dst->u.elem[pos] = put;
  }
  
  // get
  __inline static double get(double4 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static double get(double4 *src, int pos)
  {
    return src->u.elem[pos];
  } 

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
  __inline static double4 sqrt(double4 _sqrt)
  {
    return double4(__builtin_ia32_sqrtpd256(_sqrt.u.val));
  }

  // compare
  __inline mask operator<(double4  _lt);
  __inline mask operator<=(double4 _le);
  __inline mask operator>(double4  _gt);
  __inline mask operator>=(double4 _ge);
  __inline mask operator==(double4 _eq);
  __inline mask operator!=(double4 _ne);
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

  __inline int8 _add(int8 _add1, int8 _add2)
  {
    // TODO: implement predicate patterns
    return _add1 + _add2; // temporal
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
  u.val = u.val + _add.f.u.val;
  return *this;
}
double4& double4::operator-(uYMM _sub) {
  u.val = u.val - _sub.f.u.val;
  return *this;
}
double4& double4::operator*(uYMM _mul) {
  u.val = u.val * _mul.f.u.val;
  return *this;
}
double4& double4::operator/(uYMM _div) {
  u.val = u.val / _div.f.u.val;
  return *this;
}

#endif
