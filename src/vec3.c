#include "vec3.h"
#include <stdio.h>
#include <math.h>
#include <stdarg.h>

vec3 vec3_sum(int count, ...) {
    va_list args;
    va_start(args, count);

    vec3 result = va_arg(args, vec3);
    for (int i = 1; i < count; i++) {
        vec3 next = va_arg(args, vec3);
        result.x += next.x;
        result.y += next.y;
        result.z += next.z;
    }

    va_end(args);
    return result;
}

vec3 vec3_sub(vec3 A, vec3 B) {
    return (vec3) {A.x - B.x, A.y - B.y, A.z - B.z};
}  

vec3 vec3_div(vec3 A, double t) {
    if(t != 0)
        return (vec3) {A.x / t, A.y / t, A.z / t};
    return (vec3) {0, 0, 0};
}

vec3 vec3_scale(vec3 A, double t) {
    return (vec3) {A.x * t, A.y * t, A.z * t};
}

vec3 unit_vector(vec3 A) {
    double len = sqrt(A.x*A.x + A.y*A.y + A.z*A.z);
    return vec3_div(A, len);
}

void vec3_print(vec3 A) {
    printf("x: %.2lf, y: %.2lf, z: %.2lf\n", A.x, A.y, A.z);
}

double vec3_dot(vec3 A, vec3 B) {
    return A.x * B.x + A.y * B.y + A.z * B.z;
}