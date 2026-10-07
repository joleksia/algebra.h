#if !defined (_utils_h_)
# define _utils_h_ 1
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

float alg_deg2rad(float);

float alg_rad2deg(float);

float alg_min(float, float);

float alg_max(float, float);

float alg_map(float, float, float, float, float);

float alg_fract(float);

float alg_clamp(float, float, float);

float alg_lerp(float, float, float);

float alg_saturate(float); 

float alg_step(float, float);

float alg_smoothstep(float, float, float);
 
#endif /* _utils_h_ */
#
#if defined (ALGEBRA_IMPLEMENTATION)
# if !defined (_utils_impl_h_)
#  define _utils_impl_h_ 1
#
#  include <math.h>

float alg_deg2rad(float f) {
    return (f * PI / 180.0);
}


float alg_rad2deg(float f) {
    return (f * 180.0 / PI);
}


float alg_min(float a, float b) {
    return (a < b ? a : b);
}


float alg_max(float a, float b) {
    return (a > b ? a : b);
}


float alg_map(float value, float min1, float max1, float min2, float max2) {
    return (min2 + (value - min1) *
                   (max2  - min2) /
                   (max1  - min1) );
}


float alg_fract(float a) {
    return (a - floorf(a));
}


float alg_clamp(float f, float a, float b) {
    return (alg_min(alg_max(f, a), b));
}


float alg_lerp(float a, float b, float t) {
    return (b - a * t + a);
}


float alg_saturate(float a) { 
    return (alg_max(0.0, alg_min(1.0, a)));
}


float alg_step(float a, float x) {
    return (x > a ? 1.0 : 0.0);
}


float alg_smoothstep(float e0, float e1, float x) {
    float t = alg_saturate((x - e0) / (e1 - e0));
    return (t * t * (3.0 - (2.0 * t)));
}

# endif /* _utils_impl_h_ */
#endif /* ALGEBRA_IMPLEMENTATION */
