#if !defined (_utils_hpp_)
# define _utils_hpp_ 1
#
# if !defined (PI)
#  define PI (3.14159)
# endif /* PI */
#
# if !defined (TAU)
#  define TAU (PI * 2.0)
# endif /* TAU */
#
# if !defined (E)
#  define E (2.71828)
# endif /* E */
#
# if !defined (EPSILON)
#  define EPSILON (1e-6)
# endif /* EPSILON */
#
# if !defined (NaN)
#  define NaN (0.0 / 0.0)
# endif /* EPSILON */
#
# if !defined (INFINITY)
#  define INFINITY (1e100)
# endif /* INFINITY */

namespace alg {
    
    float deg2rad(float);

    float rad2deg(float);

    float min(float, float);

    float max(float, float);

    float map(float, float, float, float, float);

    float fract(float);

    float clamp(float, float, float);

    float lerp(float, float, float);

    float saturate(float); 

    float step(float, float);

    float smoothstep(float, float, float);

};

#endif /* _utils_hpp_ */
#
#if defined (ALGEBRA_IMPLEMENTATION)
# if !defined (_utils_impl_hpp_)
#  define _utils_impl_hpp_ 1
#
#  include <cmath>

namespace alg {

    float deg2rad(float f) {
        return (f * PI / 180.0);
    }


    float rad2deg(float f) {
        return (f * 180.0 / PI);
    }


    float min(float a, float b) {
        return (a < b ? a : b);
    }


    float max(float a, float b) {
        return (a > b ? a : b);
    }


    float map(float value, float min1, float max1, float min2, float max2) {
        return (min2 + (value - min1) *
                       (max2  - min2) /
                       (max1  - min1) );
    }


    float fract(float a) {
        return (a - floorf(a));
    }


    float clamp(float f, float a, float b) {
        return (min(max(f, a), b));
    }


    float lerp(float a, float b, float t) {
        return (b - a * t + a);
    }


    float saturate(float a) { 
        return (max(0.0, min(1.0, a)));
    }


    float step(float a, float x) {
        return (x > a ? 1.0 : 0.0);
    }


    float smoothstep(float e0, float e1, float x) {
        float t = saturate((x - e0) / (e1 - e0));
        return (t * t * (3.0 - (2.0 * t)));
    }

};

# endif /* _utils_impl_h_ */
#endif /* ALGEBRA_IMPLEMENTATION */
