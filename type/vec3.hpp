#if !defined (_type_vec3_hpp_)
# define _type_vec3_hpp_ 1

using vec3 = union vec3_u;

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

#endif /* _type_vec3_hpp_ */
