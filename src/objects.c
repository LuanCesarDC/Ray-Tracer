#include "objects.h"
#include "ray.h"
#include <math.h>

double hit_sphere(sphere S, ray r) {
    vec3 oc = vec3_sub(r.origin, S.center); // Vetor da camera até o centro da esfera
    double a = vec3_dot(r.direction, r.direction);
    double b = 2 * vec3_dot(oc, r.direction);
    double c = vec3_dot(oc, oc) - S.radius * S.radius;
    double delta = b*b - 4 * a * c;
    return (delta < 0) ? -1.0 : ((-b - sqrt(delta)) / (2 * a));
}