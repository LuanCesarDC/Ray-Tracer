#include <float.h>
#include <stdio.h>
#include "ray.h"
#include "vec3.h"

vec3 ray_at(ray r, double t) {
    return vec3_sum(2, r.origin, vec3_scale(r.direction, t));
}