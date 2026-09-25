#if !defined (_type_mat3_h_)
# define _type_mat3_h_ 1

typedef union mat3_u mat3;

union mat3_u {
    struct {
        float m00, m01, m02,
              m10, m11, m12,
              m20, m21, m22;
    };
};

#endif /* _type_mat3_h_ */
