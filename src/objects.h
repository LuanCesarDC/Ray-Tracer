#ifndef _OBJECTS_H_
#define _OBJECTS_H_

#include "vec3.h"
#include "ray.h"

typedef struct sphere {
    vec3 center;
    double radius;
} sphere;

double hit_sphere(sphere S, ray r); 

#endif // _OBJECTS_H_