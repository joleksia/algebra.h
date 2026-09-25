#if !defined (_mat2_hpp_)
# define _mat2_hpp_ 1
#
# include "./algebra-fwd.hpp"
# include "./type/vec2.hpp"
# include "./type/mat2.hpp"

namespace alg {
    
    /* Math operations */

    inline mat2 operator + (mat2, mat2);

    inline mat2 operator - (mat2, mat2);

    inline mat2 operator * (mat2, mat2);

    inline mat2 operator * (mat2, float);

    inline vec2 operator * (mat2, vec2);

    /* Boolean expressions */

    inline bool operator == (mat2, mat2);

    inline bool operator != (mat2, mat2);
    
    /* Math operations */

    inline mat2 &operator += (mat2 &, mat2);

    inline mat2 &operator -= (mat2 &, mat2);

    inline mat2 &operator *= (mat2 &, mat2);
    
    /* Properties */

    template <>
	mat2 init<mat2>(float);

    /* Unary operations */
    
    template <>
	mat2 neg<mat2>(mat2);
    
    template <>
	mat2 transpose<mat2>(mat2);
    
    template <>
	mat2 inv<mat2>(mat2);

    /* Scalar operations */
    
    template <>
	float det<mat2>(mat2);
    
    template <>
	float trace<mat2>(mat2);
    
    template <>
	mat2 rotate<mat2>(float);
    
    template <>
	mat2 scale<mat2>(vec2);

};

#endif /* _mat2_hpp_ */
#
#if defined (ALGEBRA_IMPLEMENTATION)
# if !defined (_mat2_impl_hpp_)
#  define _mat2_impl_hpp_ 1
#
#  include <cmath>
#  include "vec2.hpp"

namespace alg {

    /* Math operations */

    inline mat2 operator + (mat2 a, mat2 b) {
        mat2 m = alg::init<mat2>(0.0);
        m.m00 = a.m00 + b.m00; m.m01 = a.m01 + b.m01;
        m.m10 = a.m10 + b.m10; m.m11 = a.m11 + b.m11;
        return (m);
    }


    inline mat2 operator - (mat2 a, mat2 b) {
        mat2 m = alg::init<mat2>(0.0);
        m.m00 = a.m00 - b.m00; m.m01 = a.m01 - b.m01;
        m.m10 = a.m10 - b.m10; m.m11 = a.m11 - b.m11;
        return (m);
    }


    inline mat2 operator * (mat2 a, mat2 b) {
        mat2 m = alg::init<mat2>(0.0);
        m.m00 = a.m00 * b.m00 + a.m10 * b.m01; m.m01 = a.m01 * b.m00 + a.m11 * b.m01;
        m.m10 = a.m00 * b.m10 + a.m10 * b.m11; m.m11 = a.m01 * b.m10 + a.m11 * b.m11;
        return (m);
    }


    inline mat2 operator * (mat2 a, float f) {
        mat2 m = alg::init<mat2>(0.0);
        m.m00 = a.m00 * f; m.m01 = a.m01 * f;
        m.m10 = a.m10 * f; m.m11 = a.m11 * f;
        return (m);
    }


    inline vec2 operator * (mat2 a, vec2 b) {
        vec2 v = alg::init<vec2>(
            a.m00 * b.x + a.m10 * b.y,
            a.m01 * b.x + a.m11 * b.y
        ); return (v);
    }

    /* Boolean expressions */

    inline bool operator == (mat2 a, mat2 b) {
        return (fabsf(a.m00 - b.m00) < 1e-6f && fabsf(a.m01 - b.m01) < 1e-6f &&
                fabsf(a.m10 - b.m10) < 1e-6f && fabsf(a.m11 - b.m11) < 1e-6f);
    }


    inline bool operator != (mat2 a, mat2 b) {
        return (!(a == b));
    }

    /* Math operations */

    inline mat2 &operator += (mat2 &a, mat2 b) {
        a = a + b;
        return (a);
    }


    inline mat2 &operator -= (mat2 &a, mat2 b) {
        a = a - b;
        return (a);
    }


    inline mat2 &operator *= (mat2 &a, mat2 b) {
        a = a * b;
        return (a);
    }
    
    /* Properties */

    template <>
	mat2 init<mat2>(float s) {
        mat2 m;
        m.m00 = s;   m.m01 = 0.0;
        m.m10 = 0.0; m.m11 = s;
        return (m);
    }
    
    /* Unary operations */
   
    template <>
	mat2 neg<mat2>(mat2 a) {
        mat2 m = alg::init<mat2>(0.0);
        m.m00 = -a.m00; m.m01 = -a.m01;
        m.m10 = -a.m10; m.m11 = -a.m11;
        return (m);
	}
   

    template <>
	mat2 transpose<mat2>(mat2 a) {
        mat2 m = alg::init<mat2>(0.0);
        m.m00 = a.m00; m.m01 = a.m10;
        m.m10 = a.m01; m.m11 = a.m11;
        return (m);
	}
   

    template <>
	mat2 inv<mat2>(mat2 a) {
        float det = alg::det<mat2>(a);
        if (det == 0.0f) {
            return (alg::init<mat2>(0.0));
        } else {
            det = 1.0f / det;
        }

        mat2 m = alg::init<mat2>(0.0);
        m.m00 =  a.m11 * det; m.m01 = -a.m01 * det;
        m.m10 = -a.m10 * det; m.m11 =  a.m00 * det;
        return (m);
	}
   
    /* Scalar operations */

    template <>
	float det<mat2>(mat2 m) {
        return (m.m00 * m.m11 - m.m10 * m.m01);
	}
   

    template <>
	float trace<mat2>(mat2 m) {
        return (m.m00 + m.m11);
	}


    template <>
	mat2 rotate<mat2>(float angle) {
        float c = cosf(angle);
        float s = sinf(angle);

        mat2 m = alg::init<mat2>(0.0);
        m.m00 =  c; m.m01 = s;
        m.m10 = -s; m.m11 = c;
        return (m);
	}
    

    template <>
	mat2 scale<mat2>(vec2 s) {
        mat2 m = alg::init<mat2>(0.0);
        m.m00 = s.x;  m.m01 = 0.0f;
        m.m10 = 0.0f; m.m11 = s.y;
        return (m);
	}

};

# endif /* _mat2_impl_hpp_ */
#endif /* ALGEBRA_IMPLEMENTATION */
