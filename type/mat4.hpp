#if !defined (_type_mat4_hpp_)
# define _type_mat4_hpp_ 1

namespace alg {

    using mat4 = struct mat4 ;

    struct mat4 {
        float m00, m01, m02, m03,
              m10, m11, m12, m13,
              m20, m21, m22, m23,
              m30, m31, m32, m33;
    };

};

#endif /* _type_mat4_hpp_ */
