#ifndef _RAY_H_
#define _RAY_H_
#include "vec3.h"

typedef struct ray {
    vec3 origin, direction;
} ray;

vec3 ray_at(ray r, double t);

#endif // _RAY_H_