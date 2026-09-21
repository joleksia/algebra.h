#if !defined (_type_vec3_h_)
# define _type_vec3_h_ 1

typedef union vec3_u vec3;

union vec3_u {
    struct {
        float x;
        float y;
        float z;
    };

    struct {
        float r;
        float g;
        float b;
    };
};

#endif /* _type_vec3_h_ */
