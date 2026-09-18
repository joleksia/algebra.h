#if !defined (_vec2_h_)
# define _vec2_h_ 1
#
# include <stdbool.h>
# include "./type/vec2.h"
# include "./type/mat2.h"
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */

/* Properties */

ALGAPI vec2 alg_vec2(float, float);

ALGAPI vec2 alg_vec2init(float, float);

/* Math operations */

ALGAPI vec2 alg_vec2add(vec2, vec2);

ALGAPI vec2 alg_vec2sub(vec2, vec2);

ALGAPI vec2 alg_vec2mul(vec2, vec2);

ALGAPI vec2 alg_vec2div(vec2, vec2);

ALGAPI vec2 alg_vec2addf(vec2, float);

ALGAPI vec2 alg_vec2subf(vec2, float);

ALGAPI vec2 alg_vec2mulf(vec2, float);

ALGAPI vec2 alg_vec2divf(vec2, float);

ALGAPI vec2 alg_vec2mulm(vec2, mat2);

/* Boolean expressions */

ALGAPI bool alg_vec2eq(vec2, vec2);

ALGAPI bool alg_vec2ne(vec2, vec2);

ALGAPI bool alg_vec2gt(vec2, vec2);

ALGAPI bool alg_vec2ge(vec2, vec2);

ALGAPI bool alg_vec2lt(vec2, vec2);

ALGAPI bool alg_vec2le(vec2, vec2);

/* Distance Operations */

ALGAPI float alg_vec2ln(vec2);

ALGAPI float alg_vec2lnsq(vec2);

ALGAPI float alg_vec2dst(vec2, vec2);

ALGAPI float alg_vec2dstsq(vec2, vec2);

/* Unary Arithmetics */

ALGAPI float alg_vec2dot(vec2, vec2);

ALGAPI float alg_vec2cross(vec2, vec2);

ALGAPI vec2 alg_vec2norm(vec2);

ALGAPI vec2 alg_vec2neg(vec2);

ALGAPI vec2 alg_vec2abs(vec2);

ALGAPI vec2 alg_vec2sign(vec2);

ALGAPI vec2 alg_vec2sqrt(vec2);

ALGAPI vec2 alg_vec2pow(vec2, float);

ALGAPI vec2 alg_vec2fract(vec2);

ALGAPI vec2 alg_vec2floor(vec2);

ALGAPI vec2 alg_vec2ceil(vec2);

ALGAPI vec2 alg_vec2round(vec2);

ALGAPI vec2 alg_vec2mod(vec2, vec2);

ALGAPI vec2 alg_vec2modf(vec2, float);

/* Constraints */

ALGAPI vec2 alg_vec2min(vec2, vec2);

ALGAPI vec2 alg_vec2minf(vec2, float);

ALGAPI vec2 alg_vec2max(vec2, vec2);

ALGAPI vec2 alg_vec2maxf(vec2, float);

ALGAPI vec2 alg_vec2clamp(vec2, vec2, vec2);

ALGAPI vec2 alg_vec2clampf(vec2, float, float);

/* Interpolation */

ALGAPI vec2 alg_vec2lerp(vec2, vec2, float);

ALGAPI vec2 alg_vec2step(vec2, vec2);

ALGAPI vec2 alg_vec2smoothstep(vec2, vec2, vec2);

/* Geometric operations */

ALGAPI vec2 alg_vec2perp(vec2);

ALGAPI vec2 alg_vec2reflect(vec2, vec2);

ALGAPI vec2 alg_vec2refract(vec2, vec2, float);

ALGAPI vec2 alg_vec2rotate(vec2, float);

ALGAPI float alg_vec2angle(vec2, vec2);

#endif /* _vec2_h_ */
#
#if defined (ALGEBRA_IMPLEMENTATION)
#
# include <math.h>
# include "./utils.h"

/* Properties */

ALGAPI vec2 alg_vec2(float x, float y) {
    vec2 v;
    v.x = x;
    v.y = y;
    return (v);
}

ALGAPI vec2 alg_vec2init(float x, float y) {
    vec2 v;
    v.x = x;
    v.y = y;
    return (v);
}

/* Math operations */

ALGAPI vec2 alg_vec2add(vec2 a, vec2 b) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = a.x + b.x;
    v.y = a.y + b.y;
    return (v);
}


ALGAPI vec2 alg_vec2sub(vec2 a, vec2 b) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    return (v);
}


ALGAPI vec2 alg_vec2mul(vec2 a, vec2 b) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = a.x * b.x;
    v.y = a.y * b.y;
    return (v);
}


ALGAPI vec2 alg_vec2div(vec2 a, vec2 b) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = b.x != 0.0f ? a.x / b.x : 0.0f;
    v.y = b.y != 0.0f ? a.y / b.y : 0.0f;
    return (v);
}


ALGAPI vec2 alg_vec2addf(vec2 a, float f) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = a.x + f;
    v.y = a.y + f;
    return (v);
}


ALGAPI vec2 alg_vec2subf(vec2 a, float f) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = a.x - f;
    v.y = a.y - f;
    return (v);
}


ALGAPI vec2 alg_vec2mulf(vec2 a, float f) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = a.x * f;
    v.y = a.y * f;
    return (v);
}


ALGAPI vec2 alg_vec2divf(vec2 a, float f) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = f != 0.0f ? a.x / f : 0.0f;
    v.y = f != 0.0f ? a.y / f : 0.0f;
    return (v);
}


ALGAPI vec2 alg_vec2mulm(vec2 a, mat2 m) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = m.m00 * a.x + m.m10 * a.y;
    v.y = m.m01 * a.x + m.m11 * a.y;
    return (v);
}

/* Boolean expressions */

ALGAPI bool alg_vec2eq(vec2 a, vec2 b) {
    return (fabsf(a.x - b.x) < 1e-6f &&
            fabsf(a.y - b.y) < 1e-6f);
}


ALGAPI bool alg_vec2ne(vec2 a, vec2 b) {
    return (fabsf(a.x - b.x) > 1e-6f ||
            fabsf(a.y - b.y) > 1e-6f);
}


ALGAPI bool alg_vec2gt(vec2 a, vec2 b) {
    return (a.x > b.x ||
            a.y > b.y);
}


ALGAPI bool alg_vec2ge(vec2 a, vec2 b) {
    return (a.x >= b.x ||
            a.y >= b.y);
}


ALGAPI bool alg_vec2lt(vec2 a, vec2 b) {
    return (a.x < b.x ||
            a.y < b.y);
}


ALGAPI bool alg_vec2le(vec2 a, vec2 b) {
    return (a.x <= b.x ||
            a.y <= b.y);
}

/* Distance Operations */

ALGAPI float alg_vec2ln(vec2 a) {
    return (sqrtf(a.x * a.x + a.y * a.y));
}


ALGAPI float alg_vec2lnsq(vec2 a) {
    return (a.x * a.x + a.y * a.y);
}


ALGAPI float alg_vec2dst(vec2 a, vec2 b) {
    return (sqrtf((a.x - b.x) * (a.x - b.x) +
                  (a.y - b.y) * (a.y - b.y)));
}


ALGAPI float alg_vec2dstsq(vec2 a, vec2 b) {
    return ((a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y));
}

/* Unary Arithmetics */

ALGAPI float alg_vec2dot(vec2 a, vec2 b) {
    return (a.x * b.x + a.y * b.y);
}


ALGAPI float alg_vec2cross(vec2 a, vec2 b) {
    return (a.x * b.y - a.y * b.x);
}


ALGAPI vec2 alg_vec2norm(vec2 a) {
    float ln = sqrtf(a.x * a.x + a.y * a.y);
    if (ln != 0.0f) {
        a.x *= 1.0f / ln;
        a.y *= 1.0f / ln;
    }
    return (a);
}


ALGAPI vec2 alg_vec2neg(vec2 a) {
    a.x = -a.x;
    a.y = -a.y;
    return (a);
}


ALGAPI vec2 alg_vec2abs(vec2 a) {
    a.x = fabsf(a.x);
    a.y = fabsf(a.y);
    return (a);
}


ALGAPI vec2 alg_vec2sign(vec2 a) {
    a.x = a.x > 0.0f ? 1.0f : (a.x < 0.0f ? -1.0f : 0.0f);
    a.y = a.y > 0.0f ? 1.0f : (a.y < 0.0f ? -1.0f : 0.0f);
    return (a);
}


ALGAPI vec2 alg_vec2sqrt(vec2 a) {
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    return (a);
}


ALGAPI vec2 alg_vec2pow(vec2 a, float f) {
    a.x = powf(a.x, f);
    a.y = powf(a.y, f);
    return (a);
}


ALGAPI vec2 alg_vec2fract(vec2 a) {
    a.x = alg_fract(a.x);
    a.y = alg_fract(a.y);
    return (a);
}


ALGAPI vec2 alg_vec2floor(vec2 a) {
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    return (a);
}


ALGAPI vec2 alg_vec2ceil(vec2 a) {
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    return (a);
}


ALGAPI vec2 alg_vec2round(vec2 a) {
    a.x = roundf(a.x);
    a.y = roundf(a.y);
    return (a);
}


ALGAPI vec2 alg_vec2mod(vec2 a, vec2 b) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = a.x - b.x * floorf(a.x / b.x);
    v.y = a.y - b.y * floorf(a.y / b.y);
    return (v);
}


ALGAPI vec2 alg_vec2modf(vec2 a, float f) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = a.x - f * floorf(a.x / f);
    v.y = a.y - f * floorf(a.y / f);
    return (v);
}

/* Constraints */

ALGAPI vec2 alg_vec2min(vec2 a, vec2 b) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = alg_min(a.x, b.x);
    v.y = alg_min(a.y, b.y);
    return (v);
}


ALGAPI vec2 alg_vec2minf(vec2 a, float f) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = alg_min(a.x, f);
    v.y = alg_min(a.y, f);
    return (v);
}


ALGAPI vec2 alg_vec2max(vec2 a, vec2 b) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = alg_max(a.x, b.x);
    v.y = alg_max(a.y, b.y);
    return (v);
}


ALGAPI vec2 alg_vec2maxf(vec2 a, float f) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = alg_max(a.x, f);
    v.y = alg_max(a.y, f);
    return (v);
}


ALGAPI vec2 alg_vec2clamp(vec2 a, vec2 lo, vec2 hi) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = alg_clamp(a.x, lo.x, hi.x);
    v.y = alg_clamp(a.y, lo.y, hi.y);
    return (v);
}


ALGAPI vec2 alg_vec2clampf(vec2 a, float lo, float hi) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = alg_clamp(a.x, lo, hi);
    v.y = alg_clamp(a.y, lo, hi);
    return (v);
}

/* Interpolation */

ALGAPI vec2 alg_vec2lerp(vec2 a, vec2 b, float t) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = alg_lerp(a.x, b.x, t);
    v.y = alg_lerp(a.y, b.y, t);
    return (v);
}


ALGAPI vec2 alg_vec2step(vec2 a, vec2 x) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = alg_step(a.x, x.x);
    v.y = alg_step(a.y, x.y);
    return (v);
}


ALGAPI vec2 alg_vec2smoothstep(vec2 e0, vec2 e1, vec2 x) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = alg_smoothstep(e0.x, e1.x, x.x);
    v.y = alg_smoothstep(e0.y, e1.y, x.y);
    return (v);
}

/* Geometric operations */

ALGAPI vec2 alg_vec2perp(vec2 a) {
    vec2 v = alg_vec2(0.0, 0.0);
    v.x = -a.y;
    v.y =  a.x;
    return (v);
}


ALGAPI vec2 alg_vec2reflect(vec2 a, vec2 n) {
    float dot = a.x * n.x + a.y * n.y;
    vec2  v = alg_vec2(0.0, 0.0);
    v.x = a.x - 2.0f * dot * n.x;
    v.y = a.y - 2.0f * dot * n.y;
    return (v);
}


ALGAPI vec2 alg_vec2refract(vec2 a, vec2 n, float eta) {
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


ALGAPI vec2 alg_vec2rotate(vec2 a, float f) {
    float s = sinf(f);
    float c = cosf(f);
    vec2  v = alg_vec2(0.0, 0.0);
    v.x = c * a.x - s * a.y;
    v.y = s * a.x + c * a.y;
    return (v);
}


ALGAPI float alg_vec2angle(vec2 a, vec2 b) {
    float dot = a.x * b.x + a.y * b.y;
    float det = a.x * b.y - a.y * b.x;

    return (atan2f(det, dot));
}

#endif /* ALGEBRA_IMPLEMENTATION */
