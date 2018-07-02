#ifndef _AVX_SVVM_H_
#define _AVX_SVVM_H_

typedef float                    v4f32 __attribute__((ext_vector_type(4)));
typedef int                      v4i32 __attribute__((ext_vector_type(4)));
typedef unsigned int            uv4i32 __attribute__((ext_vector_type(4)));
typedef long long int            v2i64 __attribute__((ext_vector_type(2)));
typedef unsigned long long int  uv2i64 __attribute__((ext_vector_type(2)));
typedef double                   v2f64 __attribute__((ext_vector_type(2)));

typedef int           maski4 __attribute__((ext_vector_type(4)));
typedef long long int maskl2 __attribute__((ext_vector_type(2)));
typedef float         maskf4 __attribute__((ext_vector_type(4)));
typedef double        maskd2 __attribute__((ext_vector_type(2)));

struct int4;
struct uint4;
struct float4;
struct long2;
struct ulong2;
struct double2;
struct mask;
union  uXMM;

struct int4
{
  int4()             { u.val = 0; }
  int4(v4i32 assign) { u.val = assign; }
  int4(int   assign) { u.val = assign; }  
  union U {
    v4i32 val;
    int   elem[4];
  } u;

  // set
  __inline void set(int pos, int set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(int4 dst, int pos, int set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(int4 *dst, int pos, int set)
  {
    dst->u.elem[pos] = set;
  }

  // get
  __inline int get(int pos)
  {
    return u.elem[pos];
  }
  __inline static int get(int4 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static int get(int4 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float4  _assign);
  __inline void operator=(uint4   _assign);
  __inline void operator=(long2   _assign);
  __inline void operator=(double2 _assign);
  __inline void operator=(ulong2  _assign);

  // add  
  __inline int4& operator+(uXMM _add);
  __inline int4 operator+(int4 _add)
  {
    return int4(u.val + _add.u.val);
  }
  __inline int4 operator+(int _add)
  {
    return int4(u.val + (int4(_add)).u.val);
  }
 
  // sub
  __inline int4& operator-(uXMM _sub);
  __inline int4 operator-(int4 _sub)
  {
    return int4(u.val - _sub.u.val);
  }
  __inline int4 operator-(int _sub)
  {
    return int4(u.val - (int4(_sub)).u.val);
  }

  // multiply
  __inline int4& operator*(uXMM _mul);
  __inline int4 operator*(int4 _mul)
  {
    return int4(u.val * _mul.u.val);
  }
  __inline int4 operator*(int _mul)
  {
    return int4(u.val * (int4(_mul)).u.val);
  }

  // divide
  __inline int4& operator/(uXMM _div);
  __inline int4 operator/(int4 _div)
  {
    return int4(u.val / _div.u.val);
  }
  __inline int4 operator/(int _div)
  {
    return int4(u.val / (int4(_div)).u.val);
  }

  // modulo (not SIMD)
  __inline int4& operator%(uXMM _mod);
  __inline int4 operator%(int4 _mod)
  {
    return int4(u.val % _mod.u.val);
  }
  __inline int4 operator%(int _mod)
  {
    return int4(u.val % (int4(_mod)).u.val);
  }

  // and
  __inline int4& operator&(uXMM _and);
  __inline int4 operator&(int4 _and)
  {
    return int4(u.val & _and.u.val);
  }
  __inline int4 operator&(int _and)
  {
    return int4(u.val & (int4(_and)).u.val);
  }

  // or
  __inline int4& operator|(uXMM _or);
  __inline int4 operator|(int4 _or)
  {
    return int4(u.val | _or.u.val);
  }
  __inline int4 operator|(int _or)
  {
    return int4(u.val | (int4(_or)).u.val);
  }

  // xor
  __inline int4& operator^(uXMM _xor);
  __inline int4 operator^(int4 _xor)
  {
    return int4(u.val ^ _xor.u.val);
  }
  __inline int4 operator^(int _xor)
  {
    return int4(u.val ^ (int4(_xor)).u.val);
  }

  // sll
  __inline int4& operator<<(uXMM _sll);
  __inline int4 operator<<(int4 _sll)
  {
    return int4(u.val << _sll.u.val);
  }
  __inline int4 operator<<(int _sll)
  {
    return int4(u.val << (int4(_sll)).u.val);
  }  

  // sra
  __inline int4& operator>>(uXMM _sra);
  __inline int4 operator>>(int4 _sra)
  {
    return int4(u.val >> _sra.u.val);
  }
  __inline int4 operator>>(int _sra)
  {
    return int4(u.val >> (int4(_sra)).u.val);
  }  

  // compare
  __inline mask operator<(int4  _lt);
  __inline mask operator<=(int4 _le);
  __inline mask operator>(int4  _gt);
  __inline mask operator>=(int4 _ge);
  __inline mask operator==(int4 _eq);
  __inline mask operator!=(int4 _ne);
};

struct uint4
{
  uint4()                    { u.val = 0; }
  uint4(uv4i32       assign) { u.val = assign; }
  uint4(unsigned int assign) { u.val = assign; }  
  union U {
    uv4i32       val;
    unsigned int elem[4];
  } u;

  // set
  __inline void set(int pos, unsigned int set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(uint4 dst, int pos, unsigned int set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(uint4 *dst, int pos, unsigned int set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline unsigned int get(int pos)
  {
    return u.elem[pos];
  }
  __inline static unsigned int get(uint4 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static unsigned int get(uint4 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float4  _assign);
  __inline void operator=(int4    _assign);
  __inline void operator=(long2   _assign);
  __inline void operator=(double2 _assign);
  __inline void operator=(ulong2  _assign);

  // add
  __inline uint4& operator+(uXMM _add);
  __inline uint4 operator+(uint4 _add)
  {
    return uint4(u.val + _add.u.val);
  }
  __inline uint4 operator+(unsigned int _add)
  {
    return uint4(u.val + (uint4(_add)).u.val);
  }
 
  // sub
  __inline uint4& operator-(uXMM _sub);  
  __inline uint4 operator-(uint4 _sub)
  {
    return uint4(u.val - _sub.u.val);
  }
  __inline uint4 operator-(unsigned int _sub)
  {
    return uint4(u.val - (uint4(_sub)).u.val);
  }

  // multiply
  __inline uint4& operator*(uXMM _mul);
  __inline uint4 operator*(uint4 _mul)
  {
    return uint4(u.val * _mul.u.val);
  }
  __inline uint4 operator*(unsigned int _mul)
  {
    return uint4(u.val * (uint4(_mul)).u.val);
  }

  // divide
  __inline uint4& operator/(uXMM _div);
  __inline uint4 operator/(uint4 _div)
  {
    return uint4(u.val / _div.u.val);
  }
  __inline uint4 operator/(unsigned int _div)
  {
    return uint4(u.val / (uint4(_div)).u.val);
  }

  // modulo (not SIMD)
  __inline uint4& operator%(uXMM _mod);  
  __inline uint4 operator%(uint4 _mod)
  {
    return uint4(u.val % _mod.u.val);
  }
  __inline uint4 operator%(unsigned int _mod)
  {
    return uint4(u.val % (uint4(_mod)).u.val);
  }

  // and
  __inline uint4& operator&(uXMM _and);  
  __inline uint4 operator&(uint4 _and)
  {
    return uint4(u.val & _and.u.val);
  }
  __inline uint4 operator&(unsigned int _and)
  {
    return uint4(u.val & (uint4(_and)).u.val);
  }

  // or
  __inline uint4& operator|(uXMM _or);  
  __inline uint4 operator|(uint4 _or)
  {
    return uint4(u.val | _or.u.val);
  }
  __inline uint4 operator|(unsigned int _or)
  {
    return uint4(u.val | (uint4(_or)).u.val);
  }

  // xor
  __inline uint4& operator^(uXMM _xor);
  __inline uint4 operator^(uint4 _xor)
  {
    return uint4(u.val ^ _xor.u.val);
  }
  __inline uint4 operator^(unsigned int _xor)
  {
    return uint4(u.val ^ (uint4(_xor)).u.val);
  }

  // sll
  __inline uint4& operator<<(uXMM _sll);  
  __inline uint4 operator<<(uint4 _sll)
  {
    return uint4(u.val << _sll.u.val);
  }
  __inline uint4 operator<<(unsigned int _sll)
  {
    return uint4(u.val << (uint4(_sll)).u.val);
  }  

  // srl
  __inline uint4& operator>>(uXMM _srl);
  __inline uint4 operator>>(uint4 _srl)
  {
    return uint4(u.val >> _srl.u.val);
  }
  __inline uint4 operator>>(unsigned int _srl)
  {
    return uint4(u.val >> (uint4(_srl)).u.val);
  }  

  // compare
  __inline mask operator<(uint4  _lt);
  __inline mask operator<=(uint4 _le);
  __inline mask operator>(uint4  _gt);
  __inline mask operator>=(uint4 _ge);
  __inline mask operator==(uint4 _eq);
  __inline mask operator!=(uint4 _ne);
};

struct long2
{
  long2()             { u.val = 0; }
  long2(v2i64 assign) { u.val = assign; }
  long2(long  assign) { u.val = assign; }  
  union U {
    v2i64 val;
    long  elem[2];
  } u;

  // set
  __inline void set(int pos, long set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(long2 dst, int pos, long set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(long2 *dst, int pos, long set)
  {
    dst->u.elem[pos] = set;
  }

  // get
  __inline long get(int pos)
  {
    return u.elem[pos];
  }
  __inline static long get(long2 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static long get(long2 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float4  _assign);
  __inline void operator=(int4    _assign);
  __inline void operator=(uint4   _assign);
  __inline void operator=(double2 _assign);
  __inline void operator=(ulong2  _assign);

  // add  
  __inline long2& operator+(uXMM _add);
  __inline long2 operator+(long2 _add)
  {
    return long2(u.val + _add.u.val);
  }
  __inline long2 operator+(long _add)
  {
    return long2(u.val + (long2(_add)).u.val);
  }
 
  // sub
  __inline long2& operator-(uXMM _sub);
  __inline long2 operator-(long2 _sub)
  {
    return long2(u.val - _sub.u.val);
  }
  __inline long2 operator-(long _sub)
  {
    return long2(u.val - (long2(_sub)).u.val);
  }

  // multiply
  __inline long2& operator*(uXMM _mul);
  __inline long2 operator*(long2 _mul)
  {
    return long2(u.val * _mul.u.val);
  }
  __inline long2 operator*(long _mul)
  {
    return long2(u.val * (long2(_mul)).u.val);
  }

  // divide
  __inline long2& operator/(uXMM _div);
  __inline long2 operator/(long2 _div)
  {
    return long2(u.val / _div.u.val);
  }
  __inline long2 operator/(long _div)
  {
    return long2(u.val / (long2(_div)).u.val);
  }

  // modulo (not SIMD)
  __inline long2& operator%(uXMM _mod);
  __inline long2 operator%(long2 _mod)
  {
    return long2(u.val % _mod.u.val);
  }
  __inline long2 operator%(long _mod)
  {
    return long2(u.val % (long2(_mod)).u.val);
  }

  // and
  __inline long2& operator&(uXMM _and);
  __inline long2 operator&(long2 _and)
  {
    return long2(u.val & _and.u.val);
  }
  __inline long2 operator&(long _and)
  {
    return long2(u.val & (long2(_and)).u.val);
  }

  // or
  __inline long2& operator|(uXMM _or);
  __inline long2 operator|(long2 _or)
  {
    return long2(u.val | _or.u.val);
  }
  __inline long2 operator|(long _or)
  {
    return long2(u.val | (long2(_or)).u.val);
  }

  // xor
  __inline long2& operator^(uXMM _xor);
  __inline long2 operator^(long2 _xor)
  {
    return long2(u.val ^ _xor.u.val);
  }
  __inline long2 operator^(long _xor)
  {
    return long2(u.val ^ (long2(_xor)).u.val);
  }

  // sll
  __inline long2& operator<<(uXMM _sll);
  __inline long2 operator<<(long2 _sll)
  {
    return long2(u.val << _sll.u.val);
  }
  __inline long2 operator<<(long _sll)
  {
    return long2(u.val << (long2(_sll)).u.val);
  }  

  // sra
  __inline long2& operator>>(uXMM _sra);
  __inline long2 operator>>(long2 _sra)
  {
    return long2(u.val >> _sra.u.val);
  }
  __inline long2 operator>>(long _sra)
  {
    return long2(u.val >> (long2(_sra)).u.val);
  }  

  // compare
  __inline mask operator<(long2  _lt);
  __inline mask operator<=(long2 _le);
  __inline mask operator>(long2  _gt);
  __inline mask operator>=(long2 _ge);
  __inline mask operator==(long2 _eq);
  __inline mask operator!=(long2 _ne);
};

struct ulong2
{
  ulong2()                     { u.val = 0; }
  ulong2(uv2i64        assign) { u.val = assign; }
  ulong2(unsigned long assign) { u.val = assign; }  
  union U {
    uv2i64        val;
    unsigned long elem[2];
  } u;

  // set
  __inline void set(int pos, unsigned long set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(ulong2 dst, int pos, unsigned long set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(ulong2 *dst, int pos, unsigned long set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline unsigned long get(int pos)
  {
    return u.elem[pos];
  }
  __inline static unsigned long get(ulong2 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static unsigned long get(ulong2 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(double2 _assign);
  __inline void operator=(int4    _assign);
  __inline void operator=(uint4   _assign);
  __inline void operator=(long2   _assign);
  __inline void operator=(float4  _assign);

  // add
  __inline ulong2& operator+(uXMM _add);
  __inline ulong2 operator+(ulong2 _add)
  {
    return ulong2(u.val + _add.u.val);
  }
  __inline ulong2 operator+(unsigned long _add)
  {
    return ulong2(u.val + (ulong2(_add)).u.val);
  }
 
  // sub
  __inline ulong2& operator-(uXMM _sub);  
  __inline ulong2 operator-(ulong2 _sub)
  {
    return ulong2(u.val - _sub.u.val);
  }
  __inline ulong2 operator-(unsigned long _sub)
  {
    return ulong2(u.val - (ulong2(_sub)).u.val);
  }

  // multiply
  __inline ulong2& operator*(uXMM _mul);
  __inline ulong2 operator*(ulong2 _mul)
  {
    return ulong2(u.val * _mul.u.val);
  }
  __inline ulong2 operator*(unsigned long _mul)
  {
    return ulong2(u.val * (ulong2(_mul)).u.val);
  }

  // divide
  __inline ulong2& operator/(uXMM _div);
  __inline ulong2 operator/(ulong2 _div)
  {
    return ulong2(u.val / _div.u.val);
  }
  __inline ulong2 operator/(unsigned long _div)
  {
    return ulong2(u.val / (ulong2(_div)).u.val);
  }

  // modulo (not SIMD)
  __inline ulong2& operator%(uXMM _mod);  
  __inline ulong2 operator%(ulong2 _mod)
  {
    return ulong2(u.val % _mod.u.val);
  }
  __inline ulong2 operator%(unsigned long _mod)
  {
    return ulong2(u.val % (ulong2(_mod)).u.val);
  }

  // and
  __inline ulong2& operator&(uXMM _and);  
  __inline ulong2 operator&(ulong2 _and)
  {
    return ulong2(u.val & _and.u.val);
  }
  __inline ulong2 operator&(unsigned long _and)
  {
    return ulong2(u.val & (ulong2(_and)).u.val);
  }

  // or
  __inline ulong2& operator|(uXMM _or);  
  __inline ulong2 operator|(ulong2 _or)
  {
    return ulong2(u.val | _or.u.val);
  }
  __inline ulong2 operator|(unsigned long _or)
  {
    return ulong2(u.val | (ulong2(_or)).u.val);
  }

  // xor
  __inline ulong2& operator^(uXMM _xor);
  __inline ulong2 operator^(ulong2 _xor)
  {
    return ulong2(u.val ^ _xor.u.val);
  }
  __inline ulong2 operator^(unsigned long _xor)
  {
    return ulong2(u.val ^ (ulong2(_xor)).u.val);
  }

  // sll
  __inline ulong2& operator<<(uXMM _sll);  
  __inline ulong2 operator<<(ulong2 _sll)
  {
    return ulong2(u.val << _sll.u.val);
  }
  __inline ulong2 operator<<(unsigned long _sll)
  {
    return ulong2(u.val << (ulong2(_sll)).u.val);
  }  

  // srl
  __inline ulong2& operator>>(uXMM _srl);
  __inline ulong2 operator>>(ulong2 _srl)
  {
    return ulong2(u.val >> _srl.u.val);
  }
  __inline ulong2 operator>>(unsigned long _srl)
  {
    return ulong2(u.val >> (ulong2(_srl)).u.val);
  }  

  // compare
  __inline mask operator<(ulong2  _lt);
  __inline mask operator<=(ulong2 _le);
  __inline mask operator>(ulong2  _gt);
  __inline mask operator>=(ulong2 _ge);
  __inline mask operator==(ulong2 _eq);
  __inline mask operator!=(ulong2 _ne);
};

struct float4
{
  float4()             { u.val = 0.0f; }
  float4(v4f32 assign) { u.val = assign; }
  float4(float assign) { u.val = assign; }  
  union U {
    v4f32 val;
    float elem[4];
  } u;

  // set
  __inline void set(int pos, float set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(float4 dst, int pos, float set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(float4 *dst, int pos, float set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline float get(int pos)
  {
    return u.elem[pos];
  }
  __inline static float get(float4 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static float get(float4 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(double2 _assign);
  __inline void operator=(int4    _assign);
  __inline void operator=(uint4   _assign);
  __inline void operator=(long2   _assign);
  __inline void operator=(ulong2  _assign);

  // add
  __inline float4& operator+(uXMM _add);
  __inline float4 operator+(float4 _add)
  {
    return float4(u.val + _add.u.val);
  }
  __inline float4 operator+(float _add)
  {
    return float4(u.val + (float4(_add)).u.val);
  }
 
  // sub
  __inline float4& operator-(uXMM _sub);  
  __inline float4 operator-(float4 _sub)
  {
    return float4(u.val - _sub.u.val);
  }
  __inline float4 operator-(float _sub)
  {
    return float4(u.val - (float4(_sub)).u.val);
  }

  // multiply
  __inline float4& operator*(uXMM _mul);
  __inline float4 operator*(float4 _mul)
  {
    return float4(u.val * _mul.u.val);
  }
  __inline float4 operator*(float _mul)
  {
    return float4(u.val * (float4(_mul)).u.val);
  }

  // divide
  __inline float4& operator/(uXMM _div); 
  __inline float4 operator/(float4 _div)
  {
    return float4(u.val / _div.u.val);
  }
  __inline float4 operator/(float _div)
  {
    return float4(u.val / (float4(_div)).u.val);
  }

  // sqrt
  __inline float4 sqrt(void)
  {
    return float4(__builtin_ia32_sqrtps(u.val));
  }

  // rsqrt
  __inline float4 rsqrt(void)
  {
    return float4(__builtin_ia32_rsqrtps(u.val));
  }

  // rcp
  __inline float4 rcp(void)
  {
    return float4(__builtin_ia32_rcpps(u.val));
  }

  // div with rcp
  __inline float4 rcp_div(float4 _rcp_div)
  {
    float4 rcp       = float4(__builtin_ia32_rcpps(_rcp_div.u.val));
    float4 minus_one = float4(-1.0f);
    float4 tmp       = minus_one.fma_as_add(rcp, _rcp_div);
    tmp              = tmp.fma_as_mul(rcp, rcp);
    return float4(u.val * tmp.u.val);
  }      

  // fma4 for AMD64
  __inline float4 fma_as_mul(float4 _src_mul, float4 _src_add)
  {
    return float4(u.val * _src_mul.u.val + _src_add.u.val);
  }
  __inline float4 fma_as_add(float4 _src_mul1, float4 _src_mul2)
  {
    return float4(_src_mul1.u.val * _src_mul2.u.val + u.val);
  }

  // max (should rename?)
  __inline float4 max(float4 _max)
  {
    return float4(__builtin_ia32_maxps(u.val, _max.u.val));
  }
  // max
  __inline static float4 max(float4 _max1, float4 _max2)
  {
    return float4(__builtin_ia32_maxps(_max1.u.val, _max2.u.val));
  }
  // min (should rename?)
  __inline float4 min(float4 _min)
  {
    return float4(__builtin_ia32_minps(u.val, _min.u.val));
  }
  // min
  __inline static float4 min(float4 _min1, float4 _min2)
  {
    return float4(__builtin_ia32_minps(_min1.u.val, _min2.u.val));
  }
  
  // compare
  __inline mask operator<(float4  _lt);
  __inline mask operator<=(float4 _le);
  __inline mask operator>(float4  _gt);
  __inline mask operator>=(float4 _ge);
  __inline mask operator==(float4 _eq);
  __inline mask operator!=(float4 _ne);

  __inline float4 operator&(int4 _and)
  {
    return float4(reinterpret_cast<v4f32>((reinterpret_cast<v4i32>(u.val) & _and.u.val)));
  }
  __inline float4 operator|(float4 _or)
  {
    return float4(reinterpret_cast<v4f32>(reinterpret_cast<v4i32>(u.val) | reinterpret_cast<v4i32>(_or.u.val)));
  }
};

struct double2
{
  double2()              { u.val = 0.0; }
  double2(v2f64  assign) { u.val = assign; }
  double2(double assign) { u.val = assign; }  
  union U {
    v2f64  val;
    double elem[2];
  } u;

  // set
  __inline void set(int pos, double set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(double2 dst, int pos, double set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(double2 *dst, int pos, double set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline double get(int pos)
  {
    return u.elem[pos];
  }
  __inline static double get(double2 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static double get(double2 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float4 _assign);
  __inline void operator=(int4   _assign);
  __inline void operator=(uint4  _assign);
  __inline void operator=(long2  _assign);
  __inline void operator=(ulong2 _assign);

  // add
  __inline double2& operator+(uXMM _add);
  __inline double2 operator+(double2 _add)
  {
    return double2(u.val + _add.u.val);
  }
  __inline double2 operator+(double _add)
  {
    return double2(u.val + (double2(_add)).u.val);
  }
 
  // sub
  __inline double2& operator-(uXMM _sub);  
  __inline double2 operator-(double2 _sub)
  {
    return double2(u.val - _sub.u.val);
  }
  __inline double2 operator-(double _sub)
  {
    return double2(u.val - (double2(_sub)).u.val);
  }

  // multiply
  __inline double2& operator*(uXMM _mul);
  __inline double2 operator*(double2 _mul)
  {
    return double2(u.val * _mul.u.val);
  }
  __inline double2 operator*(double _mul)
  {
    return double2(u.val * (double2(_mul)).u.val);
  }

  // divide
  __inline double2& operator/(uXMM _div); 
  __inline double2 operator/(double2 _div)
  {
    return double2(u.val / _div.u.val);
  }
  __inline double2 operator/(double _div)
  {
    return double2(u.val / (double2(_div)).u.val);
  }

  // sqrt
  __inline double2 sqrt(void)
  {
    return double2(__builtin_ia32_sqrtpd(u.val));
  }

  // fma4 for AMD64
  __inline double2 fma_as_mul(double2 _src_mul, double2 _src_add)
  {
    return double2(u.val * _src_mul.u.val + _src_add.u.val);
  }
  __inline double2 fma_as_add(double2 _src_mul1, double2 _src_mul2)
  {
    return double2(_src_mul1.u.val * _src_mul2.u.val + u.val);
  }

  // max (should rename?)
  __inline double2 max(double2 _max)
  {
    return double2(__builtin_ia32_maxpd(u.val, _max.u.val));
  }
  // max
  __inline static double2 max(double2 _max1, double2 _max2)
  {
    return double2(__builtin_ia32_maxpd(_max1.u.val, _max2.u.val));
  }
  // min (should rename?)
  __inline double2 min(double2 _min)
  {
    return double2(__builtin_ia32_minpd(u.val, _min.u.val));
  }
  // min
  __inline static double2 min(double2 _min1, double2 _min2)
  {
    return double2(__builtin_ia32_minpd(_min1.u.val, _min2.u.val));
  }
  
  // compare
  __inline mask operator<(double2  _lt);
  __inline mask operator<=(double2 _le);
  __inline mask operator>(double2  _gt);
  __inline mask operator>=(double2 _ge);
  __inline mask operator==(double2 _eq);
  __inline mask operator!=(double2 _ne);

  __inline double2 operator&(long2 _and)
  {
    return double2(reinterpret_cast<v2f64>((reinterpret_cast<v2i64>(u.val) & _and.u.val)));
  }
  __inline double2 operator|(double2 _or)
  {
    return double2(reinterpret_cast<v2f64>(reinterpret_cast<v2i64>(u.val) | reinterpret_cast<v2i64>(_or.u.val)));
  }
};

struct mask {
  mask() {}
  mask(maskl2 m) { mr.ml2 = m; }
  mask(maskd2 m) { mr.md2 = m; }  
  mask(maski4 m) { mr.mi4 = m; }
  mask(maskf4 m) { mr.mf4 = m; }    
  union maskReg {
    maskl2 ml2; // mask v2i64
    maskd2 md2; // mask v2f64  
    maski4 mi4; // mask v4i32
    maskf4 mf4; // mask v4f32    
  } mr;

  // predicate patterns
  __inline float4 _add(float4 _add1, float4 _add2)
  {
    float4 tmp = _add1 + _add2;
    return (tmp & mr.mi4) | (_add1 & (~mr.mi4));
  }
  __inline float4 _mul(float4 _mul1, float4 _mul2)
  {
    float4 tmp = _mul1 * _mul2;
    return (tmp & mr.mi4) | (_mul1 & (~mr.mi4));
  }
  __inline float4 _div(float4 _div1, float4 _div2)
  {
    float4 tmp = _div1 / _div2;
    return (tmp & mr.mi4) | (_div1 & (~mr.mi4));
  }
  __inline float4 _sub(float4 _sub1, float4 _sub2)
  {
    float4 tmp = _sub1 - _sub2;
    return (tmp & mr.mi4) | (_sub1 & (~mr.mi4));
  }

  __inline double2 _add(double2 _add1, double2 _add2)
  {
    double2 tmp = _add1 + _add2;
    return (tmp & mr.ml2) | (_add1 & (~mr.ml2));
  }
  __inline double2 _mul(double2 _mul1, double2 _mul2)
  {
    double2 tmp = _mul1 * _mul2;
    return (tmp & mr.ml2) | (_mul1 & (~mr.ml2));
  }
  __inline double2 _div(double2 _div1, double2 _div2)
  {
    double2 tmp = _div1 / _div2;
    return (tmp & mr.ml2) | (_div1 & (~mr.ml2));
  }
  __inline double2 _sub(double2 _sub1, double2 _sub2)
  {
    double2 tmp = _sub1 - _sub2;
    return (tmp & mr.ml2) | (_sub1 & (~mr.ml2));
  }

  __inline int4 _add(int4 _add1, int4 _add2)
  {
    int4 tmp = _add1 + _add2;
    return (tmp & mr.mi4) | (_add1 & (~mr.mi4));
  }
  __inline int4 _mul(int4 _mul1, int4 _mul2)
  {
    int4 tmp = _mul1 * _mul2;
    return (tmp & mr.mi4) | (_mul1 & (~mr.mi4));
  }
  __inline int4 _div(int4 _div1, int4 _div2)
  {
    int4 tmp = _div1 / _div2;
    return (tmp & mr.mi4) | (_div1 & (~mr.mi4));
  }
  __inline int4 _sub(int4 _sub1, int4 _sub2)
  {
    int4 tmp = _sub1 - _sub2;
    return (tmp & mr.mi4) | (_sub1 & (~mr.mi4));
  }
  __inline int4 _sll(int4 _sll1, int4 _sll2)
  {
    int4 tmp = _sll1 << _sll2;
    return (tmp & mr.mi4) | (_sll1 & (~mr.mi4));
  }
  __inline int4 _sra(int4 _sra1, int4 _sra2)
  {
    int4 tmp = _sra1 << _sra2;
    return (tmp & mr.mi4) | (_sra1 & (~mr.mi4));
  }

  __inline long2 _add(long2 _add1, long2 _add2)
  {
    long2 tmp = _add1 + _add2;
    return (tmp & mr.ml2) | (_add1 & (~mr.ml2));
  }
  __inline long2 _mul(long2 _mul1, long2 _mul2)
  {
    long2 tmp = _mul1 * _mul2;
    return (tmp & mr.ml2) | (_mul1 & (~mr.ml2));
  }
  __inline long2 _div(long2 _div1, long2 _div2)
  {
    long2 tmp = _div1 / _div2;
    return (tmp & mr.ml2) | (_div1 & (~mr.ml2));
  }
  __inline long2 _sub(long2 _sub1, long2 _sub2)
  {
    long2 tmp = _sub1 - _sub2;
    return (tmp & mr.ml2) | (_sub1 & (~mr.ml2));
  }
  __inline long2 _sll(long2 _sll1, long2 _sll2)
  {
    long2 tmp = _sll1 << _sll2;
    return (tmp & mr.ml2) | (_sll1 & (~mr.ml2));
  }
  __inline long2 _sra(long2 _sra1, long2 _sra2)
  {
    long2 tmp = _sra1 << _sra2;
    return (tmp & mr.ml2) | (_sra1 & (~mr.ml2));
  }
};

// int4
mask int4::operator<(int4 _lt) {
  return mask((maski4)(u.val < _lt.u.val));
}
mask int4::operator<=(int4 _le) {
  return mask((maski4)(u.val <= _le.u.val));
}
mask int4::operator>(int4 _gt) {
  return mask((maski4)(u.val > _gt.u.val));
}
mask int4::operator>=(int4 _ge) {
  return mask((maski4)(u.val >= _ge.u.val));
}
mask int4::operator==(int4 _eq) {
  return mask((maski4)(u.val == _eq.u.val));
}
mask int4::operator!=(int4 _ne) {
  return mask((maski4)(u.val != _ne.u.val));
}
// uint4
mask uint4::operator<(uint4 _lt) {
  return mask((maski4)(u.val < _lt.u.val));
}
mask uint4::operator<=(uint4 _le) {
  return mask((maski4)(u.val <= _le.u.val));
}
mask uint4::operator>(uint4 _gt) {
  return mask((maski4)(u.val > _gt.u.val));
}
mask uint4::operator>=(uint4 _ge) {
  return mask((maski4)(u.val >= _ge.u.val));
}
mask uint4::operator==(uint4 _eq) {
  return mask((maski4)(u.val == _eq.u.val));
}
mask uint4::operator!=(uint4 _ne) {
  return mask((maski4)(u.val != _ne.u.val));
}
// long2
mask long2::operator<(long2 _lt) {
  return mask((maskl2)(u.val < _lt.u.val));
}
mask long2::operator<=(long2 _le) {
  return mask((maskl2)(u.val <= _le.u.val));
}
mask long2::operator>(long2 _gt) {
  return mask((maskl2)(u.val > _gt.u.val));
}
mask long2::operator>=(long2 _ge) {
  return mask((maskl2)(u.val >= _ge.u.val));
}
mask long2::operator==(long2 _eq) {
  return mask((maskl2)(u.val == _eq.u.val));
}
mask long2::operator!=(long2 _ne) {
  return mask((maskl2)(u.val != _ne.u.val));
}
// ulong2
mask ulong2::operator<(ulong2 _lt) {
  return mask((maskl2)(u.val < _lt.u.val));
}
mask ulong2::operator<=(ulong2 _le) {
  return mask((maskl2)(u.val <= _le.u.val));
}
mask ulong2::operator>(ulong2 _gt) {
  return mask((maskl2)(u.val > _gt.u.val));
}
mask ulong2::operator>=(ulong2 _ge) {
  return mask((maskl2)(u.val >= _ge.u.val));
}
mask ulong2::operator==(ulong2 _eq) {
  return mask((maskl2)(u.val == _eq.u.val));
}
mask ulong2::operator!=(ulong2 _ne) {
  return mask((maskl2)(u.val != _ne.u.val));
}
// float4
mask float4::operator<(float4 _lt) {
  return mask((maskf4)(u.val < _lt.u.val));
}
mask float4::operator<=(float4 _le) {
  return mask((maskf4)(u.val <= _le.u.val));
}
mask float4::operator>(float4 _gt) {
  return mask((maskf4)(u.val > _gt.u.val));
}
mask float4::operator>=(float4 _ge) {
  return mask((maskf4)(u.val >= _ge.u.val));
}
mask float4::operator==(float4 _eq) {
  return mask((maskf4)(u.val == _eq.u.val));
}
mask float4::operator!=(float4 _ne) {
  return mask((maskf4)(u.val != _ne.u.val));
}
// double2
mask double2::operator<(double2 _lt) {
  return mask((maskd2)(u.val < _lt.u.val));
}
mask double2::operator<=(double2 _le) {
  return mask((maskd2)(u.val <= _le.u.val));
}
mask double2::operator>(double2 _gt) {
  return mask((maskd2)(u.val > _gt.u.val));
}
mask double2::operator>=(double2 _ge) {
  return mask((maskd2)(u.val >= _ge.u.val));
}
mask double2::operator==(double2 _eq) {
  return mask((maskd2)(u.val == _eq.u.val));
}
mask double2::operator!=(double2 _ne) {
  return mask((maskd2)(u.val != _ne.u.val));
}

//////////////////////
//// xmm register ////
//////////////////////
union uXMM {
  uXMM() : i() {}
  int4     i;
  uint4   ui;
  long2    l;
  ulong2  ul;    
  float4   f;
  double2  d;

  __inline void operator=(double2 _assign);
  __inline void operator=(float4  _assign);
  __inline void operator=(int4    _assign);
  __inline void operator=(uint4   _assign);
  __inline void operator=(long2   _assign);
  __inline void operator=(ulong2  _assign);
};

using xmm   = uXMM;
using xmmf  = float4;
using xmmd  = double2;
using xmmi  = int4;
using xmmui = uint4;
using xmml  = long2;
using xmmul = ulong2;

////////////////////////////////
//// signed int4 operations ////
////////////////////////////////
int4& int4::operator+(uXMM _add) {
  u.val = u.val + _add.i.u.val;
  return *this;
}
int4& int4::operator-(uXMM _sub) {
  u.val = u.val - _sub.i.u.val;
  return *this;
}
int4& int4::operator*(uXMM _mul) {
  u.val = u.val * _mul.i.u.val;
  return *this;
}
int4& int4::operator/(uXMM _div) {
  u.val = u.val / _div.i.u.val;
  return *this;
}
int4& int4::operator%(uXMM _mod) {
  u.val = u.val % _mod.i.u.val;
  return *this;
}
int4& int4::operator&(uXMM _and) {
  u.val = u.val & _and.i.u.val;
  return *this;
}
int4& int4::operator|(uXMM _or) {
  u.val = u.val | _or.i.u.val;
  return *this;
}
int4& int4::operator^(uXMM _xor) {
  u.val = u.val ^ _xor.i.u.val;
  return *this;
}
int4& int4::operator<<(uXMM _sll) {
  u.val = u.val << _sll.i.u.val;
  return *this;
}
int4& int4::operator>>(uXMM _sra) {
  u.val = u.val >> _sra.i.u.val;
  return *this;
}
//////////////////////////////////
//// unsigned int4 operations ////
//////////////////////////////////
uint4& uint4::operator+(uXMM _add) {
  u.val = u.val + _add.ui.u.val;
  return *this;
}
uint4& uint4::operator-(uXMM _sub) {
  u.val = u.val - _sub.ui.u.val;
  return *this;
}
uint4& uint4::operator*(uXMM _mul) {
  u.val = u.val * _mul.ui.u.val;
  return *this;
}
uint4& uint4::operator/(uXMM _div) {
  u.val = u.val / _div.ui.u.val;
  return *this;
}
uint4& uint4::operator%(uXMM _mod) {
  u.val = u.val % _mod.ui.u.val;
  return *this;
}
uint4& uint4::operator&(uXMM _and) {
  u.val = u.val & _and.ui.u.val;
  return *this;
}
uint4& uint4::operator|(uXMM _or) {
  u.val = u.val | _or.ui.u.val;
  return *this;
}
uint4& uint4::operator^(uXMM _xor) {
  u.val = u.val ^ _xor.ui.u.val;
  return *this;
}
uint4& uint4::operator<<(uXMM _sll) {
  u.val = u.val << _sll.ui.u.val;
  return *this;
}
uint4& uint4::operator>>(uXMM _srl) {
  u.val = u.val >> _srl.ui.u.val;
  return *this;
}
/////////////////////////////////
//// signed long2 operations ////
/////////////////////////////////
long2& long2::operator+(uXMM _add) {
  u.val = u.val + _add.l.u.val;
  return *this;
}
long2& long2::operator-(uXMM _sub) {
  u.val = u.val - _sub.l.u.val;
  return *this;
}
long2& long2::operator*(uXMM _mul) {
  u.val = u.val * _mul.l.u.val;
  return *this;
}
long2& long2::operator/(uXMM _div) {
  u.val = u.val / _div.l.u.val;
  return *this;
}
long2& long2::operator%(uXMM _mod) {
  u.val = u.val % _mod.l.u.val;
  return *this;
}
long2& long2::operator&(uXMM _and) {
  u.val = u.val & _and.l.u.val;
  return *this;
}
long2& long2::operator|(uXMM _or) {
  u.val = u.val | _or.l.u.val;
  return *this;
}
long2& long2::operator^(uXMM _xor) {
  u.val = u.val ^ _xor.l.u.val;
  return *this;
}
long2& long2::operator<<(uXMM _sll) {
  u.val = u.val << _sll.l.u.val;
  return *this;
}
long2& long2::operator>>(uXMM _sra) {
  u.val = u.val >> _sra.l.u.val;
  return *this;
}
//////////////////////////////////
//// unsigned long2 operations ////
//////////////////////////////////
ulong2& ulong2::operator+(uXMM _add) {
  u.val = u.val + _add.ul.u.val;
  return *this;
}
ulong2& ulong2::operator-(uXMM _sub) {
  u.val = u.val - _sub.ul.u.val;
  return *this;
}
ulong2& ulong2::operator*(uXMM _mul) {
  u.val = u.val * _mul.ul.u.val;
  return *this;
}
ulong2& ulong2::operator/(uXMM _div) {
  u.val = u.val / _div.ul.u.val;
  return *this;
}
ulong2& ulong2::operator%(uXMM _mod) {
  u.val = u.val % _mod.ul.u.val;
  return *this;
}
ulong2& ulong2::operator&(uXMM _and) {
  u.val = u.val & _and.ul.u.val;
  return *this;
}
ulong2& ulong2::operator|(uXMM _or) {
  u.val = u.val | _or.ul.u.val;
  return *this;
}
ulong2& ulong2::operator^(uXMM _xor) {
  u.val = u.val ^ _xor.ul.u.val;
  return *this;
}
ulong2& ulong2::operator<<(uXMM _sll) {
  u.val = u.val << _sll.ul.u.val;
  return *this;
}
ulong2& ulong2::operator>>(uXMM _srl) {
  u.val = u.val >> _srl.ul.u.val;
  return *this;
}
///////////////////////////
//// float4 operations ////
///////////////////////////
float4& float4::operator+(uXMM _add) {
  u.val = u.val + _add.f.u.val;
  return *this;
}
float4& float4::operator-(uXMM _sub) {
  u.val = u.val - _sub.f.u.val;
  return *this;
}
float4& float4::operator*(uXMM _mul) {
  u.val = u.val * _mul.f.u.val;
  return *this;
}
float4& float4::operator/(uXMM _div) {
  u.val = u.val / _div.f.u.val;
  return *this;
}
////////////////////////////
//// double2 operations ////
////////////////////////////
double2& double2::operator+(uXMM _add) {
  u.val = u.val + _add.d.u.val;
  return *this;
}
double2& double2::operator-(uXMM _sub) {
  u.val = u.val - _sub.d.u.val;
  return *this;
}
double2& double2::operator*(uXMM _mul) {
  u.val = u.val * _mul.d.u.val;
  return *this;
}
double2& double2::operator/(uXMM _div) {
  u.val = u.val / _div.d.u.val;
  return *this;
}

///////////////////////////////
//// assignment operations ////
///////////////////////////////
void float4::operator=(double2 _assign) {
  u.val = reinterpret_cast<v4f32>(_assign.u.val); 
}
void float4::operator=(int4 _assign) {
  u.val = reinterpret_cast<v4f32>(_assign.u.val); 
}
void float4::operator=(uint4 _assign) {
  u.val = reinterpret_cast<v4f32>(_assign.u.val); 
}
void float4::operator=(long2 _assign) {
  u.val = reinterpret_cast<v4f32>(_assign.u.val); 
}
void float4::operator=(ulong2 _assign) {
  u.val = reinterpret_cast<v4f32>(_assign.u.val); 
}

void double2::operator=(float4 _assign) {
  u.val = reinterpret_cast<v2f64>(_assign.u.val); 
}
void double2::operator=(int4 _assign) {
  u.val = reinterpret_cast<v2f64>(_assign.u.val); 
}
void double2::operator=(uint4 _assign) {
  u.val = reinterpret_cast<v2f64>(_assign.u.val); 
}
void double2::operator=(long2 _assign) {
  u.val = reinterpret_cast<v2f64>(_assign.u.val); 
}
void double2::operator=(ulong2 _assign) {
  u.val = reinterpret_cast<v2f64>(_assign.u.val); 
}

void ulong2::operator=(float4 _assign) {
  u.val = reinterpret_cast<uv2i64>(_assign.u.val); 
}
void ulong2::operator=(int4 _assign) {
  u.val = reinterpret_cast<uv2i64>(_assign.u.val); 
}
void ulong2::operator=(uint4 _assign) {
  u.val = reinterpret_cast<uv2i64>(_assign.u.val); 
}
void ulong2::operator=(long2 _assign) {
  u.val = reinterpret_cast<uv2i64>(_assign.u.val); 
}
void ulong2::operator=(double2 _assign) {
  u.val = reinterpret_cast<uv2i64>(_assign.u.val); 
}

void long2::operator=(float4 _assign) {
  u.val = reinterpret_cast<v2i64>(_assign.u.val); 
}
void long2::operator=(int4 _assign) {
  u.val = reinterpret_cast<v2i64>(_assign.u.val); 
}
void long2::operator=(uint4 _assign) {
  u.val = reinterpret_cast<v2i64>(_assign.u.val); 
}
void long2::operator=(ulong2 _assign) {
  u.val = reinterpret_cast<v2i64>(_assign.u.val); 
}
void long2::operator=(double2 _assign) {
  u.val = reinterpret_cast<v2i64>(_assign.u.val); 
}

void int4::operator=(float4 _assign) {
  u.val = reinterpret_cast<v4i32>(_assign.u.val); 
}
void int4::operator=(ulong2 _assign) {
  u.val = reinterpret_cast<v4i32>(_assign.u.val); 
}
void int4::operator=(uint4 _assign) {
  u.val = reinterpret_cast<v4i32>(_assign.u.val); 
}
void int4::operator=(long2 _assign) {
  u.val = reinterpret_cast<v4i32>(_assign.u.val); 
}
void int4::operator=(double2 _assign) {
  u.val = reinterpret_cast<v4i32>(_assign.u.val); 
}

void uint4::operator=(float4 _assign) {
  u.val = reinterpret_cast<uv4i32>(_assign.u.val); 
}
void uint4::operator=(ulong2 _assign) {
  u.val = reinterpret_cast<uv4i32>(_assign.u.val); 
}
void uint4::operator=(int4 _assign) {
  u.val = reinterpret_cast<uv4i32>(_assign.u.val); 
}
void uint4::operator=(long2 _assign) {
  u.val = reinterpret_cast<uv4i32>(_assign.u.val); 
}
void uint4::operator=(double2 _assign) {
  u.val = reinterpret_cast<uv4i32>(_assign.u.val); 
}

void uXMM::operator=(float4 _assign) {
  f = _assign; 
}
void uXMM::operator=(ulong2 _assign) {
  ul = _assign;
}
void uXMM::operator=(int4 _assign) {
  i = _assign;
}
void uXMM::operator=(uint4 _assign) {
  ui = _assign;
}
void uXMM::operator=(long2 _assign) {
  ul = _assign;
}
void uXMM::operator=(double2 _assign) {
  d = _assign;
}

#endif
