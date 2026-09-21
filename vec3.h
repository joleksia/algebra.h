#if !defined (_vec3_h_)
# define _vec3_h_ 1
#
# include "./type/vec3.h"
# include "./type/mat3.h"

/* Properties */

vec3 alg_vec3(float, float, float);

vec3 alg_vec3init(float, float, float);

/* Math operations */

vec3 alg_vec3add(vec3, vec3);

vec3 alg_vec3sub(vec3, vec3);

vec3 alg_vec3mul(vec3, vec3);

vec3 alg_vec3div(vec3, vec3);

vec3 alg_vec3addf(vec3, float);

vec3 alg_vec3subf(vec3, float);

vec3 alg_vec3mulf(vec3, float);

vec3 alg_vec3divf(vec3, float);

vec3 alg_vec3mulm(vec3, mat3);

/* Boolean expressions */

bool alg_vec3eq(vec3, vec3);

bool alg_vec3ne(vec3, vec3);

bool alg_vec3gt(vec3, vec3);

bool alg_vec3ge(vec3, vec3);

bool alg_vec3lt(vec3, vec3);

bool alg_vec3le(vec3, vec3);

/* Distance operations */

float alg_vec3ln(vec3);

float alg_vec3lnsq(vec3);

float alg_vec3dist(vec3, vec3);

float alg_vec3distsq(vec3, vec3);

/* Unary arithmetics */

float alg_vec3dot(vec3, vec3);

vec3 alg_vec3cross(vec3, vec3);

vec3 alg_vec3norm(vec3);

vec3 alg_vec3neg(vec3);

vec3 alg_vec3abs(vec3);

vec3 alg_vec3sign(vec3);

vec3 alg_vec3sqrt(vec3);

vec3 alg_vec3pow(vec3, float);

vec3 alg_vec3fract(vec3);

vec3 alg_vec3floor(vec3);

vec3 alg_vec3ceil(vec3);

vec3 alg_vec3round(vec3);

vec3 alg_vec3mod(vec3, vec3);

vec3 alg_vec3modf(vec3, float);

/* Constraints */

vec3 alg_vec3min(vec3, vec3);

vec3 alg_vec3minf(vec3, float);

vec3 alg_vec3max(vec3, vec3);

vec3 alg_vec3maxf(vec3, float);

vec3 alg_vec3clamp(vec3, vec3, vec3);

vec3 alg_vec3clampf(vec3, float, float);

/* Interpolation */

vec3 alg_vec3lerp(vec3, vec3, float);

vec3 alg_vec3step(vec3, vec3);

vec3 alg_vec3smoothstep(vec3, vec3, vec3);

/* Geometric operations */

vec3 alg_vec3reflect(vec3, vec3);

vec3 alg_vec3refract(vec3, vec3, float);

vec3 alg_vec3project(vec3, vec3);

vec3 alg_vec3reject(vec3, vec3);

vec3 alg_vec3rotate(vec3, vec3, float);

float alg_vec3angle(vec3, vec3);

#endif /* _vec3_h_ */
#
#if defined (ALGEBRA_IMPLEMENTATION)
# if !defined (_vec3_impl_h_)
#  define _vec3_impl_h_ 1
#
#  include <math.h>
#  include "utils.h"

/* Properties */

vec3 alg_vec3(float x, float y, float z) {
    vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return (v);
}

vec3 alg_vec3init(float x, float y, float z) {
    vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return (v);
}

/* Math operations */

vec3 alg_vec3add(vec3 a, vec3 b) {
    vec3 v = alg_vec3(
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    ); return (v);
}


vec3 alg_vec3sub(vec3 a, vec3 b) {
    vec3 v = alg_vec3(
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    ); return (v);
}


vec3 alg_vec3mul(vec3 a, vec3 b) {
    vec3 v = alg_vec3(
        a.x * b.x,
        a.y * b.y,
        a.z * b.z
    ); return (v);
}


vec3 alg_vec3div(vec3 a, vec3 b) {
    vec3 v = alg_vec3(
        b.x != 0.0f ? a.x / b.x : 0.0f,
        b.y != 0.0f ? a.y / b.y : 0.0f,
        b.z != 0.0f ? a.z / b.z : 0.0f
    ); return (v);
}


vec3 alg_vec3addf(vec3 a, float f) {
    vec3 v = alg_vec3(
        a.x + f,
        a.y + f,
        a.z + f
    ); return (v);
}


vec3 alg_vec3subf(vec3 a, float f) {
    vec3 v = alg_vec3(
        a.x - f,
        a.y - f,
        a.z - f
    ); return (v);
}


vec3 alg_vec3mulf(vec3 a, float f) {
    vec3 v = alg_vec3(
        a.x * f,
        a.y * f,
        a.z * f
    ); return (v);
}


vec3 alg_vec3divf(vec3 a, float f) {
    vec3 v = alg_vec3(
        f != 0.0f ? a.x / f : 0.0f,
        f != 0.0f ? a.y / f : 0.0f,
        f != 0.0f ? a.z / f : 0.0f
    ); return (v);
}


vec3 alg_vec3mulm(vec3 a, mat3 m) {
    vec3 v = alg_vec3(
        m.m00 * a.x + m.m10 * a.y + m.m20 * a.z,
        m.m01 * a.x + m.m11 * a.y + m.m21 * a.z,
        m.m02 * a.x + m.m12 * a.y + m.m22 * a.z
    ); return (v);
}

/* Boolean expressions */

bool alg_vec3eq(vec3 a, vec3 b) {
    return (a.x == b.x &&
            a.y == b.y &&
            a.z == b.z);
}


bool alg_vec3ne(vec3 a, vec3 b) {
    return (a.x != b.x ||
            a.y != b.y ||
            a.z != b.z);
}


bool alg_vec3gt(vec3 a, vec3 b) {
    return (a.x > b.x ||
            a.y > b.y ||
            a.z > b.z);
}


bool alg_vec3ge(vec3 a, vec3 b) {
    return (a.x >= b.x ||
            a.y >= b.y ||
            a.z >= b.z);
}


bool alg_vec3lt(vec3 a, vec3 b) {
    return (a.x < b.x ||
            a.y < b.y ||
            a.z < b.z);
}


bool alg_vec3le(vec3 a, vec3 b) {
    return (a.x <= b.x ||
            a.y <= b.y ||
            a.z <= b.z);
}

/* Distance operations */

float alg_vec3ln(vec3 a) {
    return (sqrtf(a.x * a.x + a.y * a.y + a.z * a.z));
}


float alg_vec3lnsq(vec3 a) {
    return (a.x * a.x + a.y * a.y + a.z * a.z);
}


float alg_vec3dist(vec3 a, vec3 b) {
    return (sqrtf((a.x - b.x) * (a.x - b.x) +
                  (a.y - b.y) * (a.y - b.y) +
                  (a.z - b.z) * (a.z - b.z)));
}


float alg_vec3distsq(vec3 a, vec3 b) {
    return ((a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y) +
            (a.z - b.z) * (a.z - b.z));
}

/* Unary arithmetics */

float alg_vec3dot(vec3 a, vec3 b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}


vec3 alg_vec3cross(vec3 a, vec3 b) {
    vec3 v = alg_vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    ); return (v);
}


vec3 alg_vec3norm(vec3 a) {
    float ln = alg_vec3ln(a);
    if (ln != 0.0f) {
        a.x *= 1.0f / ln;
        a.y *= 1.0f / ln;
        a.z *= 1.0f / ln;
    }

    return (a);
}


vec3 alg_vec3neg(vec3 a) {
    vec3 v = alg_vec3(
        -a.x,
        -a.y,
        -a.z
    ); return (v);
}


vec3 alg_vec3abs(vec3 a) {
    vec3 v = alg_vec3(
        fabsf(a.x),
        fabsf(a.y),
        fabsf(a.z)
    ); return (v);
}


vec3 alg_vec3sign(vec3 a) {
    vec3 v = alg_vec3(
        a.x > 0.0f ? 1.0f : (a.x < 0.0f ? -1.0f : 0.0f),
        a.y > 0.0f ? 1.0f : (a.y < 0.0f ? -1.0f : 0.0f),
        a.z > 0.0f ? 1.0f : (a.z < 0.0f ? -1.0f : 0.0f)
    ); return (v);
}


vec3 alg_vec3sqrt(vec3 a) {
    vec3 v = alg_vec3(
        sqrtf(a.x),
        sqrtf(a.y),
        sqrtf(a.z)
    ); return (v);
}


vec3 alg_vec3pow(vec3 a, float f) {
    vec3 v = alg_vec3(
        powf(a.x, f),
        powf(a.y, f),
        powf(a.z, f)
    ); return (v);
}


vec3 alg_vec3fract(vec3 a) {
    vec3 v = alg_vec3(
        alg_fract(a.x),
        alg_fract(a.y),
        alg_fract(a.z)
    ); return (v);
}


vec3 alg_vec3floor(vec3 a) {
    vec3 v = alg_vec3(
        floorf(a.x),
        floorf(a.y),
        floorf(a.z)
    ); return (v);
}


vec3 alg_vec3ceil(vec3 a) {
    vec3 v = alg_vec3(
        ceilf(a.x),
        ceilf(a.y),
        ceilf(a.z)
    ); return (v);
}


vec3 alg_vec3round(vec3 a) {
    vec3 v = alg_vec3(
        roundf(a.x),
        roundf(a.y),
        roundf(a.z)
    ); return (v);
}


vec3 alg_vec3mod(vec3 a, vec3 b) {
    vec3 v = alg_vec3(
        a.x - b.x * floorf(a.x / b.x),
        a.y - b.y * floorf(a.y / b.y),
        a.z - b.z * floorf(a.z / b.z)
    ); return (v);
}


vec3 alg_vec3modf(vec3 a, float f) {
    vec3 v = alg_vec3(
        a.x - f * floorf(a.x / f),
        a.y - f * floorf(a.y / f),
        a.z - f * floorf(a.z / f)
    ); return (v);
}

/* Constraints */

vec3 alg_vec3min(vec3 a, vec3 b) {
    vec3 v = alg_vec3(
        alg_min(a.x, b.x),
        alg_min(a.y, b.y),
        alg_min(a.z, b.z)
    ); return (v);
}


vec3 alg_vec3minf(vec3 a, float f) {
    vec3 v = alg_vec3(
        alg_min(a.x, f),
        alg_min(a.y, f),
        alg_min(a.z, f)
    ); return (v);
}


vec3 alg_vec3max(vec3 a, vec3 b) {
    vec3 v = alg_vec3(
        alg_max(a.x, b.x),
        alg_max(a.y, b.y),
        alg_max(a.z, b.z)
    ); return (v);
}


vec3 alg_vec3maxf(vec3 a, float f) {
    vec3 v = alg_vec3(
        alg_max(a.x, f),
        alg_max(a.y, f),
        alg_max(a.z, f)
    ); return (v);
}


vec3 alg_vec3clamp(vec3 a, vec3 lo, vec3 hi) {
    vec3 v = alg_vec3(
        alg_clamp(a.x, lo.x, hi.x),
        alg_clamp(a.y, lo.y, hi.y),
        alg_clamp(a.z, lo.z, hi.z)
    ); return (v);
}


vec3 alg_vec3clampf(vec3 a, float lo, float hi) {
    vec3 v = alg_vec3(
        alg_clamp(a.x, lo, hi),
        alg_clamp(a.y, lo, hi),
        alg_clamp(a.z, lo, hi)
    ); return (v);
}

/* Interpolation */

vec3 alg_vec3lerp(vec3 a, vec3 b, float t) {
    vec3 v = alg_vec3(
        alg_lerp(a.x, b.x, t),
        alg_lerp(a.y, b.y, t),
        alg_lerp(a.z, b.z, t)
    ); return (v);
}


vec3 alg_vec3step(vec3 a, vec3 x) {
    vec3 v = alg_vec3(
        alg_step(a.x, x.x),
        alg_step(a.y, x.y),
        alg_step(a.z, x.z)
    ); return (v);
}


vec3 alg_vec3smoothstep(vec3 e0, vec3 e1, vec3 x) {
    vec3 v = alg_vec3(
        alg_smoothstep(e0.x, e1.x, x.x),
        alg_smoothstep(e0.y, e1.y, x.y),
        alg_smoothstep(e0.z, e1.z, x.z)
    ); return (v);
}

/* Geometric operations */

vec3 alg_vec3reflect(vec3 a, vec3 n) {
    float d = alg_vec3dot(a, n);
    vec3  v = alg_vec3(
        a.x - 2.0f * d * n.x,
        a.y - 2.0f * d * n.y,
        a.z - 2.0f * d * n.z
    ); return (v);
}


vec3 alg_vec3refract(vec3 a, vec3 n, float eta) {
    float d0 = alg_vec3dot(a, n);
    float d1 = 1.0f - eta * eta * (1.0 - d0 * d0);
    vec3  v = alg_vec3(0.0, 0.0, 0.0);
    if (d1 >= 0) {
        d1 = sqrtf(d1);
        v.x = eta * a.x - (eta * d0 + d1) * n.x;
        v.y = eta * a.y - (eta * d0 + d1) * n.y;
        v.z = eta * a.z - (eta * d0 + d1) * n.z;
    }

    return (v);
}


vec3 alg_vec3project(vec3 a, vec3 b) {
    float ln0 = alg_vec3lnsq(a);
    float ln1 = alg_vec3lnsq(b);
    float mag = ln0 / ln1;
    vec3  v = alg_vec3(
        b.x * mag,
        b.y * mag,
        b.z * mag
    );
    return (v);
}


vec3 alg_vec3reject(vec3 a, vec3 b) {
    float ln0 = alg_vec3lnsq(a);
    float ln1 = alg_vec3lnsq(b);
    float mag  = ln0 / ln1;
    vec3  v = alg_vec3(
        a.x - b.x * mag,
        a.y - b.y * mag,
        a.z - b.z * mag
    ); return (v);
}


/* Euler-Rodrigues Formula:
 *      
 *      v' = v + 2a(w * x) + 2(w * (w * x))
 *
 * - https://en.wikipedia.org/w/index.php?title=Euler%E2%80%93Rodrigues_formula
 * - https://en.wikipedia.org/w/index.php?title=Euler%E2%80%93Rodrigues_formula#Vector_formulation
 * */
vec3 alg_vec3rotate(vec3 x, vec3 axis, float angle) {
    float sn = sinf(angle / 2.0);
    float cs = cosf(angle / 2.0);
    vec3  n = alg_vec3norm(axis);
    float a = n.x * sn;
    float b = n.y * sn;
    float c = n.z * sn;

    vec3 w = alg_vec3(a, b, c);
    vec3 v = alg_vec3(
        x.x + 2.0 * cs * (w.x * x.x) + 2.0 * (w.x * (w.x * x.x)),
        x.y + 2.0 * cs * (w.y * x.y) + 2.0 * (w.y * (w.y * x.y)),
        x.z + 2.0 * cs * (w.z * x.z) + 2.0 * (w.z * (w.z * x.z))
    ); return (v);
}


float alg_vec3angle(vec3 a, vec3 b) {
    vec3 cross = alg_vec3cross(a, b);
    return (atan2f(alg_vec3ln(cross), alg_vec3dot(a, b)));

}

# endif /* _vec3_impl_h_ */
#endif /* ALGEBRA_IMPLEMENTATION */
