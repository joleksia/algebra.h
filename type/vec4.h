#if !defined (_type_vec4_h_)
# define _type_vec4_h_ 1

typedef union vec4_u vec4;

union vec4_u {
    struct {
        float x;
        float y;
        float z;
        float w;
    };

    struct {
        float r;
        float g;
        float b;
        float a;
    };
};

#endif /* _type_vec4_h_ */
