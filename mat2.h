#if !defined (_mat2_h_)
# define _mat2_h_ 1
#
# include <stdbool.h>
# include "./type/vec2.h"
# include "./type/mat2.h"

/* Properties */

mat2 alg_mat2(float);

mat2 alg_mat2init(float);

/* Math operations */

mat2 alg_mat2add(mat2, mat2);

mat2 alg_mat2sub(mat2, mat2);

mat2 alg_mat2mul(mat2, mat2);

mat2 alg_mat2mulf(mat2, float);

 vec2 mat2mulv(mat2, vec2);

/* Boolean expressions */

bool alg_mat2eq(mat2, mat2);

bool alg_mat2ne(mat2, mat2);

/* Unary operations */

mat2 alg_mat2neg(mat2);

mat2 alg_mat2transpose(mat2);

mat2 alg_mat2inv(mat2);

/* Scalar operations */

float alg_mat2det(mat2);

float alg_mat2trace(mat2);

/* Construction */

mat2 alg_mat2rotate(float);

mat2 alg_mat2scale(vec2);

#endif /* _mat2_h_ */
#
#if defined (ALGEBRA_IMPLEMENTATION)
# if !defined (_mat2_impl_h_)
#  define _mat2_impl_h_ 1
#
#  include <math.h>
#  include "vec2.h"

/* Properties */

mat2 alg_mat2(float s) {
    mat2 m;
    m.m00 = 1.0f * s; m.m01 = 0.0f;
    m.m10 = 0.0f;     m.m11 = 1.0f * s;
    return (m);
}

mat2 alg_mat2init(float s) {
    mat2 m;
    m.m00 = 1.0f * s; m.m01 = 0.0f;
    m.m10 = 0.0f;     m.m11 = 1.0f * s;
    return (m);
}

/* Math operations */

mat2 alg_mat2add(mat2 a, mat2 b) {
    mat2 m = alg_mat2(0.0);
    m.m00 = a.m00 + b.m00; m.m01 = a.m01 + b.m01;
    m.m10 = a.m10 + b.m10; m.m11 = a.m11 + b.m11;
    return (m);
}


mat2 alg_mat2sub(mat2 a, mat2 b) {
    mat2 m = alg_mat2(0.0);
    m.m00 = a.m00 - b.m00; m.m01 = a.m01 - b.m01;
    m.m10 = a.m10 - b.m10; m.m11 = a.m11 - b.m11;
    return (m);
}


mat2 alg_mat2mul(mat2 a, mat2 b) {
    mat2 m = alg_mat2(0.0);
    m.m00 = a.m00 * b.m00 + a.m10 * b.m01; m.m01 = a.m01 * b.m00 + a.m11 * b.m01;
    m.m10 = a.m00 * b.m10 + a.m10 * b.m11; m.m11 = a.m01 * b.m10 + a.m11 * b.m11;
    return (m);
}


mat2 alg_mat2mulf(mat2 a, float f) {
    mat2 m = alg_mat2(0.0);
    m.m00 = a.m00 * f; m.m01 = a.m01 * f;
    m.m10 = a.m10 * f; m.m11 = a.m11 * f;
    return (m);
}


 vec2 mat2mulv(mat2 a, vec2 b) {
    vec2 v = alg_vec2(
        a.m00 * b.x + a.m10 * b.y,
        a.m01 * b.x + a.m11 * b.y
    ); return (v);
}

/* Boolean expressions */

bool alg_mat2eq(mat2 a, mat2 b) {
    return (fabsf(a.m00 - b.m00) < 1e-6f && fabsf(a.m01 - b.m01) < 1e-6f &&
            fabsf(a.m10 - b.m10) < 1e-6f && fabsf(a.m11 - b.m11) < 1e-6f);
}


bool alg_mat2ne(mat2 a, mat2 b) {
    return (!alg_mat2eq(a, b));
}

/* Unary operations */

mat2 alg_mat2neg(mat2 a) {
    mat2 m = alg_mat2(0.0);
    m.m00 = -a.m00; m.m01 = -a.m01;
    m.m10 = -a.m10; m.m11 = -a.m11;
    return (m);
}


mat2 alg_mat2transpose(mat2 a) {
    mat2 m = alg_mat2(0.0);
    m.m00 = a.m00; m.m01 = a.m10;
    m.m10 = a.m01; m.m11 = a.m11;
    return (m);
}


mat2 alg_mat2inv(mat2 a) {
    float det = alg_mat2det(a);
    if (det == 0.0f) {
        return (alg_mat2(0.0));
    } else {
        det = 1.0f / det;
    }

    mat2 m = alg_mat2(0.0);
    m.m00 =  a.m11 * det; m.m01 = -a.m01 * det;
    m.m10 = -a.m10 * det; m.m11 =  a.m00 * det;
    return (m);
}

/* Scalar operations */

float alg_mat2det(mat2 m) {
    return (m.m00 * m.m11 - m.m10 * m.m01);
}


float alg_mat2trace(mat2 m) {
    return (m.m00 + m.m11);
}

mat2 alg_mat2rotate(float angle) {
    float c = cosf(angle);
    float s = sinf(angle);

    mat2 m = alg_mat2(0.0);
    m.m00 =  c; m.m01 = s;
    m.m10 = -s; m.m11 = c;
    return (m);
}


mat2 alg_mat2scale(vec2 s) {
    mat2 m = alg_mat2(0.0);
    m.m00 = s.x;  m.m01 = 0.0f;
    m.m10 = 0.0f; m.m11 = s.y;
    return (m);
}

# endif /* _mat2_impl_h_ */
#endif /* ALGEBRA_IMPLEMENTATION */
