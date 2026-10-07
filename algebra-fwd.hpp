#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#
#if !defined (_algebra_fwd_hpp_)
# define _algebra_fwd_hpp_ 1

namespace alg {

    template <typename T>
	T init(float);

    template <typename T>
	T init(float, float);

    template <typename T>
	T init(float, float, float);

    template <typename T>
	T init(float, float, float, float);
 
    template <typename T>
	T rotate(float);
    
    template <typename T, typename U>
	T rotate(U, float);
   
    template <typename T>
	T rotate(T, float);
   
    template <typename T>
	T rotate(T, T, float);

    /* vector functions */

    template <typename T>
	float ln(T);

    template <typename T>
	float lnsq(T);

    template <typename T>
	float dst(T, T);

    template <typename T>
	float dstsq(T, T);

    template <typename T>
	float dot(T, T);

    template <typename T, typename U>
	T cross(U, U);
    
    template <typename T>
	float det(T, T);

    template <typename T>
	T norm(T);

    template <typename T>
	T neg(T);

    template <typename T>
	T abs(T);

    template <typename T>
	T sign(T);

    template <typename T>
	T sqrt(T);

    template <typename T>
	T pow(T, float);

    template <typename T>
	T fract(T);

    template <typename T>
	T floor(T);

    template <typename T>
	T ceil(T);

    template <typename T>
	T round(T);

    template <typename T>
	T min(T, T);

    template <typename T>
	T minf(T, float);

    template <typename T>
	T max(T, T);

    template <typename T>
	T maxf(T, float);

    template <typename T>
	T clamp(T, T, T);

    template <typename T>
	T clampf(T, float, float);

    template <typename T>
	T lerp(T, T, float);

    template <typename T>
	T step(T, T);

    template <typename T>
	T smoothstep(T, T, T);

    template <typename T>
	T perp(T);

    template <typename T>
	T reflect(T, T);

    template <typename T>
	T refract(T, T, float);

    template <typename T>
	float angle(T, T);
    
    /* matrix functions */
    
    template <typename T>
	T neg(T);
    
    template <typename T>
	T transpose(T);
    
    template <typename T>
	T inv(T);
    
    template <typename T>
	float det(T);
    
    template <typename T>
	float trace(T);

    template <typename T>
	T rotatex(float);
    
    template <typename T>
	T rotatey(float);
    
    template <typename T>
	T rotatez(float);

    template <typename T, typename U>
	T rotateat(U, U, float);

    template <typename T, typename U>
	T lookat(U, U, U);
    
    template <typename T, typename U>
	T scale(U);
    
    template <typename T, typename U>
	T translate(U);
    
    template <typename T>
	T frust(float, float, float, float, float, float);
    
    template <typename T>
	T ortho(float, float, float, float, float, float);
    
    template <typename T>
	T perps(float, float, float, float);

};

#endif /* _algebra_fwd_hpp_ */
