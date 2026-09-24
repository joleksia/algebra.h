#if !defined (_vec4_h_)
# define _vec4_h_ 1
#
# include "./type/vec4.h"
# include "./type/mat4.h"

/* Properties */

vec4 alg_vec4(float, float, float, float);

vec4 alg_vec4init(float, float, float, float);

/* Math operations */

vec4 alg_vec4add(vec4, vec4);

vec4 alg_vec4sub(vec4, vec4);

vec4 alg_vec4mul(vec4, vec4);

vec4 alg_vec4div(vec4, vec4);

vec4 alg_vec4addf(vec4, float);

vec4 alg_vec4subf(vec4, float);

vec4 alg_vec4mulf(vec4, float);

vec4 alg_vec4divf(vec4, float);

vec4 alg_vec4mulm(vec4, mat4);

/* Boolean expressions */

bool alg_vec4eq(vec4, vec4);

bool alg_vec4ne(vec4, vec4);

bool alg_vec4gt(vec4, vec4);

bool alg_vec4ge(vec4, vec4);

bool alg_vec4lt(vec4, vec4);

bool alg_vec4le(vec4, vec4);

/* Distance operations */

float alg_vec4ln(vec4);

float alg_vec4lnsq(vec4);

float alg_vec4dist(vec4, vec4);

float alg_vec4distsq(vec4, vec4);

/* Unary arithmetics */

float alg_vec4dot(vec4, vec4);

vec4 alg_vec4cross(vec4, vec4);

vec4 alg_vec4norm(vec4);

vec4 alg_vec4neg(vec4);

vec4 alg_vec4abs(vec4);

vec4 alg_vec4sign(vec4);

vec4 alg_vec4sqrt(vec4);

vec4 alg_vec4pow(vec4, float);

vec4 alg_vec4fract(vec4);

vec4 alg_vec4floor(vec4);

vec4 alg_vec4ceil(vec4);

vec4 alg_vec4round(vec4);

vec4 alg_vec4mod(vec4, vec4);

vec4 alg_vec4modf(vec4, float);

/* Constraints */

vec4 alg_vec4min(vec4, vec4);

vec4 alg_vec4minf(vec4, float);

vec4 alg_vec4max(vec4, vec4);

vec4 alg_vec4maxf(vec4, float);

vec4 alg_vec4clamp(vec4, vec4, vec4);

vec4 alg_vec4clampf(vec4, float, float);

/* Interpolation */

vec4 alg_vec4lerp(vec4, vec4, float);

vec4 alg_vec4step(vec4, vec4);

vec4 alg_vec4smoothstep(vec4, vec4, vec4);

/* Geometric operations */

vec4 alg_vec4reflect(vec4, vec4);

vec4 alg_vec4refract(vec4, vec4, float);

vec4 alg_vec4project(vec4, vec4);

vec4 alg_vec4reject(vec4, vec4);

vec4 alg_vec4rotate(vec4, vec4, float);

float alg_vec4angle(vec4, vec4);

#endif /* _vec4_h_ */
#
#if defined (ALGEBRA_IMPLEMENTATION)
# if !defined (_vec4_impl_h_)
#  define _vec4_impl_h_ 1
#
#  include <math.h>
#  include "utils.h"

/* Properties */

vec4 alg_vec4(float x, float y, float z, float w) {
    vec4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return (v);
}

vec4 alg_vec4init(float x, float y, float z, float w) {
    vec4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return (v);
}

/* Math operations */

vec4 alg_vec4add(vec4 a, vec4 b) {
    vec4 v = alg_vec4(
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w
    ); return (v);
}


vec4 alg_vec4sub(vec4 a, vec4 b) {
    vec4 v = alg_vec4(
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w
    ); return (v);
}


vec4 alg_vec4mul(vec4 a, vec4 b) {
    vec4 v = alg_vec4(
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
        a.w * b.w
    ); return (v);
}


vec4 alg_vec4div(vec4 a, vec4 b) {
    vec4 v = alg_vec4(
        b.x != 0.0f ? a.x / b.x : 0.0f,
        b.y != 0.0f ? a.y / b.y : 0.0f,
        b.z != 0.0f ? a.z / b.z : 0.0f,
        b.w != 0.0f ? a.w / b.w : 0.0f
    ); return (v);
}


vec4 alg_vec4addf(vec4 a, float f) {
    vec4 v = alg_vec4(
        a.x + f,
        a.y + f,
        a.z + f,
        a.w + f
    ); return (v);
}


vec4 alg_vec4subf(vec4 a, float f) {
    vec4 v = alg_vec4(
        a.x - f,
        a.y - f,
        a.z - f,
        a.w - f
    ); return (v);
}


vec4 alg_vec4mulf(vec4 a, float f) {
    vec4 v = alg_vec4(
        a.x * f,
        a.y * f,
        a.z * f,
        a.w * f
    ); return (v);
}


vec4 alg_vec4divf(vec4 a, float f) {
    vec4 v = alg_vec4(
        f != 0.0f ? a.x / f : 0.0f,
        f != 0.0f ? a.y / f : 0.0f,
        f != 0.0f ? a.z / f : 0.0f,
        f != 0.0f ? a.w / f : 0.0f
    ); return (v);
}


vec4 alg_vec4mulm(vec4 a, mat4 m) {
    vec4 v = alg_vec4(
        m.m00 * a.x + m.m10 * a.y + m.m20 * a.z + m.m30 * a.w,
        m.m01 * a.x + m.m11 * a.y + m.m21 * a.z + m.m31 * a.w,
        m.m02 * a.x + m.m12 * a.y + m.m22 * a.z + m.m32 * a.w,
        m.m03 * a.x + m.m13 * a.y + m.m23 * a.z + m.m33 * a.w
    ); return (v);
}

/* Boolean expressions */

bool alg_vec4eq(vec4 a, vec4 b) {
    return (fabsf(a.x - b.x) < 1e-6f &&
            fabsf(a.y - b.y) < 1e-6f &&
            fabsf(a.z - b.z) < 1e-6f &&
            fabsf(a.w - b.w) < 1e-6f);
}


bool alg_vec4ne(vec4 a, vec4 b) {
    return (!alg_vec4eq(a, b));
}


bool alg_vec4gt(vec4 a, vec4 b) {
    return (a.x > b.x ||
            a.y > b.y ||
            a.z > b.z ||
            a.w > b.w);
}


bool alg_vec4ge(vec4 a, vec4 b) {
    return (a.x >= b.x ||
            a.y >= b.y ||
            a.z >= b.z ||
            a.w >= b.w);
}


bool alg_vec4lt(vec4 a, vec4 b) {
    return (a.x < b.x ||
            a.y < b.y ||
            a.z < b.z ||
            a.w < b.w);
}


bool alg_vec4le(vec4 a, vec4 b) {
    return (a.x <= b.x ||
            a.y <= b.y ||
            a.z <= b.z ||
            a.w <= b.w);
}

/* Distance operations */

float alg_vec4ln(vec4 a) {
    return (sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w));
}


float alg_vec4lnsq(vec4 a) {
    return (a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}


float alg_vec4dist(vec4 a, vec4 b) {
    return (sqrtf((a.x - b.x) * (a.x - b.x) +
                  (a.y - b.y) * (a.y - b.y) +
                  (a.z - b.z) * (a.z - b.z) +
                  (a.w - b.w) * (a.w - b.w)));
}


float alg_vec4distsq(vec4 a, vec4 b) {
    return ((a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y) +
            (a.z - b.z) * (a.z - b.z) +
            (a.w - b.w) * (a.w - b.w));
}

/* Unary arithmetics */

float alg_vec4dot(vec4 a, vec4 b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}


vec4 alg_vec4cross(vec4 a, vec4 b) {
    vec4 v = alg_vec4(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x,
        a.x * b.y - a.y * b.x
    ); return (v);
}


vec4 alg_vec4norm(vec4 a) {
    float ln = alg_vec4ln(a);
    if (ln != 0.0f) {
        a.x *= 1.0f / ln;
        a.y *= 1.0f / ln;
        a.z *= 1.0f / ln;
        a.w *= 1.0f / ln;
    }

    return (a);
}


vec4 alg_vec4neg(vec4 a) {
    vec4 v = alg_vec4(
        -a.x,
        -a.y,
        -a.z,
        -a.w
    ); return (v);
}


vec4 alg_vec4abs(vec4 a) {
    vec4 v = alg_vec4(
        fabsf(a.x),
        fabsf(a.y),
        fabsf(a.z),
        fabsf(a.w)
    ); return (v);
}


vec4 alg_vec4sign(vec4 a) {
    vec4 v = alg_vec4(
        a.x > 0.0f ? 1.0f : (a.x < 0.0f ? -1.0f : 0.0f),
        a.y > 0.0f ? 1.0f : (a.y < 0.0f ? -1.0f : 0.0f),
        a.z > 0.0f ? 1.0f : (a.z < 0.0f ? -1.0f : 0.0f),
        a.w > 0.0f ? 1.0f : (a.w < 0.0f ? -1.0f : 0.0f)
    ); return (v);
}


vec4 alg_vec4sqrt(vec4 a) {
    vec4 v = alg_vec4(
        sqrtf(a.x),
        sqrtf(a.y),
        sqrtf(a.z),
        sqrtf(a.w)
    ); return (v);
}


vec4 alg_vec4pow(vec4 a, float f) {
    vec4 v = alg_vec4(
        powf(a.x, f),
        powf(a.y, f),
        powf(a.z, f),
        powf(a.w, f)
    ); return (v);
}


vec4 alg_vec4fract(vec4 a) {
    vec4 v = alg_vec4(
        alg_fract(a.x),
        alg_fract(a.y),
        alg_fract(a.z),
        alg_fract(a.w)
    ); return (v);
}


vec4 alg_vec4floor(vec4 a) {
    vec4 v = alg_vec4(
        floorf(a.x),
        floorf(a.y),
        floorf(a.z),
        floorf(a.w)
    ); return (v);
}


vec4 alg_vec4ceil(vec4 a) {
    vec4 v = alg_vec4(
        ceilf(a.x),
        ceilf(a.y),
        ceilf(a.z),
        ceilf(a.w)
    ); return (v);
}


vec4 alg_vec4round(vec4 a) {
    vec4 v = alg_vec4(
        roundf(a.x),
        roundf(a.y),
        roundf(a.z),
        roundf(a.w)
    ); return (v);
}


vec4 alg_vec4mod(vec4 a, vec4 b) {
    vec4 v = alg_vec4(
        a.x - b.x * floorf(a.x / b.x),
        a.y - b.y * floorf(a.y / b.y),
        a.z - b.z * floorf(a.z / b.z),
        a.w - b.w * floorf(a.w / b.w)
    ); return (v);
}


vec4 alg_vec4modf(vec4 a, float f) {
    vec4 v = alg_vec4(
        a.x - f * floorf(a.x / f),
        a.y - f * floorf(a.y / f),
        a.z - f * floorf(a.z / f),
        a.w - f * floorf(a.w / f)
    ); return (v);
}

/* Constraints */

vec4 alg_vec4min(vec4 a, vec4 b) {
    vec4 v = alg_vec4(
        alg_min(a.x, b.x),
        alg_min(a.y, b.y),
        alg_min(a.z, b.z),
        alg_min(a.w, b.w)
    ); return (v);
}


vec4 alg_vec4minf(vec4 a, float f) {
    vec4 v = alg_vec4(
        alg_min(a.x, f),
        alg_min(a.y, f),
        alg_min(a.z, f),
        alg_min(a.w, f)
    ); return (v);
}


vec4 alg_vec4max(vec4 a, vec4 b) {
    vec4 v = alg_vec4(
        alg_max(a.x, b.x),
        alg_max(a.y, b.y),
        alg_max(a.z, b.z),
        alg_max(a.w, b.w)
    ); return (v);
}


vec4 alg_vec4maxf(vec4 a, float f) {
    vec4 v = alg_vec4(
        alg_max(a.x, f),
        alg_max(a.y, f),
        alg_max(a.z, f),
        alg_max(a.w, f)
    ); return (v);
}


vec4 alg_vec4clamp(vec4 a, vec4 lo, vec4 hi) {
    vec4 v = alg_vec4(
        alg_clamp(a.x, lo.x, hi.x),
        alg_clamp(a.y, lo.y, hi.y),
        alg_clamp(a.z, lo.z, hi.z),
        alg_clamp(a.w, lo.w, hi.w)
    ); return (v);
}


vec4 alg_vec4clampf(vec4 a, float lo, float hi) {
    vec4 v = alg_vec4(
        alg_clamp(a.x, lo, hi),
        alg_clamp(a.y, lo, hi),
        alg_clamp(a.z, lo, hi),
        alg_clamp(a.w, lo, hi)
    ); return (v);
}

/* Interpolation */

vec4 alg_vec4lerp(vec4 a, vec4 b, float t) {
    vec4 v = alg_vec4(
        alg_lerp(a.x, b.x, t),
        alg_lerp(a.y, b.y, t),
        alg_lerp(a.z, b.z, t),
        alg_lerp(a.w, b.w, t)
    ); return (v);
}


vec4 alg_vec4step(vec4 a, vec4 x) {
    vec4 v = alg_vec4(
        alg_step(a.x, x.x),
        alg_step(a.y, x.y),
        alg_step(a.z, x.z),
        alg_step(a.w, x.w)
    ); return (v);
}


vec4 alg_vec4smoothstep(vec4 e0, vec4 e1, vec4 x) {
    vec4 v = alg_vec4(
        alg_smoothstep(e0.x, e1.x, x.x),
        alg_smoothstep(e0.y, e1.y, x.y),
        alg_smoothstep(e0.z, e1.z, x.z),
        alg_smoothstep(e0.w, e1.w, x.w)
    ); return (v);
}

/* Geometric operations */

vec4 alg_vec4reflect(vec4 a, vec4 n) {
    float d = alg_vec4dot(a, n);
    vec4  v = alg_vec4(
        a.x - 2.0f * d * n.x,
        a.y - 2.0f * d * n.y,
        a.z - 2.0f * d * n.z,
        a.w - 2.0f * d * n.w
    ); return (v);
}


vec4 alg_vec4refract(vec4 a, vec4 n, float eta) {
    float d0 = alg_vec4dot(a, n);
    float d1 = 1.0f - eta * eta * (1.0 - d0 * d0);
    vec4  v = alg_vec4(0.0, 0.0, 0.0, 0.0);
    if (d1 >= 0) {
        d1 = sqrtf(d1);
        v.x = eta * a.x - (eta * d0 + d1) * n.x;
        v.y = eta * a.y - (eta * d0 + d1) * n.y;
        v.z = eta * a.z - (eta * d0 + d1) * n.z;
        v.w = eta * a.w - (eta * d0 + d1) * n.w;
    }

    return (v);
}

# endif /* _vec4_impl_h_ */
#endif /* ALGEBRA_IMPLEMENTATION */
