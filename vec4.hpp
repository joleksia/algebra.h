#if !defined (_vec4_hpp_)
# define _vec4_hpp_ 1
#
# include "./algebra-fwd.hpp"
# include "./type/vec4.hpp"
# include "./type/mat4.hpp"

namespace alg {

    /* Math operations */

    inline vec4 operator + (vec4, vec4);

    inline vec4 operator - (vec4, vec4);

    inline vec4 operator * (vec4, vec4);

    inline vec4 operator / (vec4, vec4);

    inline vec4 operator + (vec4, float);

    inline vec4 operator - (vec4, float);

    inline vec4 operator * (vec4, float);

    inline vec4 operator / (vec4, float);

    inline vec4 operator * (vec4, mat4);

    /* Boolean expressions */

    inline bool operator == (vec4, vec4);

    inline bool operator != (vec4, vec4);

    inline bool operator > (vec4, vec4);

    inline bool operator >= (vec4, vec4);

    inline bool operator < (vec4, vec4);

    inline bool operator <= (vec4, vec4);

    /* Math operations */

    inline vec4 &operator += (vec4 &, vec4);

    inline vec4 &operator -= (vec4 &, vec4);

    inline vec4 &operator *= (vec4 &, vec4);

    inline vec4 &operator /= (vec4 &, vec4);

    inline vec4 &operator += (vec4 &, float);

    inline vec4 &operator -= (vec4 &, float);

    inline vec4 &operator *= (vec4 &, float);

    inline vec4 &operator /= (vec4 &, float);

    /* Properties */

    template <>
    vec4 init<vec4>(float);

    template <>
    vec4 init<vec4>(float, float);

    template <>
    vec4 init<vec4>(float, float, float);

    template <>
    vec4 init<vec4>(float, float, float, float);

    /* Distance operations */

    template <>
    float ln<vec4>(vec4);

    template <>
    float lnsq<vec4>(vec4);

    template <>
    float dst<vec4>(vec4, vec4);

    template <>
    float dstsq<vec4>(vec4, vec4);

    /* Unary arithmetics */

    template <>
    float dot<vec4>(vec4, vec4);
    
    template <>
    vec4 cross<vec4>(vec4, vec4);

    template <>
    vec4 norm<vec4>(vec4);

    template <>
    vec4 neg<vec4>(vec4);

    template <>
    vec4 abs<vec4>(vec4);

    template <>
    vec4 sign<vec4>(vec4);

    template <>
    vec4 sqrt<vec4>(vec4);

    template <>
    vec4 pow<vec4>(vec4, float);

    template <>
    vec4 fract<vec4>(vec4);

    template <>
    vec4 floor<vec4>(vec4);

    template <>
    vec4 ceil<vec4>(vec4);

    template <>
    vec4 round<vec4>(vec4);

    /* Constraints */

    template <>
    vec4 min<vec4>(vec4, vec4);

    template <>
    vec4 minf<vec4>(vec4, float);

    template <>
    vec4 max<vec4>(vec4, vec4);

    template <>
    vec4 maxf<vec4>(vec4, float);

    template <>
    vec4 clamp<vec4>(vec4, vec4, vec4);

    template <>
    vec4 clampf<vec4>(vec4, float, float);

    /* Interpolation */

    template <>
    vec4 lerp<vec4>(vec4, vec4, float);

    template <>
    vec4 step<vec4>(vec4, vec4);

    template <>
    vec4 smoothstep<vec4>(vec4, vec4, vec4);

    /* Geometric operations */

    template <>
    vec4 perp<vec4>(vec4);

    template <>
    vec4 reflect<vec4>(vec4, vec4);

    template <>
    vec4 refract<vec4>(vec4, vec4, float);

    template <>
    float angle<vec4>(vec4, vec4);
    
    template <>
    vec4 rotate<vec4>(vec4, vec4, float);

};

#endif /* _vec4_hpp_ */
#
#if defined (ALGEBRA_IMPLEMENTATION)
# if !defined (_vec4_impl_hpp_)
#  define _vec4_impl_hpp_ 1
#
#  include <cmath>
#  include "utils.hpp"

namespace alg {

    /* Math operations */

    inline vec4 operator + (vec4 a, vec4 b) {
        vec4 v = alg::init<vec4>(
            a.x + b.x,
            a.y + b.y,
            a.z + b.z,
            a.w + b.w
        ); return (v);
    }


    inline vec4 operator - (vec4 a, vec4 b) {
        vec4 v = alg::init<vec4>(
            a.x - b.x,
            a.y - b.y,
            a.z - b.z,
            a.w - b.w
        ); return (v);
    }


    inline vec4 operator * (vec4 a, vec4 b) {
        vec4 v = alg::init<vec4>(
            a.x * b.x,
            a.y * b.y,
            a.z * b.z,
            a.w * b.w
        ); return (v);
    }


    inline vec4 operator / (vec4 a, vec4 b) {
        vec4 v = alg::init<vec4>(
            b.x != 0.0f ? a.x / b.x : 0.0f,
            b.y != 0.0f ? a.y / b.y : 0.0f,
            b.z != 0.0f ? a.z / b.z : 0.0f,
            b.w != 0.0f ? a.w / b.w : 0.0f
        ); return (v);
    }


    inline vec4 operator % (vec4 a, vec4 b) {
        vec4 v = alg::init<vec4>(
            a.x - b.x * floorf(a.x / b.x),
            a.y - b.y * floorf(a.y / b.y),
            a.z - b.z * floorf(a.z / b.z),
            a.w - b.w * floorf(a.w / b.w)
        ); return (v);
    }


    inline vec4 operator + (vec4 a, float f) {
        vec4 v = alg::init<vec4>(
            a.x + f,
            a.y + f,
            a.z + f,
            a.w + f
        ); return (v);
    }


    inline vec4 operator - (vec4 a, float f) {
        vec4 v = alg::init<vec4>(
            a.x - f,
            a.y - f,
            a.z - f,
            a.w - f
        ); return (v);
    }


    inline vec4 operator * (vec4 a, float f) {
        vec4 v = alg::init<vec4>(
            a.x * f,
            a.y * f,
            a.z * f,
            a.w * f
        ); return (v);
    }


    inline vec4 operator / (vec4 a, float f) {
        vec4 v = alg::init<vec4>(
            f != 0.0f ? a.x / f : 0.0f,
            f != 0.0f ? a.y / f : 0.0f,
            f != 0.0f ? a.z / f : 0.0f,
            f != 0.0f ? a.w / f : 0.0f
        ); return (v);
    }


    inline vec4 operator % (vec4 a, float f) {
        vec4 v = alg::init<vec4>(
            a.x - f * floorf(a.x / f),
            a.y - f * floorf(a.y / f),
            a.z - f * floorf(a.z / f),
            a.w - f * floorf(a.w / f)
        ); return (v);
    }


    inline vec4 operator * (vec4 a, mat4 m) {
        vec4 v = alg::init<vec4>(
            m.m00 * a.x + m.m10 * a.y + m.m20 * a.z + m.m30 * a.w,
            m.m01 * a.x + m.m11 * a.y + m.m21 * a.z + m.m31 * a.w,
            m.m02 * a.x + m.m12 * a.y + m.m22 * a.z + m.m32 * a.w,
            m.m03 * a.x + m.m13 * a.y + m.m23 * a.z + m.m33 * a.w
        ); return (v);
    }

    /* Boolean expressions */

    inline bool operator == (vec4 a, vec4 b) {
        return (fabsf(a.x - b.x) < 1e-6f &&
                fabsf(a.y - b.y) < 1e-6f &&
                fabsf(a.z - b.z) < 1e-6f &&
                fabsf(a.w - b.w) < 1e-6f);
    }


    inline bool operator != (vec4 a, vec4 b) {
        return (!(a == b));
    }


    inline bool operator > (vec4 a, vec4 b) {
        return (a.x > b.x ||
                a.y > b.y ||
                a.z > b.z ||
                a.w > b.w);
    }


    inline bool operator >= (vec4 a, vec4 b) {
        return (a.x >= b.x ||
                a.y >= b.y ||
                a.z >= b.z ||
                a.w >= b.w);
    }


    inline bool operator < (vec4 a, vec4 b) {
        return (a.x < b.x ||
                a.y < b.y ||
                a.z < b.z ||
                a.w < b.w);
    }


    inline bool operator <= (vec4 a, vec4 b) {
    return (a.x <= b.x ||
            a.y <= b.y ||
            a.z <= b.z ||
            a.w <= b.w);
    }

    /* Math operations */

    inline vec4 &operator += (vec4 &a, vec4 b) {
        a = a + b;
        return (a);
    }


    inline vec4 &operator -= (vec4 &a, vec4 b) {
        a = a - b;
        return (a);
    }


    inline vec4 &operator *= (vec4 &a, vec4 b) {
        a = a * b;
        return (a);
    }


    inline vec4 &operator /= (vec4 &a, vec4 b) {
        a = a / b;
        return (a);
    }


    inline vec4 &operator %= (vec4 &a, vec4 b) {
        a = a % b;
        return (a);
    }


    inline vec4 &operator += (vec4 &a, float f) {
        a = a + f;
        return (a);
    }


    inline vec4 &operator -= (vec4 &a, float f) {
        a = a - f;
        return (a);
    }


    inline vec4 &operator *= (vec4 &a, float f) {
        a = a * f;
        return (a);
    }


    inline vec4 &operator /= (vec4 &a, float f) {
        a = a / f;
        return (a);
    }


    inline vec4 &operator %= (vec4 &a, float f) {
        a = a % f;
        return (a);
    }

    /* Properties */

    template <>
    vec4 init<vec4>(float x) {
        vec4 v;
        v.x = x;
        v.y = 0.0f;
        v.z = 0.0f;
        v.w = 0.0f;
        return (v);
    }


    template <>
    vec4 init<vec4>(float x, float y) {
        vec4 v;
        v.x = x;
        v.y = y;
        v.z = 0.0f;
        v.w = 0.0f;
        return (v);
    }


    template <>
    vec4 init<vec4>(float x, float y, float z) {
        vec4 v;
        v.x = x;
        v.y = y;
        v.z = z;
        v.w = 0.0f;
        return (v);
    }


    template <>
    vec4 init<vec4>(float x, float y, float z, float w) {
        vec4 v;
        v.x = x;
        v.y = y;
        v.z = z;
        v.w = w;
        return (v);
    }

    /* Distance operations */

    template <>
    float ln<vec4>(vec4 a) {
        return (sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w));
    }


    template <>
    float lnsq<vec4>(vec4 a) {
        return (a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
    }


    template <>
    float dst<vec4>(vec4 a, vec4 b) {
        return (sqrtf((a.x - b.x) * (a.x - b.x) +
                      (a.y - b.y) * (a.y - b.y) +
                      (a.z - b.z) * (a.z - b.z) +
                      (a.w - b.w) * (a.w - b.w)));
    }


    template <>
    float dstsq<vec4>(vec4 a, vec4 b) {
        return ((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y) +
                (a.z - b.z) * (a.z - b.z) +
                (a.w - b.w) * (a.w - b.w));
    }

    /* Unary arithmetics */

    template <>
    float dot<vec4>(vec4 a, vec4 b) {
        return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
    }


    template <>
    vec4 cross<vec4>(vec4 a, vec4 b) {
        vec4 v = alg::init<vec4>(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x,
            a.x * b.y - a.y * b.x
        ); return (v);
    }


    template <>
    vec4 norm<vec4>(vec4 a) {
        float ln = alg::ln<vec4>(a);
        if (ln != 0.0f) {
            a.x *= 1.0f / ln;
            a.y *= 1.0f / ln;
            a.z *= 1.0f / ln;
            a.w *= 1.0f / ln;
        }
        
        return (a);
    }


    template <>
    vec4 neg<vec4>(vec4 a) {
        vec4 v = alg::init<vec4>(
            -a.x,
            -a.y,
            -a.z,
            -a.w
        ); return (v);
    }


    template <>
    vec4 abs<vec4>(vec4 a) {
        vec4 v = alg::init<vec4>(
            fabsf(a.x),
            fabsf(a.y),
            fabsf(a.z),
            fabsf(a.w)
        ); return (v);
    }


    template <>
    vec4 sign<vec4>(vec4 a) {
        vec4 v = alg::init<vec4>(
            a.x > 0.0f ? 1.0f : (a.x < 0.0f ? -1.0f : 0.0f),
            a.y > 0.0f ? 1.0f : (a.y < 0.0f ? -1.0f : 0.0f),
            a.z > 0.0f ? 1.0f : (a.z < 0.0f ? -1.0f : 0.0f),
            a.w > 0.0f ? 1.0f : (a.w < 0.0f ? -1.0f : 0.0f)
        ); return (v);
    }


    template <>
    vec4 sqrt<vec4>(vec4 a) {
        vec4 v = alg::init<vec4>(
            sqrtf(a.x),
            sqrtf(a.y),
            sqrtf(a.z),
            sqrtf(a.w)
        ); return (v);
    }


    template <>
    vec4 pow<vec4>(vec4 a, float f) {
        vec4 v = alg::init<vec4>(
            powf(a.x, f),
            powf(a.y, f),
            powf(a.z, f),
            powf(a.w, f)
        ); return (v);
    }


    template <>
    vec4 fract<vec4>(vec4 a) {
        vec4 v = alg::init<vec4>(
            fract(a.x),
            fract(a.y),
            fract(a.z),
            fract(a.w)
        ); return (v);
    }


    template <>
    vec4 floor<vec4>(vec4 a) {
        vec4 v = alg::init<vec4>(
            floorf(a.x),
            floorf(a.y),
            floorf(a.z),
            floorf(a.w)
        ); return (v);
    }


    template <>
    vec4 ceil<vec4>(vec4 a) {
        vec4 v = alg::init<vec4>(
            ceilf(a.x),
            ceilf(a.y),
            ceilf(a.z),
            ceilf(a.w)
        ); return (v);
    }


    template <>
    vec4 round<vec4>(vec4 a) {
        vec4 v = alg::init<vec4>(
            roundf(a.x),
            roundf(a.y),
            roundf(a.z),
            roundf(a.w)
        ); return (v);
    }

    /* Constraints */

    template <>
    vec4 min<vec4>(vec4 a, vec4 b) {
        vec4 v = alg::init<vec4>(
            min(a.x, b.x),
            min(a.y, b.y),
            min(a.z, b.z),
            min(a.w, b.w)
        ); return (v);
    }


    template <>
    vec4 minf<vec4>(vec4 a, float f) {
        vec4 v = alg::init<vec4>(
            min(a.x, f),
            min(a.y, f),
            min(a.z, f),
            min(a.w, f)
        ); return (v);
    }


    template <>
    vec4 max<vec4>(vec4 a, vec4 b) {
        vec4 v = alg::init<vec4>(
            max(a.x, b.x),
            max(a.y, b.y),
            max(a.z, b.z),
            max(a.w, b.w)
        ); return (v);
    }


    template <>
    vec4 maxf<vec4>(vec4 a, float f) {
        vec4 v = alg::init<vec4>(
            max(a.x, f),
            max(a.y, f),
            max(a.z, f),
            max(a.w, f)
        ); return (v);
    }


    template <>
    vec4 clamp<vec4>(vec4 a, vec4 lo, vec4 hi) {
        vec4 v = alg::init<vec4>(
            clamp(a.x, lo.x, hi.x),
            clamp(a.y, lo.y, hi.y),
            clamp(a.z, lo.z, hi.z),
            clamp(a.w, lo.w, hi.w)
        ); return (v);
    }


    template <>
    vec4 clampf<vec4>(vec4 a, float lo, float hi) {
        vec4 v = alg::init<vec4>(
            clamp(a.x, lo, hi),
            clamp(a.y, lo, hi),
            clamp(a.z, lo, hi),
            clamp(a.w, lo, hi)
        ); return (v);
    }

    /* Interpolation */

    template <>
    vec4 lerp<vec4>(vec4 a, vec4 b, float t) {
        vec4 v = alg::init<vec4>(
            lerp(a.x, b.x, t),
            lerp(a.y, b.y, t),
            lerp(a.z, b.z, t),
            lerp(a.w, b.w, t)
        ); return (v);
    }


    template <>
    vec4 step<vec4>(vec4 a, vec4 x) {
        vec4 v = alg::init<vec4>(
            step(a.x, x.x),
            step(a.y, x.y),
            step(a.z, x.z),
            step(a.w, x.w)
        ); return (v);
    }


    template <>
    vec4 smoothstep<vec4>(vec4 e0, vec4 e1, vec4 x) {
        vec4 v = alg::init<vec4>(
            smoothstep(e0.x, e1.x, x.x),
            smoothstep(e0.y, e1.y, x.y),
            smoothstep(e0.z, e1.z, x.z),
            smoothstep(e0.w, e1.w, x.w)
        ); return (v);
    }

    /* Geometric operations */

    template <>
    vec4 reflect<vec4>(vec4 a, vec4 n) {
        float d = alg::dot<vec4>(a, n);
        vec4  v = alg::init<vec4>(
            a.x - 2.0f * d * n.x,
            a.y - 2.0f * d * n.y,
            a.z - 2.0f * d * n.z,
            a.w - 2.0f * d * n.w
        ); return (v);
    }


    template <>
    vec4 refract<vec4>(vec4 a, vec4 n, float eta) {
        float d0 = alg::dot<vec4>(a, n);
        float d1 = 1.0f - eta * eta * (1.0 - d0 * d0);
        vec4  v = alg::init<vec4>(0.0);
        if (d1 >= 0) {
            d1 = sqrtf(d1);
            v.x = eta * a.x - (eta * d0 + d1) * n.x;
            v.y = eta * a.y - (eta * d0 + d1) * n.y;
            v.z = eta * a.z - (eta * d0 + d1) * n.z;
            v.w = eta * a.w - (eta * d0 + d1) * n.w;
        }

        return (v);
    }

};

# endif /* _vec4_impl_hpp_  */
#endif /* ALGEBRA_IMPLEMENTATION */
