#if !defined (_type_mat2_h_)
# define _type_mat2_h_ 1

typedef union mat2_u mat2;

union mat2_u {
    struct {
        float m00, m01,
              m10, m11;
    };
};

#endif /* _type_mat2_h_ */
