#ifndef _VEC3_H_
#define _VEC3_H_

typedef struct vec3 {
    double x, y, z;
} vec3;

vec3 vec3_sum(vec3 A, vec3 B);

vec3 vec3_sub(vec3 A, vec3 B);

vec3 vec3_div(vec3 A, double t);

vec3 vec3_scale(vec3 A, double t);

vec3 unit_vector(vec3 A);

void vec3_print(vec3 A);

double vec3_dot(vec3 A, vec3 B);


#endif // _VEC3_H_