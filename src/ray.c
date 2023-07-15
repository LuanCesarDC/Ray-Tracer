#include "ray.h"
#include "vec3.h"

vec3 ray_at(ray r, double t) {
    return vec3_sum(r.origin, vec3_scale(r.direction, t));
}

vec3 ray_color(ray r) {
    vec3 unit_direction = unit_vector(r.direction);
    double t = 0.5 * (unit_direction.y + 1.0);
    return vec3_sum(vec3_scale((vec3) {1.0, 1.0, 1.0}, (1.0-t)), vec3_scale((vec3) {0.5, 0.7, 1.0}, t));
}