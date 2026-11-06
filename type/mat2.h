#if !defined (_type_mat2_h_)
# define _type_mat2_h_ 1

typedef struct mat2 mat2;

/* Column-Major Matrix2x2:
 * 
 * Member name meaning: 'm{Col.}{Row.}'
 *
 * Layout:
 * [m00, m10]
 * [m01, m11]
 *
 * Memory layout:
 * [m00, m01, m10, m11]
 * * * * * * * * * * * */
struct mat2 {
    float m00, m01,
          m10, m11;
};

#endif /* _type_mat2_h_ */
