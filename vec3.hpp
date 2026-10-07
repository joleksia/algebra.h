#if !defined (_vec3_hpp_)
# define _vec3_hpp_ 1
#
# include "./algebra-fwd.hpp"
# include "./type/vec3.hpp"
# include "./type/mat3.hpp"

namespace alg {

    /* Math operations */

    inline vec3 operator + (vec3, vec3);

    inline vec3 operator - (vec3, vec3);

    inline vec3 operator * (vec3, vec3);

    inline vec3 operator / (vec3, vec3);

    inline vec3 operator + (vec3, float);

    inline vec3 operator - (vec3, float);

    inline vec3 operator * (vec3, float);

    inline vec3 operator / (vec3, float);

    inline vec3 operator * (vec3, mat3);

    /* Boolean expressions */

    inline bool operator == (vec3, vec3);

    inline bool operator != (vec3, vec3);

    inline bool operator > (vec3, vec3);

    inline bool operator >= (vec3, vec3);

    inline bool operator < (vec3, vec3);

    inline bool operator <= (vec3, vec3);

    /* Math operations */

    inline vec3 &operator += (vec3 &, vec3);

    inline vec3 &operator -= (vec3 &, vec3);

    inline vec3 &operator *= (vec3 &, vec3);

    inline vec3 &operator /= (vec3 &, vec3);

    inline vec3 &operator += (vec3 &, float);

    inline vec3 &operator -= (vec3 &, float);

    inline vec3 &operator *= (vec3 &, float);

    inline vec3 &operator /= (vec3 &, float);

    /* Properties */

    template <>
	vec3 init<vec3>(float);

    template <>
	vec3 init<vec3>(float, float);

    template <>
	vec3 init<vec3>(float, float, float);

    /* Distance operations */

    template <>
	float ln<vec3>(vec3);

    template <>
	float lnsq<vec3>(vec3);

    template <>
	float dst<vec3>(vec3, vec3);

    template <>
	float dstsq<vec3>(vec3, vec3);

    /* Unary arithmetics */

    template <>
	float dot<vec3>(vec3, vec3);
    
    template <>
	vec3 cross<vec3>(vec3, vec3);

    template <>
	vec3 norm<vec3>(vec3);

    template <>
	vec3 neg<vec3>(vec3);

    template <>
	vec3 abs<vec3>(vec3);

    template <>
	vec3 sign<vec3>(vec3);

    template <>
	vec3 sqrt<vec3>(vec3);

    template <>
	vec3 pow<vec3>(vec3, float);

    template <>
	vec3 fract<vec3>(vec3);

    template <>
	vec3 floor<vec3>(vec3);

    template <>
	vec3 ceil<vec3>(vec3);

    template <>
	vec3 round<vec3>(vec3);

    /* Constraints */

    template <>
	vec3 min<vec3>(vec3, vec3);

    template <>
	vec3 minf<vec3>(vec3, float);

    template <>
	vec3 max<vec3>(vec3, vec3);

    template <>
	vec3 maxf<vec3>(vec3, float);

    template <>
	vec3 clamp<vec3>(vec3, vec3, vec3);

    template <>
	vec3 clampf<vec3>(vec3, float, float);

    /* Interpolation */

    template <>
	vec3 lerp<vec3>(vec3, vec3, float);

    template <>
	vec3 step<vec3>(vec3, vec3);

    template <>
	vec3 smoothstep<vec3>(vec3, vec3, vec3);

    /* Geometric operations */

    template <>
	vec3 perp<vec3>(vec3);

    template <>
	vec3 reflect<vec3>(vec3, vec3);

    template <>
	vec3 refract<vec3>(vec3, vec3, float);

    template <>
	float angle<vec3>(vec3, vec3);
    
    template <>
	vec3 rotate<vec3>(vec3, vec3, float);

};

#endif /* _vec3_hpp_ */
#
#if defined (ALGEBRA_IMPLEMENTATION)
# if !defined (_vec3_impl_hpp_)
#  define _vec3_impl_hpp_ 1
#
#  include <cmath>
#  include "utils.hpp"

namespace alg {

    /* Math operations */

    inline vec3 operator + (vec3 a, vec3 b) {
        vec3 v = alg::init<vec3>(
            a.x + b.x,
            a.y + b.y,
            a.z + b.z
        ); return (v);
    }


    inline vec3 operator - (vec3 a, vec3 b) {
        vec3 v = alg::init<vec3>(
            a.x - b.x,
            a.y - b.y,
            a.z - b.z
        ); return (v);
    }


    inline vec3 operator * (vec3 a, vec3 b) {
        vec3 v = alg::init<vec3>(
            a.x * b.x,
            a.y * b.y,
            a.z * b.z
        ); return (v);
    }


    inline vec3 operator / (vec3 a, vec3 b) {
        vec3 v = alg::init<vec3>(
            b.x != 0.0f ? a.x / b.x : 0.0f,
            b.y != 0.0f ? a.y / b.y : 0.0f,
            b.z != 0.0f ? a.z / b.z : 0.0f
        ); return (v);
    }


    inline vec3 operator % (vec3 a, vec3 b) {
        vec3 v = alg::init<vec3>(
            a.x - b.x * floorf(a.x / b.x),
            a.y - b.y * floorf(a.y / b.y),
            a.z - b.z * floorf(a.z / b.z)
        ); return (v);
    }


    inline vec3 operator + (vec3 a, float f) {
        vec3 v = alg::init<vec3>(
            a.x + f,
            a.y + f,
            a.z + f
        ); return (v);
    }


    inline vec3 operator - (vec3 a, float f) {
        vec3 v = alg::init<vec3>(
            a.x - f,
            a.y - f,
            a.z - f
        ); return (v);
    }


    inline vec3 operator * (vec3 a, float f) {
        vec3 v = alg::init<vec3>(
            a.x * f,
            a.y * f,
            a.z * f
        ); return (v);
    }


    inline vec3 operator / (vec3 a, float f) {
        vec3 v = alg::init<vec3>(
            f != 0.0f ? a.x / f : 0.0f,
            f != 0.0f ? a.y / f : 0.0f,
            f != 0.0f ? a.z / f : 0.0f
        ); return (v);
    }


    inline vec3 operator % (vec3 a, float f) {
        vec3 v = alg::init<vec3>(
            a.x - f * floorf(a.x / f),
            a.y - f * floorf(a.y / f),
            a.z - f * floorf(a.z / f)
        ); return (v);
    }


    inline vec3 operator * (vec3 a, mat3 m) {
        vec3 v = alg::init<vec3>(
            m.m00 * a.x + m.m10 * a.y + m.m20 * a.z,
            m.m01 * a.x + m.m11 * a.y + m.m21 * a.z,
            m.m02 * a.x + m.m12 * a.y + m.m22 * a.z
        ); return (v);
    }

    /* Boolean expressions */

    inline bool operator == (vec3 a, vec3 b) {
        return (fabsf(a.x - b.x) < 1e-6f &&
                fabsf(a.y - b.y) < 1e-6f &&
                fabsf(a.z - b.z) < 1e-6f);
    }


    inline bool operator != (vec3 a, vec3 b) {
        return (!(a == b));
    }


    inline bool operator > (vec3 a, vec3 b) {
        return (a.x > b.x ||
                a.y > b.y ||
                a.z > b.z);
    }


    inline bool operator >= (vec3 a, vec3 b) {
        return (a.x >= b.x ||
                a.y >= b.y ||
                a.z >= b.z);
    }


    inline bool operator < (vec3 a, vec3 b) {
        return (a.x < b.x ||
                a.y < b.y ||
                a.z < b.z);
    }


    inline bool operator <= (vec3 a, vec3 b) {
        return (a.x <= b.x ||
                a.y <= b.y ||
                a.z <= b.z);
    }

    /* Math operations */

    inline vec3 &operator += (vec3 &a, vec3 b) {
        a = a + b;
        return (a);
    }


    inline vec3 &operator -= (vec3 &a, vec3 b) {
        a = a - b;
        return (a);
    }


    inline vec3 &operator *= (vec3 &a, vec3 b) {
        a = a * b;
        return (a);
    }


    inline vec3 &operator /= (vec3 &a, vec3 b) {
        a = a / b;
        return (a);
    }


    inline vec3 &operator %= (vec3 &a, vec3 b) {
        a = a % b;
        return (a);
    }


    inline vec3 &operator += (vec3 &a, float f) {
        a = a + f;
        return (a);
    }


    inline vec3 &operator -= (vec3 &a, float f) {
        a = a - f;
        return (a);
    }


    inline vec3 &operator *= (vec3 &a, float f) {
        a = a * f;
        return (a);
    }


    inline vec3 &operator /= (vec3 &a, float f) {
        a = a / f;
        return (a);
    }


    inline vec3 &operator %= (vec3 &a, float f) {
        a = a % f;
        return (a);
    }

    /* Properties */

    template <>
	vec3 init<vec3>(float x) {
        vec3 v;
        v.x = x;
        v.y = 0.0f;
        v.z = 0.0f;
        return (v);
	}


    template <>
	vec3 init<vec3>(float x, float y) {
        vec3 v;
        v.x = x;
        v.y = y;
        v.z = 0.0f;
        return (v);
	}


    template <>
	vec3 init<vec3>(float x, float y, float z) {
        vec3 v;
        v.x = x;
        v.y = y;
        v.z = z;
        return (v);
	}

    /* Distance operations */

    template <>
	float ln<vec3>(vec3 a) {
        return (sqrtf(a.x * a.x + a.y * a.y + a.z * a.z));
	}


    template <>
	float lnsq<vec3>(vec3 a) {
        return (a.x * a.x + a.y * a.y + a.z * a.z);
	}


    template <>
	float dst<vec3>(vec3 a, vec3 b) {
        return (sqrtf((a.x - b.x) * (a.x - b.x) +
                      (a.y - b.y) * (a.y - b.y) +
                      (a.z - b.z) * (a.z - b.z)));
	}


    template <>
	float dstsq<vec3>(vec3 a, vec3 b) {
        return ((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y) +
                (a.z - b.z) * (a.z - b.z));
	}

    /* Unary arithmetics */

    template <>
	float dot<vec3>(vec3 a, vec3 b) {
        return (a.x * b.x + a.y * b.y + a.z * b.z);
	}


    template <>
	vec3 cross<vec3>(vec3 a, vec3 b) {
        vec3 v = alg::init<vec3>(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        ); return (v);
	}


    template <>
	vec3 norm<vec3>(vec3 a) {
        float ln = alg::ln<vec3>(a);
        if (ln != 0.0f) {
            a.x *= 1.0f / ln;
            a.y *= 1.0f / ln;
            a.z *= 1.0f / ln;
        }
        
        return (a);
	}


    template <>
	vec3 neg<vec3>(vec3 a) {
        vec3 v = alg::init<vec3>(
            -a.x,
            -a.y,
            -a.z
        ); return (v);
	}


    template <>
	vec3 abs<vec3>(vec3 a) {
        vec3 v = alg::init<vec3>(
            fabsf(a.x),
            fabsf(a.y),
            fabsf(a.z)
        ); return (v);
	}


    template <>
	vec3 sign<vec3>(vec3 a) {
        vec3 v = alg::init<vec3>(
            a.x > 0.0f ? 1.0f : (a.x < 0.0f ? -1.0f : 0.0f),
            a.y > 0.0f ? 1.0f : (a.y < 0.0f ? -1.0f : 0.0f),
            a.z > 0.0f ? 1.0f : (a.z < 0.0f ? -1.0f : 0.0f)
        ); return (v);
	}


    template <>
	vec3 sqrt<vec3>(vec3 a) {
        vec3 v = alg::init<vec3>(
            sqrtf(a.x),
            sqrtf(a.y),
            sqrtf(a.z)
        ); return (v);
	}


    template <>
	vec3 pow<vec3>(vec3 a, float f) {
        vec3 v = alg::init<vec3>(
            powf(a.x, f),
            powf(a.y, f),
            powf(a.z, f)
        ); return (v);
	}


    template <>
	vec3 fract<vec3>(vec3 a) {
        vec3 v = alg::init<vec3>(
            fract(a.x),
            fract(a.y),
            fract(a.z)
        ); return (v);
	}


    template <>
	vec3 floor<vec3>(vec3 a) {
        vec3 v = alg::init<vec3>(
            floorf(a.x),
            floorf(a.y),
            floorf(a.z)
        ); return (v);
	}


    template <>
	vec3 ceil<vec3>(vec3 a) {
        vec3 v = alg::init<vec3>(
            ceilf(a.x),
            ceilf(a.y),
            ceilf(a.z)
        ); return (v);
	}


    template <>
    vec3 round<vec3>(vec3 a) {
        vec3 v = alg::init<vec3>(
            roundf(a.x),
            roundf(a.y),
            roundf(a.z)
        ); return (v);
    }

    /* Constraints */

    template <>
    vec3 min<vec3>(vec3 a, vec3 b) {
        vec3 v = alg::init<vec3>(
            min(a.x, b.x),
            min(a.y, b.y),
            min(a.z, b.z)
        ); return (v);
    }


    template <>
    vec3 minf<vec3>(vec3 a, float f) {
        vec3 v = alg::init<vec3>(
            min(a.x, f),
            min(a.y, f),
            min(a.z, f)
        ); return (v);
    }


    template <>
    vec3 max<vec3>(vec3 a, vec3 b) {
        vec3 v = alg::init<vec3>(
            max(a.x, b.x),
            max(a.y, b.y),
            max(a.z, b.z)
        ); return (v);
    }


    template <>
    vec3 maxf<vec3>(vec3 a, float f) {
        vec3 v = alg::init<vec3>(
            max(a.x, f),
            max(a.y, f),
            max(a.z, f)
        ); return (v);
    }


    template <>
    vec3 clamp<vec3>(vec3 a, vec3 lo, vec3 hi) {
        vec3 v = alg::init<vec3>(
            clamp(a.x, lo.x, hi.x),
            clamp(a.y, lo.y, hi.y),
            clamp(a.z, lo.z, hi.z)
        ); return (v);
    }


    template <>
    vec3 clampf<vec3>(vec3 a, float lo, float hi) {
        vec3 v = alg::init<vec3>(
            clamp(a.x, lo, hi),
            clamp(a.y, lo, hi),
            clamp(a.z, lo, hi)
        ); return (v);
    }

    /* Interpolation */

    template <>
    vec3 lerp<vec3>(vec3 a, vec3 b, float t) {
        vec3 v = alg::init<vec3>(
            lerp(a.x, b.x, t),
            lerp(a.y, b.y, t),
            lerp(a.z, b.z, t)
        ); return (v);
    }


    template <>
    vec3 step<vec3>(vec3 a, vec3 x) {
        vec3 v = alg::init<vec3>(
            step(a.x, x.x),
            step(a.y, x.y),
            step(a.z, x.z)
        ); return (v);
    }


    template <>
    vec3 smoothstep<vec3>(vec3 e0, vec3 e1, vec3 x) {
        vec3 v = alg::init<vec3>(
            smoothstep(e0.x, e1.x, x.x),
            smoothstep(e0.y, e1.y, x.y),
            smoothstep(e0.z, e1.z, x.z)
        ); return (v);
    }

    /* Geometric operations */

    template <>
    vec3 reflect<vec3>(vec3 a, vec3 n) {
        float d = alg::dot<vec3>(a, n);
        vec3  v = alg::init<vec3>(
            a.x - 2.0f * d * n.x,
            a.y - 2.0f * d * n.y,
            a.z - 2.0f * d * n.z
        ); return (v);
    }


    template <>
    vec3 refract<vec3>(vec3 a, vec3 n, float eta) {
        float d0 = alg::dot<vec3>(a, n);
        float d1 = 1.0f - eta * eta * (1.0 - d0 * d0);
        vec3  v = alg::init<vec3>(0.0);
        if (d1 >= 0) {
            d1 = sqrtf(d1);
            v.x = eta * a.x - (eta * d0 + d1) * n.x;
            v.y = eta * a.y - (eta * d0 + d1) * n.y;
            v.z = eta * a.z - (eta * d0 + d1) * n.z;
        }

        return (v);
    }

};

# endif /* _vec3_impl_hpp_  */
#endif /* ALGEBRA_IMPLEMENTATION */
