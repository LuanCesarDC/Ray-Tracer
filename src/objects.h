#ifndef _OBJECTS_H_
#define _OBJECTS_H_

#include "vec3.h"
#include "ray.h"

// SPHERES

typedef struct sphere {
    vec3 center;
    double radius;
} sphere;

typedef struct sphere_node {
    sphere data;
    struct sphere_node* next;
} sphere_node;

typedef struct sphere_list {
    sphere_node* head;
} sphere_list;

// CUBES

double hit_sphere(sphere S, ray r);

void add_sphere(sphere_list* list, sphere data);

vec3 ray_color(ray r, sphere_list list);

// double hit_sphere(sphere S, ray r); 

#endif // _OBJECTS_H_