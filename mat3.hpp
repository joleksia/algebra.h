#if !defined (_mat3_hpp_)
# define _mat3_hpp_ 1
#
# include "./algebra-fwd.hpp"
# include "./type/vec3.hpp"
# include "./type/mat3.hpp"

namespace alg {
    
    /* Math operations */

    inline mat3 operator + (mat3, mat3);

    inline mat3 operator - (mat3, mat3);

    inline mat3 operator * (mat3, mat3);

    inline mat3 operator * (mat3, float);

    inline vec3 operator * (mat3, vec3);

    /* Boolean expressions */

    inline bool operator == (mat3, mat3);

    inline bool operator != (mat3, mat3);
    
    /* Math operations */

    inline mat3 &operator += (mat3 &, mat3);

    inline mat3 &operator -= (mat3 &, mat3);

    inline mat3 &operator *= (mat3 &, mat3);
    
    /* Properties */

    template <>
	mat3 init<mat3>(float);

    /* Unary operations */
    
    template <>
	mat3 neg<mat3>(mat3);
    
    template <>
	mat3 transpose<mat3>(mat3);
    
    template <>
	mat3 inv<mat3>(mat3);

    /* Scalar operations */
    
    template <>
	float det<mat3>(mat3);
    
    template <>
	float trace<mat3>(mat3);

    template <>
	mat3 rotatex<mat3>(float);
    
    template <>
	mat3 rotatey<mat3>(float);
    
    template <>
	mat3 rotatez<mat3>(float);
    
    template <>
	mat3 rotate<mat3>(vec3, float);
    
    template <>
	mat3 scale<mat3>(vec3);

};

#endif /* _mat3_hpp_ */
#
#if defined (ALGEBRA_IMPLEMENTATION)
# if !defined (_mat3_impl_hpp_)
#  define _mat3_impl_hpp_ 1
#
#  include <cmath>
#  include "vec3.hpp"

namespace alg {
    
    /* Math operations */

    inline mat3 operator + (mat3 a, mat3 b) {
        mat3 m = alg::init<mat3>(0.0);
        m.m00 = a.m00 + b.m00; m.m01 = a.m01 + b.m01; m.m02 = a.m02 + b.m02;
        m.m10 = a.m10 + b.m10; m.m11 = a.m11 + b.m11; m.m12 = a.m12 + b.m12;
        m.m20 = a.m20 + b.m20; m.m21 = a.m21 + b.m21; m.m22 = a.m22 + b.m22;
        return (m);
    }


    inline mat3 operator - (mat3 a, mat3 b) {
        mat3 m = alg::init<mat3>(0.0);
        m.m00 = a.m00 - b.m00; m.m01 = a.m01 - b.m01; m.m02 = a.m02 - b.m02;
        m.m10 = a.m10 - b.m10; m.m11 = a.m11 - b.m11; m.m12 = a.m12 - b.m12;
        m.m20 = a.m20 - b.m20; m.m21 = a.m21 - b.m21; m.m22 = a.m22 - b.m22;
        return (m);
    }


    inline mat3 operator * (mat3 a, mat3 b) {
        mat3 m = alg::init<mat3>(0.0);
        m.m00 = a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02; m.m01 = a.m01 * b.m00 + a.m11 * b.m01 + a.m21 * b.m02; m.m02 = a.m02 * b.m00 + a.m12 * b.m01 + a.m22 * b.m02;
        m.m10 = a.m00 * b.m10 + a.m10 * b.m11 + a.m20 * b.m12; m.m11 = a.m01 * b.m10 + a.m11 * b.m11 + a.m21 * b.m12; m.m12 = a.m02 * b.m10 + a.m12 * b.m11 + a.m22 * b.m12;
        m.m20 = a.m00 * b.m20 + a.m10 * b.m21 + a.m20 * b.m22; m.m21 = a.m01 * b.m20 + a.m11 * b.m21 + a.m21 * b.m22; m.m22 = a.m02 * b.m20 + a.m12 * b.m21 + a.m22 * b.m22;
        return (m);
    }


    inline mat3 operator * (mat3 a, float f) {
        mat3 m = alg::init<mat3>(0.0);
        m.m00 = a.m00 * f; m.m01 = a.m01 * f; m.m02 = a.m02 * f;
        m.m10 = a.m10 * f; m.m11 = a.m11 * f; m.m12 = a.m12 * f;
        m.m20 = a.m20 * f; m.m21 = a.m21 * f; m.m22 = a.m22 * f;
        return (m);
    }


    inline vec3 operator * (mat3 a, vec3 b) {
        vec3 v = alg::init<vec3>(
            a.m00 * b.x + a.m10 * b.y + a.m20 * b.z,
            a.m01 * b.x + a.m11 * b.y + a.m21 * b.z,
            a.m02 * b.x + a.m12 * b.y + a.m22 * b.z
        ); return (v);
    }

    /* Boolean expressions */

    inline bool operator == (mat3 a, mat3 b) {
        return (fabsf(a.m00 - b.m00) < 1e-6f && fabsf(a.m01 - b.m01) < 1e-6f && fabsf(a.m02 - b.m02) < 1e-6f &&
                fabsf(a.m10 - b.m10) < 1e-6f && fabsf(a.m11 - b.m11) < 1e-6f && fabsf(a.m12 - b.m12) < 1e-6f &&
                fabsf(a.m20 - b.m20) < 1e-6f && fabsf(a.m21 - b.m21) < 1e-6f && fabsf(a.m22 - b.m22) < 1e-6f);
    }


    inline bool operator != (mat3 a, mat3 b) {
        return (!(a == b));
    }

    /* Math operations */

    inline mat3 &operator += (mat3 &a, mat3 b) {
        a = a + b;
        return (a);
    }


    inline mat3 &operator -= (mat3 &a, mat3 b) {
        a = a - b;
        return (a);
    }


    inline mat3 &operator *= (mat3 &a, mat3 b) {
        a = a * b;
        return (a);
    }
    
    /* Properties */

    template <>
	mat3 init<mat3>(float s) {
        mat3 m;
        m.m00 = 1.0f * s; m.m01 = 0.0f;     m.m02 = 0.0f;
        m.m10 = 0.0f;     m.m11 = 1.0f * s; m.m12 = 0.0f;
        m.m20 = 0.0f;     m.m21 = 0.0f;     m.m22 = 1.0f * s;
        return (m);
    }
    
    /* Unary operations */
   
    template <>
	mat3 neg<mat3>(mat3 a) {
        mat3 m = alg::init<mat3>(0.0);
        m.m00 = -a.m00; m.m01 = -a.m01; m.m02 = -a.m02;
        m.m10 = -a.m10; m.m11 = -a.m11; m.m12 = -a.m12;
        m.m20 = -a.m20; m.m21 = -a.m21; m.m22 = -a.m22;
        return (m);
	}
   

    template <>
	mat3 transpose<mat3>(mat3 a) {
        mat3 m = alg::init<mat3>(0.0);

        m.m00 = a.m00; m.m01 = a.m10; m.m02 = a.m20;
        m.m10 = a.m01; m.m11 = a.m11; m.m12 = a.m21;
        m.m20 = a.m02; m.m21 = a.m12; m.m22 = a.m22;
        return (m);
	}
   

    template <>
	mat3 inv<mat3>(mat3 a) {
        float det = alg::det<mat3>(a);
        if (det == 0.0f) {
            return (alg::init<mat3>(0.0));
        } else {
            det = 1.0f / det;
        }

        mat3 m = alg::init<mat3>(0.0);
        m.m00 =  (a.m11 * a.m22 - a.m21 * a.m12) * det; m.m01 = -(a.m01 * a.m22 - a.m21 * a.m02) * det; m.m02 =  (a.m01 * a.m12 - a.m11 * a.m02) * det;
        m.m10 = -(a.m10 * a.m22 - a.m20 * a.m12) * det; m.m11 =  (a.m00 * a.m22 - a.m20 * a.m02) * det; m.m12 = -(a.m00 * a.m12 - a.m10 * a.m02) * det;
        m.m20 =  (a.m10 * a.m21 - a.m20 * a.m11) * det; m.m21 = -(a.m00 * a.m21 - a.m20 * a.m01) * det; m.m22 =  (a.m00 * a.m11 - a.m10 * a.m01) * det;
        return (m);
	}
   
    /* Scalar operations */

    template <>
	float det<mat3>(mat3 m) {
        return (m.m00 * (m.m11 * m.m22 - m.m21 * m.m12) -
                m.m10 * (m.m01 * m.m22 - m.m21 * m.m02) +
                m.m20 * (m.m01 * m.m12 - m.m11 * m.m02));
	}
   

    template <>
	float trace<mat3>(mat3 m) {
        return (m.m00 + m.m11 + m.m22);
	}


    template <>
	mat3 rotatex<mat3>(float angle) {
        float c = cosf(angle);
        float s = sinf(angle);

        mat3 m = alg::init<mat3>(0.0);
        m.m00 =    c; m.m01 = 0.0f; m.m02 =   -s;
        m.m10 = 0.0f; m.m11 = 1.0f; m.m12 = 0.0f;
        m.m20 =    s; m.m21 = 0.0f; m.m22 =    c;
        return (m);
	}


    template <>
	mat3 rotatey<mat3>(float angle) {
        float c = cosf(angle);
        float s = sinf(angle);

        mat3 m = alg::init<mat3>(0.0);
        m.m00 =    c; m.m01 = 0.0f; m.m02 =   -s;
        m.m10 = 0.0f; m.m11 = 1.0f; m.m12 = 0.0f;
        m.m20 =    s; m.m21 = 0.0f; m.m22 =    c;
        return (m);
	}


    template <>
	mat3 rotatez<mat3>(float angle) {
        float c = cosf(angle);
        float s = sinf(angle);

        mat3 m = alg::init<mat3>(0.0);
        m.m00 =    c; m.m01 =    s; m.m02 = 0.0f;
        m.m10 =   -s; m.m11 =    c; m.m12 = 0.0f;
        m.m20 = 0.0f; m.m21 = 0.0f; m.m22 = 1.0f;
        return (m);
	}


    template <>
	mat3 rotate<mat3>(vec3 axis, float angle) {
        float c = cosf(angle);
        float s = sinf(angle);
        float t = 1.0f - c;
        vec3  n = alg::norm<vec3>(axis);

        mat3 m = alg::init<mat3>(0.0);
        m.m00 = t * n.x * n.x + c;       m.m01 = t * n.x * n.y + s * n.z; m.m02 = t * n.x * n.z - s * n.y;
        m.m10 = t * n.x * n.y - s * n.z; m.m11 = t * n.y * n.y + c;       m.m12 = t * n.y * n.z + s * n.x;
        m.m20 = t * n.x * n.z + s * n.y; m.m21 = t * n.y * n.z - s * n.x; m.m22 = t * n.z * n.z + c;
        return (m);
	}
    

    template <>
	mat3 scale<mat3>(vec3 s) {
        mat3 m = alg::init<mat3>(0.0);
        m.m00 = s.x;  m.m01 = 0.0f; m.m02 = 0.0f;
        m.m10 = 0.0f; m.m11 = s.y;  m.m12 = 0.0f;
        m.m20 = 0.0f; m.m21 = 0.0f; m.m22 = s.z;
        return (m);
	}

};

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat3_hpp_ */
