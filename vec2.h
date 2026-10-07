#if !defined (_vec2_h_)
# define _vec2_h_ 1
#
# include <stdbool.h>
# include "./type/vec2.h"
# include "./type/mat2.h"

/* Properties */

vec2 alg_vec2(float, float);

vec2 alg_vec2init(float, float);

/* Math operations */

vec2 alg_vec2add(vec2, vec2);

vec2 alg_vec2sub(vec2, vec2);

vec2 alg_vec2mul(vec2, vec2);

vec2 alg_vec2div(vec2, vec2);

vec2 alg_vec2addf(vec2, float);

vec2 alg_vec2subf(vec2, float);

vec2 alg_vec2mulf(vec2, float);

vec2 alg_vec2divf(vec2, float);

vec2 alg_vec2mulm(vec2, mat2);

/* Boolean expressions */

bool alg_vec2eq(vec2, vec2);

bool alg_vec2ne(vec2, vec2);

bool alg_vec2gt(vec2, vec2);

bool alg_vec2ge(vec2, vec2);

bool alg_vec2lt(vec2, vec2);

bool alg_vec2le(vec2, vec2);

/* Distance Operations */

float alg_vec2ln(vec2);

float alg_vec2lnsq(vec2);

float alg_vec2dst(vec2, vec2);

float alg_vec2dstsq(vec2, vec2);

/* Unary Arithmetics */

float alg_vec2dot(vec2, vec2);

float alg_vec2det(vec2, vec2);

vec2 alg_vec2norm(vec2);

vec2 alg_vec2neg(vec2);

vec2 alg_vec2abs(vec2);

vec2 alg_vec2sign(vec2);

vec2 alg_vec2sqrt(vec2);

vec2 alg_vec2pow(vec2, float);

vec2 alg_vec2fract(vec2);

vec2 alg_vec2floor(vec2);

vec2 alg_vec2ceil(vec2);

vec2 alg_vec2round(vec2);

vec2 alg_vec2mod(vec2, vec2);

vec2 alg_vec2modf(vec2, float);

/* Constraints */

vec2 alg_vec2min(vec2, vec2);

vec2 alg_vec2minf(vec2, float);

vec2 alg_vec2max(vec2, vec2);

vec2 alg_vec2maxf(vec2, float);

vec2 alg_vec2clamp(vec2, vec2, vec2);

vec2 alg_vec2clampf(vec2, float, float);

/* Interpolation */

vec2 alg_vec2lerp(vec2, vec2, float);

vec2 alg_vec2step(vec2, vec2);

vec2 alg_vec2smoothstep(vec2, vec2, vec2);

/* Geometric operations */

vec2 alg_vec2perp(vec2);

vec2 alg_vec2reflect(vec2, vec2);

vec2 alg_vec2refract(vec2, vec2, float);

vec2 alg_vec2rotate(vec2, float);

float alg_vec2angle(vec2, vec2);

#endif /* _vec2_h_ */
#
#if defined (ALGEBRA_IMPLEMENTATION)
# if !defined (_vec2_impl_h_)
#  define _vec2_impl_h_ 1
#
#  include <math.h>
#  include "utils.h"

/* Properties */

vec2 alg_vec2(float x, float y) {
    vec2 v;
    v.x = x;
    v.y = y;
    return (v);
}

vec2 alg_vec2init(float x, float y) {
    vec2 v;
    v.x = x;
    v.y = y;
    return (v);
}

/* Math operations */

vec2 alg_vec2add(vec2 a, vec2 b) {
    vec2 v = alg_vec2(
        a.x + b.x,
        a.y + b.y
    ); return (v);
}


vec2 alg_vec2sub(vec2 a, vec2 b) {
    vec2 v = alg_vec2(
        a.x - b.x,
        a.y - b.y
    ); return (v);
}


vec2 alg_vec2mul(vec2 a, vec2 b) {
    vec2 v = alg_vec2(
        a.x * b.x,
        a.y * b.y
    ); return (v);
}


vec2 alg_vec2div(vec2 a, vec2 b) {
    vec2 v = alg_vec2(
        b.x != 0.0f ? a.x / b.x : 0.0f,
        b.y != 0.0f ? a.y / b.y : 0.0f
    ); return (v);
}


vec2 alg_vec2addf(vec2 a, float f) {
    vec2 v = alg_vec2(
        a.x + f,
        a.y + f
    ); return (v);
}


vec2 alg_vec2subf(vec2 a, float f) {
    vec2 v = alg_vec2(
        a.x - f,
        a.y - f
    ); return (v);
}


vec2 alg_vec2mulf(vec2 a, float f) {
    vec2 v = alg_vec2(
        a.x * f,
        a.y * f
    ); return (v);
}


vec2 alg_vec2divf(vec2 a, float f) {
    vec2 v = alg_vec2(
        f != 0.0f ? a.x / f : 0.0f,
        f != 0.0f ? a.y / f : 0.0f
    ); return (v);
}


vec2 alg_vec2mulm(vec2 a, mat2 m) {
    vec2 v = alg_vec2(
        m.m00 * a.x + m.m10 * a.y,
        m.m01 * a.x + m.m11 * a.y
    ); return (v);
}

/* Boolean expressions */

bool alg_vec2eq(vec2 a, vec2 b) {
    return (fabsf(a.x - b.x) < 1e-6f &&
            fabsf(a.y - b.y) < 1e-6f);
}


bool alg_vec2ne(vec2 a, vec2 b) {
    return (fabsf(a.x - b.x) > 1e-6f ||
            fabsf(a.y - b.y) > 1e-6f);
}


bool alg_vec2gt(vec2 a, vec2 b) {
    return (a.x > b.x ||
            a.y > b.y);
}


bool alg_vec2ge(vec2 a, vec2 b) {
    return (a.x >= b.x ||
            a.y >= b.y);
}


bool alg_vec2lt(vec2 a, vec2 b) {
    return (a.x < b.x ||
            a.y < b.y);
}


bool alg_vec2le(vec2 a, vec2 b) {
    return (a.x <= b.x ||
            a.y <= b.y);
}

/* Distance Operations */

float alg_vec2ln(vec2 a) {
    return (sqrtf(a.x * a.x + a.y * a.y));
}


float alg_vec2lnsq(vec2 a) {
    return (a.x * a.x + a.y * a.y);
}


float alg_vec2dst(vec2 a, vec2 b) {
    return (sqrtf((a.x - b.x) * (a.x - b.x) +
                  (a.y - b.y) * (a.y - b.y)));
}


float alg_vec2dstsq(vec2 a, vec2 b) {
    return ((a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y));
}

/* Unary Arithmetics */

float alg_vec2dot(vec2 a, vec2 b) {
    return (a.x * b.x + a.y * b.y);
}


float alg_vec2det(vec2 a, vec2 b) {
    return (a.x * b.y - a.y * b.x);
}


vec2 alg_vec2norm(vec2 a) {
    float ln = sqrtf(a.x * a.x + a.y * a.y);
    if (ln != 0.0f) {
        a.x *= 1.0f / ln;
        a.y *= 1.0f / ln;
    }
    return (a);
}


vec2 alg_vec2neg(vec2 a) {
    vec2 v = alg_vec2(-a.x, -a.x);
    return (v);
}


vec2 alg_vec2abs(vec2 a) {
    vec2 v = alg_vec2(
        fabsf(a.x),
        fabsf(a.y)
    ); return (v);
}


vec2 alg_vec2sign(vec2 a) {
    vec2 v = alg_vec2(
        a.x > 0.0f ? 1.0f : (a.x < 0.0f ? -1.0f : 0.0f),
        a.y > 0.0f ? 1.0f : (a.y < 0.0f ? -1.0f : 0.0f)
    ); return (v);
}


vec2 alg_vec2sqrt(vec2 a) {
    vec2 v = alg_vec2(
        sqrtf(a.x),
        sqrtf(a.y)
    ); return (v);
}


vec2 alg_vec2pow(vec2 a, float f) {
    vec2 v = alg_vec2(
        powf(a.x, f),
        powf(a.y, f)
    ); return (v);
}


vec2 alg_vec2fract(vec2 a) {
    vec2 v = alg_vec2(
        alg_fract(a.x),
        alg_fract(a.y)
    ); return (v);
}


vec2 alg_vec2floor(vec2 a) {
    vec2 v = alg_vec2(
        floorf(a.x),
        floorf(a.y)
    ); return (v);
}


vec2 alg_vec2ceil(vec2 a) {
    vec2 v = alg_vec2(
        ceilf(a.x),
        ceilf(a.y)
    ); return (v);
}


vec2 alg_vec2round(vec2 a) {
    vec2 v = alg_vec2(
        roundf(a.x),
        roundf(a.y)
    ); return (v);
}


vec2 alg_vec2mod(vec2 a, vec2 b) {
    vec2 v = alg_vec2(
        a.x - b.x * floorf(a.x / b.x),
        a.y - b.y * floorf(a.y / b.y)
    ); return (v);
}


vec2 alg_vec2modf(vec2 a, float f) {
    vec2 v = alg_vec2(
    v.x = a.x - f * floorf(a.x / f),
    v.y = a.y - f * floorf(a.y / f)
    ); return (v);
}

/* Constraints */

vec2 alg_vec2min(vec2 a, vec2 b) {
    vec2 v = alg_vec2(
        alg_min(a.x, b.x),
        alg_min(a.y, b.y)
    ); return (v);
}


vec2 alg_vec2minf(vec2 a, float f) {
    vec2 v = alg_vec2(
        alg_min(a.x, f),
        alg_min(a.y, f)
    ); return (v);
}


vec2 alg_vec2max(vec2 a, vec2 b) {
    vec2 v = alg_vec2(
        alg_max(a.x, b.x),
        alg_max(a.y, b.y)
    ); return (v);
}


vec2 alg_vec2maxf(vec2 a, float f) {
    vec2 v = alg_vec2(
        alg_max(a.x, f),
        alg_max(a.y, f)
    ); return (v);
}


vec2 alg_vec2clamp(vec2 a, vec2 lo, vec2 hi) {
    vec2 v = alg_vec2(
        alg_clamp(a.x, lo.x, hi.x),
        alg_clamp(a.y, lo.y, hi.y)
    ); return (v);
}


vec2 alg_vec2clampf(vec2 a, float lo, float hi) {
    vec2 v = alg_vec2(
        alg_clamp(a.x, lo, hi),
        alg_clamp(a.y, lo, hi)
    ); return (v);
}

/* Interpolation */

vec2 alg_vec2lerp(vec2 a, vec2 b, float t) {
    vec2 v = alg_vec2(
        alg_lerp(a.x, b.x, t),
        alg_lerp(a.y, b.y, t)
    ); return (v);
}


vec2 alg_vec2step(vec2 a, vec2 x) {
    vec2 v = alg_vec2(
        alg_step(a.x, x.x),
        alg_step(a.y, x.y)
    ); return (v);
}


vec2 alg_vec2smoothstep(vec2 e0, vec2 e1, vec2 x) {
    vec2 v = alg_vec2(
        alg_smoothstep(e0.x, e1.x, x.x),
        alg_smoothstep(e0.y, e1.y, x.y)
    ); return (v);
}

/* Geometric operations */

vec2 alg_vec2perp(vec2 a) {
    vec2 v = alg_vec2(-a.x, a.x);
    return (v);
}


vec2 alg_vec2reflect(vec2 a, vec2 n) {
    float dot = a.x * n.x + a.y * n.y;
    vec2  v = alg_vec2(
        a.x - 2.0f * dot * n.x,
        a.y - 2.0f * dot * n.y
    ); return (v);
}


vec2 alg_vec2refract(vec2 a, vec2 n, float eta) {
    float dot = a.x * n.x + a.y * n.y;
    float d   = 1.0f - eta * eta * (1.0 - dot * dot);
    vec2  v = alg_vec2(0.0, 0.0);
    if (d >= 0) {
        d = sqrtf(d);
        v.x = eta * a.x - (eta * dot + d) * n.x;
        v.y = eta * a.y - (eta * dot + d) * n.y;
    }

    return (v);
}


vec2 alg_vec2rotate(vec2 a, float f) {
    float s = sinf(f);
    float c = cosf(f);
    vec2  v = alg_vec2(
        c * a.x - s * a.y,
        s * a.x + c * a.y
    ); return (v);
}


float alg_vec2angle(vec2 a, vec2 b) {
    float dot = alg_vec2dot(a, b); 
    float det = alg_vec2det(a, b);
    return (atan2f(det, dot));
}

# endif /* _vec2_impl_h_ */
#endif /* ALGEBRA_IMPLEMENTATION */
