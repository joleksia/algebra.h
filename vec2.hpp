#if !defined (_vec2_hpp_)
# define _vec2_hpp_ 1
#
# include "./algebra-fwd.hpp"
# include "./type/vec2.hpp"
# include "./type/mat2.hpp"

namespace alg {

    /* Math operations */

    inline vec2 operator + (vec2, vec2);

    inline vec2 operator - (vec2, vec2);

    inline vec2 operator * (vec2, vec2);

    inline vec2 operator / (vec2, vec2);

    inline vec2 operator % (vec2, vec2);

    inline vec2 operator + (vec2, float);

    inline vec2 operator - (vec2, float);

    inline vec2 operator * (vec2, float);

    inline vec2 operator / (vec2, float);

    inline vec2 operator % (vec2, float);

    inline vec2 operator * (vec2, mat2);

    /* Boolean expressions */

    inline bool operator == (vec2, vec2);

    inline bool operator != (vec2, vec2);

    inline bool operator > (vec2, vec2);

    inline bool operator >= (vec2, vec2);

    inline bool operator < (vec2, vec2);

    inline bool operator <= (vec2, vec2);
    
    /* Math operations */

    inline vec2 &operator += (vec2 &, vec2);

    inline vec2 &operator -= (vec2 &, vec2);

    inline vec2 &operator *= (vec2 &, vec2);

    inline vec2 &operator /= (vec2 &, vec2);

    inline vec2 &operator %= (vec2 &, vec2);

    inline vec2 &operator += (vec2 &, float);

    inline vec2 &operator -= (vec2 &, float);

    inline vec2 &operator *= (vec2 &, float);

    inline vec2 &operator /= (vec2 &, float);

    inline vec2 &operator %= (vec2 &, float);

    /* Properties */

    template <>
	vec2 init<vec2>(float);

    template <>
	vec2 init<vec2>(float, float);
    
    /* Distance Operations */

    template <>
	float ln<vec2>(vec2);

    template <>
	float lnsq<vec2>(vec2);

    template <>
	float dst<vec2>(vec2, vec2);

    template <>
	float dstsq<vec2>(vec2, vec2);

    /* Unary Arithmetics */

    template <>
	float dot<vec2>(vec2, vec2);

    template <>
	float det(vec2, vec2);

    template <>
	vec2 norm<vec2>(vec2);

    template <>
	vec2 neg<vec2>(vec2);

    template <>
	vec2 abs<vec2>(vec2);

    template <>
	vec2 sign<vec2>(vec2);

    template <>
	vec2 sqrt<vec2>(vec2);

    template <>
	vec2 pow<vec2>(vec2, float);

    template <>
	vec2 fract<vec2>(vec2);

    template <>
	vec2 floor<vec2>(vec2);

    template <>
	vec2 ceil<vec2>(vec2);

    template <>
	vec2 round<vec2>(vec2);

    /* Constraints */

    template <>
	vec2 min<vec2>(vec2, vec2);

    template <>
	vec2 minf<vec2>(vec2, float);

    template <>
	vec2 max<vec2>(vec2, vec2);

    template <>
	vec2 maxf<vec2>(vec2, float);

    template <>
	vec2 clamp<vec2>(vec2, vec2, vec2);

    template <>
	vec2 clampf<vec2>(vec2, float, float);

    /* Interpolation */

    template <>
	vec2 lerp<vec2>(vec2, vec2, float);

    template <>
	vec2 step<vec2>(vec2, vec2);

    template <>
	vec2 smoothstep<vec2>(vec2, vec2, vec2);

    /* Geometric operations */

    template <>
	vec2 perp<vec2>(vec2);

    template <>
	vec2 reflect<vec2>(vec2, vec2);

    template <>
	vec2 refract<vec2>(vec2, vec2, float);

    template <>
	vec2 rotate<vec2>(vec2, float);

    template <>
	float angle<vec2>(vec2, vec2);

};

#endif /* _vec2_hpp_ */
#
#if defined (ALGEBRA_IMPLEMENTATION)
# if !defined (_vec2_impl_hpp_)
#  define _vec2_impl_hpp_ 1
#
#  include <cmath>
#  include "utils.hpp"

namespace alg {

    /* Math operations */

    inline vec2 operator + (vec2 a, vec2 b) {
        vec2 v = alg::init<vec2>(
            a.x + b.x,
            a.y + b.y
        ); return (v);
    }


    inline vec2 operator - (vec2 a, vec2 b) {
        vec2 v = alg::init<vec2>(
            a.x - b.x,
            a.y - b.y
        ); return (v);
    }


    inline vec2 operator * (vec2 a, vec2 b) {
        vec2 v = alg::init<vec2>(
            a.x * b.x,
            a.y * b.y
        ); return (v);
    }


    inline vec2 operator / (vec2 a, vec2 b) {
        vec2 v = alg::init<vec2>(
            b.x != 0.0f ? a.x / b.x : 0.0f,
            b.y != 0.0f ? a.y / b.y : 0.0f
        ); return (v);
    }


    inline vec2 operator % (vec2 a, vec2 b) {
        vec2 v = alg::init<vec2>(
            a.x - b.x * floorf(a.x / b.x),
            a.y - b.y * floorf(a.y / b.y)
        ); return (v);
    }


    inline vec2 operator + (vec2 a, float f) {
        vec2 v = alg::init<vec2>(
            a.x + f,
            a.y + f
        ); return (v);
    }


    inline vec2 operator - (vec2 a, float f) {
        vec2 v = alg::init<vec2>(
            a.x - f,
            a.y - f
        ); return (v);
    }


    inline vec2 operator * (vec2 a, float f) {
        vec2 v = alg::init<vec2>(
            a.x * f,
            a.y * f
        ); return (v);
    }


    inline vec2 operator / (vec2 a, float f) {
        vec2 v = alg::init<vec2>(
            f != 0.0f ? a.x / f : 0.0f,
            f != 0.0f ? a.y / f : 0.0f
        ); return (v);
    }


    inline vec2 operator % (vec2 a, float f) {
        vec2 v = alg::init<vec2>(
            a.x - f * floorf(a.x / f),
            a.y - f * floorf(a.y / f)
        ); return (v);
    }


    inline vec2 operator * (vec2 a, mat2 m) {
        vec2 v = alg::init<vec2>(
            m.m00 * a.x + m.m10 * a.y,
            m.m01 * a.x + m.m11 * a.y
        ); return (v);
    }

    /* Boolean expressions */

    inline bool operator == (vec2 a, vec2 b) {
        return (fabsf(a.x - b.x) < 1e-6f &&
                fabsf(a.y - b.y) < 1e-6f);
    }


    inline bool operator != (vec2 a, vec2 b) {
        return (!(a == b));
    }


    inline bool operator > (vec2 a, vec2 b) {
        return (a.x > b.x ||
                a.y > b.y);
    }


    inline bool operator >= (vec2 a, vec2 b) {
        return (a.x >= b.x ||
                a.y >= b.y);
    }


    inline bool operator < (vec2 a, vec2 b) {
        return (a.x < b.x ||
                a.y < b.y);
    }


    inline bool operator <= (vec2 a, vec2 b) {
        return (a.x <= b.x ||
                a.y <= b.y);
    }

    /* Math operations */

    inline vec2 &operator += (vec2 &a, vec2 b) {
        a = a + b;
        return (a);
    }


    inline vec2 &operator -= (vec2 &a, vec2 b) {
        a = a - b;
        return (a);
    }


    inline vec2 &operator *= (vec2 &a, vec2 b) {
        a = a * b;
        return (a);
    }


    inline vec2 &operator /= (vec2 &a, vec2 b) {
        a = a / b;
        return (a);
    }


    inline vec2 &operator %= (vec2 &a, vec2 b) {
        a = a % b;
        return (a);
    }


    inline vec2 &operator += (vec2 &a, float f) {
        a = a + f;
        return (a);
    }


    inline vec2 &operator -= (vec2 &a, float f) {
        a = a - f;
        return (a);
    }


    inline vec2 &operator *= (vec2 &a, float f) {
        a = a * f;
        return (a);
    }


    inline vec2 &operator /= (vec2 &a, float f) {
        a = a / f;
        return (a);
    }


    inline vec2 &operator %= (vec2 &a, float f) {
        a = a % f;
        return (a);
    }

    /* Properties */

    template <>
	vec2 init<vec2>(float x) {
        vec2 v;
        v.x = x;
        v.y = 0.0f;
        return (v);
	}


    template <>
	vec2 init<vec2>(float x, float y) {
        vec2 v;
        v.x = x;
        v.y = y;
        return (v);
	}

    /* Distance Operations */

    template <>
	float ln<vec2>(vec2 a) {
        return (sqrtf(a.x * a.x + a.y * a.y));
	}


    template <>
	float lnsq<vec2>(vec2 a) {
        return (a.x * a.x + a.y * a.y);
	}


    template <>
	float dst<vec2>(vec2 a, vec2 b) {
        return (sqrtf((a.x - b.x) * (a.x - b.x) +
                      (a.y - b.y) * (a.y - b.y)));
	}


    template <>
	float dstsq<vec2>(vec2 a, vec2 b) {
        return ((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
	}

    /* Unary Arithmetics */

    template <>
	float dot<vec2>(vec2 a, vec2 b) {
        return (a.x * b.x + a.y * b.y);
	}


    template <>
	float det(vec2 a, vec2 b) {
        return (a.x * b.y - a.y * b.x);
	}


    template <>
	vec2 norm<vec2>(vec2 a) {
        float ln = alg::ln<vec2>(a);
        if (ln != 0.0f) {
            a.x *= 1.0f / ln;
            a.y *= 1.0f / ln;
        }
        return (a);
	}


    template <>
	vec2 neg<vec2>(vec2 a) {
        vec2 v = alg::init<vec2>(-a.x, -a.y);
        return (v);
	}


    template <>
	vec2 abs<vec2>(vec2 a) {
        vec2 v = alg::init<vec2>(
            fabsf(a.x),
            fabsf(a.y)
        ); return (v);
	}


    template <>
	vec2 sign<vec2>(vec2 a) {
        vec2 v = alg::init<vec2>(
            a.x > 0.0f ? 1.0f : (a.x < 0.0f ? -1.0f : 0.0f),
            a.y > 0.0f ? 1.0f : (a.y < 0.0f ? -1.0f : 0.0f)
        ); return (v);
	}


    template <>
	vec2 sqrt<vec2>(vec2 a) {
        vec2 v = alg::init<vec2>(
            sqrtf(a.x),
            sqrtf(a.y)
        ); return (v);
	}


    template <>
	vec2 pow<vec2>(vec2 a, float f) {
        vec2 v = alg::init<vec2>(
            powf(a.x, f),
            powf(a.y, f)
        ); return (v);
	}


    template <>
	vec2 fract<vec2>(vec2 a) {
        vec2 v = alg::init<vec2>(
            alg_fract(a.x),
            alg_fract(a.y)
        ); return (v);
	}


    template <>
	vec2 floor<vec2>(vec2 a) {
        vec2 v = alg::init<vec2>(
            floorf(a.x),
            floorf(a.y)
        ); return (v);
	}


    template <>
	vec2 ceil<vec2>(vec2 a) {
        vec2 v = alg::init<vec2>(
            ceilf(a.x),
            ceilf(a.y)
        ); return (v);
	}


    template <>
	vec2 round<vec2>(vec2 a) {
        vec2 v = alg::init<vec2>(
            roundf(a.x),
            roundf(a.y)
        ); return (v);
	}

    /* Constraints */

    template <>
	vec2 min<vec2>(vec2 a, vec2 b) {
        vec2 v = alg::init<vec2>(
            alg_min(a.x, b.x),
            alg_min(a.y, b.y)
        ); return (v);
	}


    template <>
	vec2 minf<vec2>(vec2 a, float f) {
        vec2 v = alg::init<vec2>(
            alg_min(a.x, f),
            alg_min(a.y, f)
        ); return (v);
	}


    template <>
	vec2 max<vec2>(vec2 a, vec2 b) {
        vec2 v = alg::init<vec2>(
            alg_max(a.x, b.x),
            alg_max(a.y, b.y)
        ); return (v);
	}


    template <>
	vec2 maxf<vec2>(vec2 a, float f) {
        vec2 v = alg::init<vec2>(
            alg_max(a.x, f),
            alg_max(a.y, f)
        ); return (v);
	}


    template <>
	vec2 clamp<vec2>(vec2 a, vec2 lo, vec2 hi) {
        vec2 v = alg::init<vec2>(
            alg_clamp(a.x, lo.x, hi.x),
            alg_clamp(a.y, lo.y, hi.y)
        ); return (v);
	}


    template <>
	vec2 clampf<vec2>(vec2 a, float lo, float hi) {
        vec2 v = alg::init<vec2>(
            alg_clamp(a.x, lo, hi),
            alg_clamp(a.y, lo, hi)
        ); return (v);
	}

    /* Interpolation */

    template <>
	vec2 lerp<vec2>(vec2 a, vec2 b, float t) {
        vec2 v = alg::init<vec2>(
            alg_lerp(a.x, b.x, t),
            alg_lerp(a.y, b.y, t)
        ); return (v);
	}


    template <>
	vec2 step<vec2>(vec2 a, vec2 x) {
        vec2 v = alg::init<vec2>(
            alg_step(a.x, x.x),
            alg_step(a.y, x.y)
        ); return (v);
	}


    template <>
	vec2 smoothstep<vec2>(vec2 e0, vec2 e1, vec2 x) {
        vec2 v = alg::init<vec2>(
            alg_smoothstep(e0.x, e1.x, x.x),
            alg_smoothstep(e0.y, e1.y, x.y)
        ); return (v);
	}

    /* Geometric operations */

    template <>
	vec2 perp<vec2>(vec2 a) {
        vec2 v = alg::init<vec2>(-a.y, a.x);
        return (v);
	}


    template <>
	vec2 reflect<vec2>(vec2 a, vec2 n) {
        float dot = alg::dot<vec2>(a, n);
        vec2  v = alg::init<vec2>(
            a.x - 2.0f * dot * n.x,
            a.y - 2.0f * dot * n.y
        ); return (v);
	}


    template <>
	vec2 refract<vec2>(vec2 a, vec2 n, float eta) {
        float dot = alg::dot<vec2>(a, n);
        float d = 1.0f - eta * eta * (1.0 - dot * dot);
        vec2  v = alg::init<vec2>(0.0);
        if (d >= 0) {
            d = sqrtf(d);
            v.x = eta * a.x - (eta * dot + d) * n.x;
            v.y = eta * a.y - (eta * dot + d) * n.y;
        }

        return (v);
	}


    template <>
	vec2 rotate<vec2>(vec2 a, float f) {
        float s = sinf(f);
        float c = cosf(f);
        vec2  v = alg::init<vec2>(
            c * a.x - s * a.y,
            s * a.x + c * a.y
        ); return (v);
	}


    template <>
	float angle<vec2>(vec2 a, vec2 b) {
        float dot = alg::dot<vec2>(a, b);
        float det = alg::det<vec2>(a, b);
        return (atan2f(det, dot));
	}

};

# endif /* _vec2_impl_hpp_ */
#endif /* ALGEBRA_IMPLEMENTATION */
