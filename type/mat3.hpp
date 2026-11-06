#if !defined (_type_mat3_hpp_)
# define _type_mat3_hpp_ 1

namespace alg {

    using mat3 = struct mat3;

    /* Column-Major Matrix3x3:
     * 
     * Member name meaning: 'm{Col.}{Row.}'
     *
     * Layout:
     * [m00, m10, m20]
     * [m01, m11, m21]
     * [m02, m12, m22]
     *
     * Memory layout:
     * [m00, m01, m02, m10, m11, m12, m20, m21, m22]
     * * * * * * * * * * * * * * * * * * * * * * * */
    struct mat3 {
        float m00, m01, m02,
              m10, m11, m12,
              m20, m21, m22;
    };

};

#endif /* _type_mat3_hpp_ */
