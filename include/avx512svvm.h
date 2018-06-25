#ifndef _AVX512_SVVM_H_
#define _AVX512_SVVM_H_

typedef float                   v16f32 __attribute__((ext_vector_type(16)));
typedef int                     v16i32 __attribute__((ext_vector_type(16)));
typedef unsigned int           uv16i32 __attribute__((ext_vector_type(16)));
typedef long long int            v8i64 __attribute__((ext_vector_type(8)));
typedef unsigned long long int  uv8i64 __attribute__((ext_vector_type(8)));
typedef double                   v8f64 __attribute__((ext_vector_type(8)));

typedef int           maski16 __attribute__((ext_vector_type(16)));
typedef long long int maskl8  __attribute__((ext_vector_type(8)));
typedef float         maskf16 __attribute__((ext_vector_type(16)));
typedef double        maskd8  __attribute__((ext_vector_type(8)));

struct int16;
struct uint16;
struct float16;
struct long8;
struct ulong8;
struct double8;
struct mask;
union  uZMM;

struct int16
{
  int16()              { u.val = 0; }
  int16(v16i32 assign) { u.val = assign; }
  int16(int    assign) { u.val = assign; }  
  union U {
    v16i32 val;
    int    elem[16];
  } u;

  // set
  __inline void set(int pos, int set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(int16 dst, int pos, int set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(int16 *dst, int pos, int set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline int get(int pos)
  {
    return u.elem[pos];
  }
  __inline static int get(int16 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static int get(int16 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float16 _assign);
  __inline void operator=(uint16  _assign);
  __inline void operator=(long8   _assign);
  __inline void operator=(double8 _assign);
  __inline void operator=(ulong8  _assign);

  // add  
  __inline int16& operator+(uZMM _add);
  __inline int16 operator+(int16 _add)
  {
    return int16(u.val + _add.u.val);
  }
  __inline int16 operator+(int _add)
  {
    return int16(u.val + (int16(_add)).u.val);
  }
 
  // sub
  __inline int16& operator-(uZMM _sub);
  __inline int16 operator-(int16 _sub)
  {
    return int16(u.val - _sub.u.val);
  }
  __inline int16 operator-(int _sub)
  {
    return int16(u.val - (int16(_sub)).u.val);
  }

  // multiply
  __inline int16& operator*(uZMM _mul);
  __inline int16 operator*(int16 _mul)
  {
    return int16(u.val * _mul.u.val);
  }
  __inline int16 operator*(int _mul)
  {
    return int16(u.val * (int16(_mul)).u.val);
  }

  // divide
  __inline int16& operator/(uZMM _div);
  __inline int16 operator/(int16 _div)
  {
    return int16(u.val / _div.u.val);
  }
  __inline int16 operator/(int _div)
  {
    return int16(u.val / (int16(_div)).u.val);
  }

  // modulo (not SIMD)
  __inline int16& operator%(uZMM _mod);
  __inline int16 operator%(int16 _mod)
  {
    return int16(u.val % _mod.u.val);
  }
  __inline int16 operator%(int _mod)
  {
    return int16(u.val % (int16(_mod)).u.val);
  }

  // and
  __inline int16& operator&(uZMM _and);
  __inline int16 operator&(int16 _and)
  {
    return int16(u.val & _and.u.val);
  }
  __inline int16 operator&(int _and)
  {
    return int16(u.val & (int16(_and)).u.val);
  }

  // or
  __inline int16& operator|(uZMM _or);
  __inline int16 operator|(int16 _or)
  {
    return int16(u.val | _or.u.val);
  }
  __inline int16 operator|(int _or)
  {
    return int16(u.val | (int16(_or)).u.val);
  }

  // xor
  __inline int16& operator^(uZMM _xor);
  __inline int16 operator^(int16 _xor)
  {
    return int16(u.val ^ _xor.u.val);
  }
  __inline int16 operator^(int _xor)
  {
    return int16(u.val ^ (int16(_xor)).u.val);
  }

  // sll
  __inline int16& operator<<(uZMM _sll);
  __inline int16 operator<<(int16 _sll)
  {
    return int16(u.val << _sll.u.val);
  }
  __inline int16 operator<<(int _sll)
  {
    return int16(u.val << (int16(_sll)).u.val);
  }  

  // sra
  __inline int16& operator>>(uZMM _sra);
  __inline int16 operator>>(int16 _sra)
  {
    return int16(u.val >> _sra.u.val);
  }
  __inline int16 operator>>(int _sra)
  {
    return int16(u.val >> (int16(_sra)).u.val);
  }  

  // compare
  __inline mask operator<(int16  _lt);
  __inline mask operator<=(int16 _le);
  __inline mask operator>(int16  _gt);
  __inline mask operator>=(int16 _ge);
  __inline mask operator==(int16 _eq);
  __inline mask operator!=(int16 _ne);
};

struct uint16
{
  uint16()                    { u.val = 0; }
  uint16(uv16i32      assign) { u.val = assign; }
  uint16(unsigned int assign) { u.val = assign; }  
  union U {
    uv16i32      val;
    unsigned int elem[16];
  } u;

  // set
  __inline void set(int pos, unsigned int set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(uint16 dst, int pos, unsigned int set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(uint16 *dst, int pos, unsigned int set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline unsigned int get(int pos)
  {
    return u.elem[pos];
  }
  __inline static unsigned int get(uint16 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static unsigned int get(uint16 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float16 _assign);
  __inline void operator=(int16   _assign);
  __inline void operator=(long8   _assign);
  __inline void operator=(double8 _assign);
  __inline void operator=(ulong8  _assign);

  // add
  __inline uint16& operator+(uZMM _add);
  __inline uint16 operator+(uint16 _add)
  {
    return uint16(u.val + _add.u.val);
  }
  __inline uint16 operator+(unsigned int _add)
  {
    return uint16(u.val + (uint16(_add)).u.val);
  }
 
  // sub
  __inline uint16& operator-(uZMM _sub);  
  __inline uint16 operator-(uint16 _sub)
  {
    return uint16(u.val - _sub.u.val);
  }
  __inline uint16 operator-(unsigned int _sub)
  {
    return uint16(u.val - (uint16(_sub)).u.val);
  }

  // multiply
  __inline uint16& operator*(uZMM _mul);
  __inline uint16 operator*(uint16 _mul)
  {
    return uint16(u.val * _mul.u.val);
  }
  __inline uint16 operator*(unsigned int _mul)
  {
    return uint16(u.val * (uint16(_mul)).u.val);
  }

  // divide
  __inline uint16& operator/(uZMM _div);
  __inline uint16 operator/(uint16 _div)
  {
    return uint16(u.val / _div.u.val);
  }
  __inline uint16 operator/(unsigned int _div)
  {
    return uint16(u.val / (uint16(_div)).u.val);
  }

  // modulo (not SIMD)
  __inline uint16& operator%(uZMM _mod);  
  __inline uint16 operator%(uint16 _mod)
  {
    return uint16(u.val % _mod.u.val);
  }
  __inline uint16 operator%(unsigned int _mod)
  {
    return uint16(u.val % (uint16(_mod)).u.val);
  }

  // and
  __inline uint16& operator&(uZMM _and);  
  __inline uint16 operator&(uint16 _and)
  {
    return uint16(u.val & _and.u.val);
  }
  __inline uint16 operator&(unsigned int _and)
  {
    return uint16(u.val & (uint16(_and)).u.val);
  }

  // or
  __inline uint16& operator|(uZMM _or);  
  __inline uint16 operator|(uint16 _or)
  {
    return uint16(u.val | _or.u.val);
  }
  __inline uint16 operator|(unsigned int _or)
  {
    return uint16(u.val | (uint16(_or)).u.val);
  }

  // xor
  __inline uint16& operator^(uZMM _xor);
  __inline uint16 operator^(uint16 _xor)
  {
    return uint16(u.val ^ _xor.u.val);
  }
  __inline uint16 operator^(unsigned int _xor)
  {
    return uint16(u.val ^ (uint16(_xor)).u.val);
  }

  // sll
  __inline uint16& operator<<(uZMM _sll);  
  __inline uint16 operator<<(uint16 _sll)
  {
    return uint16(u.val << _sll.u.val);
  }
  __inline uint16 operator<<(unsigned int _sll)
  {
    return uint16(u.val << (uint16(_sll)).u.val);
  }  

  // srl
  __inline uint16& operator>>(uZMM _srl);
  __inline uint16 operator>>(uint16 _srl)
  {
    return uint16(u.val >> _srl.u.val);
  }
  __inline uint16 operator>>(unsigned int _srl)
  {
    return uint16(u.val >> (uint16(_srl)).u.val);
  }  

  // compare
  __inline mask operator<(uint16  _lt);
  __inline mask operator<=(uint16 _le);
  __inline mask operator>(uint16  _gt);
  __inline mask operator>=(uint16 _ge);
  __inline mask operator==(uint16 _eq);
  __inline mask operator!=(uint16 _ne);
};

struct long8
{
  long8()             { u.val = 0; }
  long8(v8i64 assign) { u.val = assign; }
  long8(long  assign) { u.val = assign; }  
  union U {
    v8i64 val;
    long  elem[8];
  } u;

  // set
  __inline void set(int pos, long set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(long8 dst, int pos, long set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(long8 *dst, int pos, long set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline long get(int pos)
  {
    return u.elem[pos];
  }
  __inline static long get(long8 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static long get(long8 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float16 _assign);
  __inline void operator=(int16   _assign);
  __inline void operator=(uint16  _assign);
  __inline void operator=(double8 _assign);
  __inline void operator=(ulong8  _assign);

  // add  
  __inline long8& operator+(uZMM _add);
  __inline long8 operator+(long8 _add)
  {
    return long8(u.val + _add.u.val);
  }
  __inline long8 operator+(long _add)
  {
    return long8(u.val + (long8(_add)).u.val);
  }
 
  // sub
  __inline long8& operator-(uZMM _sub);
  __inline long8 operator-(long8 _sub)
  {
    return long8(u.val - _sub.u.val);
  }
  __inline long8 operator-(long _sub)
  {
    return long8(u.val - (long8(_sub)).u.val);
  }

  // multiply
  __inline long8& operator*(uZMM _mul);
  __inline long8 operator*(long8 _mul)
  {
    return long8(u.val * _mul.u.val);
  }
  __inline long8 operator*(long _mul)
  {
    return long8(u.val * (long8(_mul)).u.val);
  }

  // divide
  __inline long8& operator/(uZMM _div);
  __inline long8 operator/(long8 _div)
  {
    return long8(u.val / _div.u.val);
  }
  __inline long8 operator/(long _div)
  {
    return long8(u.val / (long8(_div)).u.val);
  }

  // modulo (not SIMD)
  __inline long8& operator%(uZMM _mod);
  __inline long8 operator%(long8 _mod)
  {
    return long8(u.val % _mod.u.val);
  }
  __inline long8 operator%(long _mod)
  {
    return long8(u.val % (long8(_mod)).u.val);
  }

  // and
  __inline long8& operator&(uZMM _and);
  __inline long8 operator&(long8 _and)
  {
    return long8(u.val & _and.u.val);
  }
  __inline long8 operator&(long _and)
  {
    return long8(u.val & (long8(_and)).u.val);
  }

  // or
  __inline long8& operator|(uZMM _or);
  __inline long8 operator|(long8 _or)
  {
    return long8(u.val | _or.u.val);
  }
  __inline long8 operator|(long _or)
  {
    return long8(u.val | (long8(_or)).u.val);
  }

  // xor
  __inline long8& operator^(uZMM _xor);
  __inline long8 operator^(long8 _xor)
  {
    return long8(u.val ^ _xor.u.val);
  }
  __inline long8 operator^(long _xor)
  {
    return long8(u.val ^ (long8(_xor)).u.val);
  }

  // sll
  __inline long8& operator<<(uZMM _sll);
  __inline long8 operator<<(long8 _sll)
  {
    return long8(u.val << _sll.u.val);
  }
  __inline long8 operator<<(long _sll)
  {
    return long8(u.val << (long8(_sll)).u.val);
  }  

  // sra
  __inline long8& operator>>(uZMM _sra);
  __inline long8 operator>>(long8 _sra)
  {
    return long8(u.val >> _sra.u.val);
  }
  __inline long8 operator>>(long _sra)
  {
    return long8(u.val >> (long8(_sra)).u.val);
  }  

  // compare
  __inline mask operator<(long8  _lt);
  __inline mask operator<=(long8 _le);
  __inline mask operator>(long8  _gt);
  __inline mask operator>=(long8 _ge);
  __inline mask operator==(long8 _eq);
  __inline mask operator!=(long8 _ne);
};

struct ulong8
{
  ulong8()                     { u.val = 0; }
  ulong8(uv8i64        assign) { u.val = assign; }
  ulong8(unsigned long assign) { u.val = assign; }  
  union U {
    uv8i64        val;
    unsigned long elem[8];
  } u;

  // set
  __inline void set(int pos, unsigned long set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(ulong8 dst, int pos, unsigned long set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(ulong8 *dst, int pos, unsigned long set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline unsigned long get(int pos)
  {
    return u.elem[pos];
  }
  __inline static unsigned long get(ulong8 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static unsigned long get(ulong8 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float16 _assign);
  __inline void operator=(int16   _assign);
  __inline void operator=(uint16  _assign);
  __inline void operator=(long8   _assign);
  __inline void operator=(double8 _assign);

  // add
  __inline ulong8& operator+(uZMM _add);
  __inline ulong8 operator+(ulong8 _add)
  {
    return ulong8(u.val + _add.u.val);
  }
  __inline ulong8 operator+(unsigned long _add)
  {
    return ulong8(u.val + (ulong8(_add)).u.val);
  }
 
  // sub
  __inline ulong8& operator-(uZMM _sub);  
  __inline ulong8 operator-(ulong8 _sub)
  {
    return ulong8(u.val - _sub.u.val);
  }
  __inline ulong8 operator-(unsigned long _sub)
  {
    return ulong8(u.val - (ulong8(_sub)).u.val);
  }

  // multiply
  __inline ulong8& operator*(uZMM _mul);
  __inline ulong8 operator*(ulong8 _mul)
  {
    return ulong8(u.val * _mul.u.val);
  }
  __inline ulong8 operator*(unsigned long _mul)
  {
    return ulong8(u.val * (ulong8(_mul)).u.val);
  }

  // divide
  __inline ulong8& operator/(uZMM _div);
  __inline ulong8 operator/(ulong8 _div)
  {
    return ulong8(u.val / _div.u.val);
  }
  __inline ulong8 operator/(unsigned long _div)
  {
    return ulong8(u.val / (ulong8(_div)).u.val);
  }

  // modulo (not SIMD)
  __inline ulong8& operator%(uZMM _mod);  
  __inline ulong8 operator%(ulong8 _mod)
  {
    return ulong8(u.val % _mod.u.val);
  }
  __inline ulong8 operator%(unsigned long _mod)
  {
    return ulong8(u.val % (ulong8(_mod)).u.val);
  }

  // and
  __inline ulong8& operator&(uZMM _and);  
  __inline ulong8 operator&(ulong8 _and)
  {
    return ulong8(u.val & _and.u.val);
  }
  __inline ulong8 operator&(unsigned long _and)
  {
    return ulong8(u.val & (ulong8(_and)).u.val);
  }

  // or
  __inline ulong8& operator|(uZMM _or);  
  __inline ulong8 operator|(ulong8 _or)
  {
    return ulong8(u.val | _or.u.val);
  }
  __inline ulong8 operator|(unsigned long _or)
  {
    return ulong8(u.val | (ulong8(_or)).u.val);
  }

  // xor
  __inline ulong8& operator^(uZMM _xor);
  __inline ulong8 operator^(ulong8 _xor)
  {
    return ulong8(u.val ^ _xor.u.val);
  }
  __inline ulong8 operator^(unsigned long _xor)
  {
    return ulong8(u.val ^ (ulong8(_xor)).u.val);
  }

  // sll
  __inline ulong8& operator<<(uZMM _sll);  
  __inline ulong8 operator<<(ulong8 _sll)
  {
    return ulong8(u.val << _sll.u.val);
  }
  __inline ulong8 operator<<(unsigned long _sll)
  {
    return ulong8(u.val << (ulong8(_sll)).u.val);
  }  

  // srl
  __inline ulong8& operator>>(uZMM _srl);
  __inline ulong8 operator>>(ulong8 _srl)
  {
    return ulong8(u.val >> _srl.u.val);
  }
  __inline ulong8 operator>>(unsigned long _srl)
  {
    return ulong8(u.val >> (ulong8(_srl)).u.val);
  }  

  // compare
  __inline mask operator<(ulong8  _lt);
  __inline mask operator<=(ulong8 _le);
  __inline mask operator>(ulong8  _gt);
  __inline mask operator>=(ulong8 _ge);
  __inline mask operator==(ulong8 _eq);
  __inline mask operator!=(ulong8 _ne);
};

struct float16
{
  float16()              { u.val = 0.0f; }
  float16(v16f32 assign) { u.val = assign; }
  float16(float  assign) { u.val = assign; }  
  union U {
    v16f32 val;
    float  elem[16];
  } u;

  // set
  __inline void set(int pos, float set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(float16 dst, int pos, float set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(float16 *dst, int pos, float set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline float get(int pos)
  {
    return u.elem[pos];
  }
  __inline static float get(float16 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static float get(float16 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(int16   _assign);
  __inline void operator=(uint16  _assign);
  __inline void operator=(long8   _assign);
  __inline void operator=(double8 _assign);
  __inline void operator=(ulong8  _assign);

  // add
  __inline float16& operator+(uZMM _add);
  __inline float16 operator+(float16 _add)
  {
    return float16(u.val + _add.u.val);
  }
  __inline float16 operator+(float _add)
  {
    return float16(u.val + (float16(_add)).u.val);
  }
 
  // sub
  __inline float16& operator-(uZMM _sub);  
  __inline float16 operator-(float16 _sub)
  {
    return float16(u.val - _sub.u.val);
  }
  __inline float16 operator-(float _sub)
  {
    return float16(u.val - (float16(_sub)).u.val);
  }

  // multiply
  __inline float16& operator*(uZMM _mul);
  __inline float16 operator*(float16 _mul)
  {
    return float16(u.val * _mul.u.val);
  }
  __inline float16 operator*(float _mul)
  {
    return float16(u.val * (float16(_mul)).u.val);
  }

  // divide
  __inline float16& operator/(uZMM _div); 
  __inline float16 operator/(float16 _div)
  {
    return float16(u.val / _div.u.val);
  }
  __inline float16 operator/(float _div)
  {
    return float16(u.val / (float16(_div)).u.val);
  }
  
  // compare
  __inline mask operator<(float16  _lt);
  __inline mask operator<=(float16 _le);
  __inline mask operator>(float16  _gt);
  __inline mask operator>=(float16 _ge);
  __inline mask operator==(float16 _eq);
  __inline mask operator!=(float16 _ne);
};

struct double8
{
  double8()              { u.val = 0.0; }
  double8(v8f64  assign) { u.val = assign; }
  double8(double assign) { u.val = assign; }  
  union U {
    v8f64  val;
    double elem[8];
  } u;

  // set
  __inline void set(int pos, double set)
  {
    u.elem[pos] = set;
  }
  __inline static void set(double8 dst, int pos, double set)
  {
    dst.u.elem[pos] = set;
  }
  __inline static void set(double8 *dst, int pos, double set)
  {
    dst->u.elem[pos] = set;
  }
  
  // get
  __inline double get(int pos)
  {
    return u.elem[pos];
  }
  __inline static double get(double8 src, int pos)
  {
    return src.u.elem[pos];
  }
  __inline static double get(double8 *src, int pos)
  {
    return src->u.elem[pos];
  } 

  // assign
  __inline void operator=(float16 _assign);
  __inline void operator=(int16   _assign);
  __inline void operator=(uint16  _assign);
  __inline void operator=(long8   _assign);
  __inline void operator=(ulong8  _assign);

  // add
  __inline double8& operator+(uZMM _add);
  __inline double8 operator+(double8 _add)
  {
    return double8(u.val + _add.u.val);
  }
  __inline double8 operator+(double _add)
  {
    return double8(u.val + (double8(_add)).u.val);
  }
 
  // sub
  __inline double8& operator-(uZMM _sub);  
  __inline double8 operator-(double8 _sub)
  {
    return double8(u.val - _sub.u.val);
  }
  __inline double8 operator-(double _sub)
  {
    return double8(u.val - (double8(_sub)).u.val);
  }

  // multiply
  __inline double8& operator*(uZMM _mul);
  __inline double8 operator*(double8 _mul)
  {
    return double8(u.val * _mul.u.val);
  }
  __inline double8 operator*(double _mul)
  {
    return double8(u.val * (double8(_mul)).u.val);
  }

  // divide
  __inline double8& operator/(uZMM _div); 
  __inline double8 operator/(double8 _div)
  {
    return double8(u.val / _div.u.val);
  }
  __inline double8 operator/(double _div)
  {
    return double8(u.val / (double8(_div)).u.val);
  }

  // compare
  __inline mask operator<(double8  _lt);
  __inline mask operator<=(double8 _le);
  __inline mask operator>(double8  _gt);
  __inline mask operator>=(double8 _ge);
  __inline mask operator==(double8 _eq);
  __inline mask operator!=(double8 _ne);
};

struct mask {
  mask() {}
  mask(maskl8  m) { mr.ml8  = m; }
  mask(maskd8  m) { mr.md8  = m; }  
  mask(maski16 m) { mr.mi16 = m; }
  mask(maskf16 m) { mr.mf16 = m; }    
  union maskReg {
    maskl8  ml8;  // mask v8i64
    maskd8  md8;  // mask v8f64  
    maski16 mi16; // mask v16i32
    maskf16 mf16; // mask v16f32    
  } mr;

  __inline int16 _add(int16 _add1, int16 _add2)
  {
    // TODO: implement predicate patterns
    return _add1 + _add2; // temporal
  }
};

// int16
mask int16::operator<(int16 _lt) {
  return mask((maski16)(u.val < _lt.u.val));
}
mask int16::operator<=(int16 _le) {
  return mask((maski16)(u.val <= _le.u.val));
}
mask int16::operator>(int16 _gt) {
  return mask((maski16)(u.val > _gt.u.val));
}
mask int16::operator>=(int16 _ge) {
  return mask((maski16)(u.val >= _ge.u.val));
}
mask int16::operator==(int16 _eq) {
  return mask((maski16)(u.val == _eq.u.val));
}
mask int16::operator!=(int16 _ne) {
  return mask((maski16)(u.val != _ne.u.val));
}
// uint16
mask uint16::operator<(uint16 _lt) {
  return mask((maski16)(u.val < _lt.u.val));
}
mask uint16::operator<=(uint16 _le) {
  return mask((maski16)(u.val <= _le.u.val));
}
mask uint16::operator>(uint16 _gt) {
  return mask((maski16)(u.val > _gt.u.val));
}
mask uint16::operator>=(uint16 _ge) {
  return mask((maski16)(u.val >= _ge.u.val));
}
mask uint16::operator==(uint16 _eq) {
  return mask((maski16)(u.val == _eq.u.val));
}
mask uint16::operator!=(uint16 _ne) {
  return mask((maski16)(u.val != _ne.u.val));
}
// long8
mask long8::operator<(long8 _lt) {
  return mask((maskl8)(u.val < _lt.u.val));
}
mask long8::operator<=(long8 _le) {
  return mask((maskl8)(u.val <= _le.u.val));
}
mask long8::operator>(long8 _gt) {
  return mask((maskl8)(u.val > _gt.u.val));
}
mask long8::operator>=(long8 _ge) {
  return mask((maskl8)(u.val >= _ge.u.val));
}
mask long8::operator==(long8 _eq) {
  return mask((maskl8)(u.val == _eq.u.val));
}
mask long8::operator!=(long8 _ne) {
  return mask((maskl8)(u.val != _ne.u.val));
}
// ulong8
mask ulong8::operator<(ulong8 _lt) {
  return mask((maskl8)(u.val < _lt.u.val));
}
mask ulong8::operator<=(ulong8 _le) {
  return mask((maskl8)(u.val <= _le.u.val));
}
mask ulong8::operator>(ulong8 _gt) {
  return mask((maskl8)(u.val > _gt.u.val));
}
mask ulong8::operator>=(ulong8 _ge) {
  return mask((maskl8)(u.val >= _ge.u.val));
}
mask ulong8::operator==(ulong8 _eq) {
  return mask((maskl8)(u.val == _eq.u.val));
}
mask ulong8::operator!=(ulong8 _ne) {
  return mask((maskl8)(u.val != _ne.u.val));
}
// float16
mask float16::operator<(float16 _lt) {
  return mask((maskf16)(u.val < _lt.u.val));
}
mask float16::operator<=(float16 _le) {
  return mask((maskf16)(u.val <= _le.u.val));
}
mask float16::operator>(float16 _gt) {
  return mask((maskf16)(u.val > _gt.u.val));
}
mask float16::operator>=(float16 _ge) {
  return mask((maskf16)(u.val >= _ge.u.val));
}
mask float16::operator==(float16 _eq) {
  return mask((maskf16)(u.val == _eq.u.val));
}
mask float16::operator!=(float16 _ne) {
  return mask((maskf16)(u.val != _ne.u.val));
}
// double8
mask double8::operator<(double8 _lt) {
  return mask((maskd8)(u.val < _lt.u.val));
}
mask double8::operator<=(double8 _le) {
  return mask((maskd8)(u.val <= _le.u.val));
}
mask double8::operator>(double8 _gt) {
  return mask((maskd8)(u.val > _gt.u.val));
}
mask double8::operator>=(double8 _ge) {
  return mask((maskd8)(u.val >= _ge.u.val));
}
mask double8::operator==(double8 _eq) {
  return mask((maskd8)(u.val == _eq.u.val));
}
mask double8::operator!=(double8 _ne) {
  return mask((maskd8)(u.val != _ne.u.val));
}

//////////////////////
//// zmm register ////
//////////////////////
union uZMM {
  uZMM() : i() {}
  int16    i;
  uint16  ui;
  long8    l;
  ulong8  ul;   
  float16  f;
  double8  d;

  __inline void operator=(double8 _assign);
  __inline void operator=(float16 _assign);
  __inline void operator=(int16   _assign);
  __inline void operator=(uint16  _assign);
  __inline void operator=(long8   _assign);
  __inline void operator=(ulong8  _assign);
};

using zmm   = uZMM;
using zmmf  = float16;
using zmmd  = double8;
using zmmi  = int16;
using zmmui = uint16;
using zmml  = long8;
using zmmul = ulong8;

////////////////////////////////
//// signed int16 operations ////
////////////////////////////////
int16& int16::operator+(uZMM _add) {
  u.val = u.val + _add.i.u.val;
  return *this;
}
int16& int16::operator-(uZMM _sub) {
  u.val = u.val - _sub.i.u.val;
  return *this;
}
int16& int16::operator*(uZMM _mul) {
  u.val = u.val * _mul.i.u.val;
  return *this;
}
int16& int16::operator/(uZMM _div) {
  u.val = u.val / _div.i.u.val;
  return *this;
}
int16& int16::operator%(uZMM _mod) {
  u.val = u.val % _mod.i.u.val;
  return *this;
}
int16& int16::operator&(uZMM _and) {
  u.val = u.val & _and.i.u.val;
  return *this;
}
int16& int16::operator|(uZMM _or) {
  u.val = u.val | _or.i.u.val;
  return *this;
}
int16& int16::operator^(uZMM _xor) {
  u.val = u.val ^ _xor.i.u.val;
  return *this;
}
int16& int16::operator<<(uZMM _sll) {
  u.val = u.val << _sll.i.u.val;
  return *this;
}
int16& int16::operator>>(uZMM _sra) {
  u.val = u.val >> _sra.i.u.val;
  return *this;
}
//////////////////////////////////
//// unsigned int16 operations ////
//////////////////////////////////
uint16& uint16::operator+(uZMM _add) {
  u.val = u.val + _add.ui.u.val;
  return *this;
}
uint16& uint16::operator-(uZMM _sub) {
  u.val = u.val - _sub.ui.u.val;
  return *this;
}
uint16& uint16::operator*(uZMM _mul) {
  u.val = u.val * _mul.ui.u.val;
  return *this;
}
uint16& uint16::operator/(uZMM _div) {
  u.val = u.val / _div.ui.u.val;
  return *this;
}
uint16& uint16::operator%(uZMM _mod) {
  u.val = u.val % _mod.ui.u.val;
  return *this;
}
uint16& uint16::operator&(uZMM _and) {
  u.val = u.val & _and.ui.u.val;
  return *this;
}
uint16& uint16::operator|(uZMM _or) {
  u.val = u.val | _or.ui.u.val;
  return *this;
}
uint16& uint16::operator^(uZMM _xor) {
  u.val = u.val ^ _xor.ui.u.val;
  return *this;
}
uint16& uint16::operator<<(uZMM _sll) {
  u.val = u.val << _sll.ui.u.val;
  return *this;
}
uint16& uint16::operator>>(uZMM _srl) {
  u.val = u.val >> _srl.ui.u.val;
  return *this;
}
/////////////////////////////////
//// signed long8 operations ////
/////////////////////////////////
long8& long8::operator+(uZMM _add) {
  u.val = u.val + _add.l.u.val;
  return *this;
}
long8& long8::operator-(uZMM _sub) {
  u.val = u.val - _sub.l.u.val;
  return *this;
}
long8& long8::operator*(uZMM _mul) {
  u.val = u.val * _mul.l.u.val;
  return *this;
}
long8& long8::operator/(uZMM _div) {
  u.val = u.val / _div.l.u.val;
  return *this;
}
long8& long8::operator%(uZMM _mod) {
  u.val = u.val % _mod.l.u.val;
  return *this;
}
long8& long8::operator&(uZMM _and) {
  u.val = u.val & _and.l.u.val;
  return *this;
}
long8& long8::operator|(uZMM _or) {
  u.val = u.val | _or.l.u.val;
  return *this;
}
long8& long8::operator^(uZMM _xor) {
  u.val = u.val ^ _xor.l.u.val;
  return *this;
}
long8& long8::operator<<(uZMM _sll) {
  u.val = u.val << _sll.l.u.val;
  return *this;
}
long8& long8::operator>>(uZMM _sra) {
  u.val = u.val >> _sra.l.u.val;
  return *this;
}
//////////////////////////////////
//// unsigned long8 operations ////
//////////////////////////////////
ulong8& ulong8::operator+(uZMM _add) {
  u.val = u.val + _add.ul.u.val;
  return *this;
}
ulong8& ulong8::operator-(uZMM _sub) {
  u.val = u.val - _sub.ul.u.val;
  return *this;
}
ulong8& ulong8::operator*(uZMM _mul) {
  u.val = u.val * _mul.ul.u.val;
  return *this;
}
ulong8& ulong8::operator/(uZMM _div) {
  u.val = u.val / _div.ul.u.val;
  return *this;
}
ulong8& ulong8::operator%(uZMM _mod) {
  u.val = u.val % _mod.ul.u.val;
  return *this;
}
ulong8& ulong8::operator&(uZMM _and) {
  u.val = u.val & _and.ul.u.val;
  return *this;
}
ulong8& ulong8::operator|(uZMM _or) {
  u.val = u.val | _or.ul.u.val;
  return *this;
}
ulong8& ulong8::operator^(uZMM _xor) {
  u.val = u.val ^ _xor.ul.u.val;
  return *this;
}
ulong8& ulong8::operator<<(uZMM _sll) {
  u.val = u.val << _sll.ul.u.val;
  return *this;
}
ulong8& ulong8::operator>>(uZMM _srl) {
  u.val = u.val >> _srl.ul.u.val;
  return *this;
}
///////////////////////////
//// float16 operations ////
///////////////////////////
float16& float16::operator+(uZMM _add) {
  u.val = u.val + _add.f.u.val;
  return *this;
}
float16& float16::operator-(uZMM _sub) {
  u.val = u.val - _sub.f.u.val;
  return *this;
}
float16& float16::operator*(uZMM _mul) {
  u.val = u.val * _mul.f.u.val;
  return *this;
}
float16& float16::operator/(uZMM _div) {
  u.val = u.val / _div.f.u.val;
  return *this;
}
////////////////////////////
//// double8 operations ////
////////////////////////////
double8& double8::operator+(uZMM _add) {
  u.val = u.val + _add.d.u.val;
  return *this;
}
double8& double8::operator-(uZMM _sub) {
  u.val = u.val - _sub.d.u.val;
  return *this;
}
double8& double8::operator*(uZMM _mul) {
  u.val = u.val * _mul.d.u.val;
  return *this;
}
double8& double8::operator/(uZMM _div) {
  u.val = u.val / _div.d.u.val;
  return *this;
}

///////////////////////////////
//// assignment operations ////
///////////////////////////////
void float16::operator=(double8 _assign) {
  u.val = reinterpret_cast<v16f32>(_assign.u.val); 
}
void float16::operator=(int16 _assign) {
  u.val = reinterpret_cast<v16f32>(_assign.u.val); 
}
void float16::operator=(uint16 _assign) {
  u.val = reinterpret_cast<v16f32>(_assign.u.val); 
}
void float16::operator=(long8 _assign) {
  u.val = reinterpret_cast<v16f32>(_assign.u.val); 
}
void float16::operator=(ulong8 _assign) {
  u.val = reinterpret_cast<v16f32>(_assign.u.val); 
}

void double8::operator=(float16 _assign) {
  u.val = reinterpret_cast<v8f64>(_assign.u.val); 
}
void double8::operator=(int16 _assign) {
  u.val = reinterpret_cast<v8f64>(_assign.u.val); 
}
void double8::operator=(uint16 _assign) {
  u.val = reinterpret_cast<v8f64>(_assign.u.val); 
}
void double8::operator=(long8 _assign) {
  u.val = reinterpret_cast<v8f64>(_assign.u.val); 
}
void double8::operator=(ulong8 _assign) {
  u.val = reinterpret_cast<v8f64>(_assign.u.val); 
}

void ulong8::operator=(float16 _assign) {
  u.val = reinterpret_cast<uv8i64>(_assign.u.val); 
}
void ulong8::operator=(int16 _assign) {
  u.val = reinterpret_cast<uv8i64>(_assign.u.val); 
}
void ulong8::operator=(uint16 _assign) {
  u.val = reinterpret_cast<uv8i64>(_assign.u.val); 
}
void ulong8::operator=(long8 _assign) {
  u.val = reinterpret_cast<uv8i64>(_assign.u.val); 
}
void ulong8::operator=(double8 _assign) {
  u.val = reinterpret_cast<uv8i64>(_assign.u.val); 
}

void long8::operator=(float16 _assign) {
  u.val = reinterpret_cast<v8i64>(_assign.u.val); 
}
void long8::operator=(int16 _assign) {
  u.val = reinterpret_cast<v8i64>(_assign.u.val); 
}
void long8::operator=(uint16 _assign) {
  u.val = reinterpret_cast<v8i64>(_assign.u.val); 
}
void long8::operator=(ulong8 _assign) {
  u.val = reinterpret_cast<v8i64>(_assign.u.val); 
}
void long8::operator=(double8 _assign) {
  u.val = reinterpret_cast<v8i64>(_assign.u.val); 
}

void int16::operator=(float16 _assign) {
  u.val = reinterpret_cast<v16i32>(_assign.u.val); 
}
void int16::operator=(ulong8 _assign) {
  u.val = reinterpret_cast<v16i32>(_assign.u.val); 
}
void int16::operator=(uint16 _assign) {
  u.val = reinterpret_cast<v16i32>(_assign.u.val); 
}
void int16::operator=(long8 _assign) {
  u.val = reinterpret_cast<v16i32>(_assign.u.val); 
}
void int16::operator=(double8 _assign) {
  u.val = reinterpret_cast<v16i32>(_assign.u.val); 
}

void uint16::operator=(float16 _assign) {
  u.val = reinterpret_cast<uv16i32>(_assign.u.val); 
}
void uint16::operator=(ulong8 _assign) {
  u.val = reinterpret_cast<uv16i32>(_assign.u.val); 
}
void uint16::operator=(int16 _assign) {
  u.val = reinterpret_cast<uv16i32>(_assign.u.val); 
}
void uint16::operator=(long8 _assign) {
  u.val = reinterpret_cast<uv16i32>(_assign.u.val); 
}
void uint16::operator=(double8 _assign) {
  u.val = reinterpret_cast<uv16i32>(_assign.u.val); 
}

void uZMM::operator=(float16 _assign) {
  f = _assign; 
}
void uZMM::operator=(ulong8 _assign) {
  ul = _assign;
}
void uZMM::operator=(int16 _assign) {
  i = _assign;
}
void uZMM::operator=(uint16 _assign) {
  ui = _assign;
}
void uZMM::operator=(long8 _assign) {
  ul = _assign;
}
void uZMM::operator=(double8 _assign) {
  d = _assign;
}

#endif
