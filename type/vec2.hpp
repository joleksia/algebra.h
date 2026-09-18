#if !defined (_type_vec2_hpp_)
# define _type_vec2_hpp_ 1

namespace alg {

    using vec2 = union u_vec2;

    union u_vec2 {
        struct {
            float x;
            float y;
        };

        struct {
            float w;
            float h;
        };
    };

};

#endif /* _type_vec2_hpp_ */
