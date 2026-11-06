#if !defined (_type_mat4_h_)
# define _type_mat4_h_ 1

typedef struct mat4 mat4;

/* Column-Major Matrix4x4:
 * 
 * Member name meaning: 'm{Col.}{Row.}'
 *
 * Layout:
 * [m00, m10, m20, m30]
 * [m01, m11, m21, m31]
 * [m02, m12, m22, m32]
 * [m03, m13, m23, m33]
 *
 * Memory layout:
 * [m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct mat4 {
    float m00, m01, m02, m03,
          m10, m11, m12, m13,
          m20, m21, m22, m23,
          m30, m31, m32, m33;
};

#endif /* _type_mat4_h_ */
