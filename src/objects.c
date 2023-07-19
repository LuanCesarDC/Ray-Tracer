#include "objects.h"
#include "ray.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <float.h>


double hit_sphere(sphere S, ray r) {
    vec3 oc = vec3_sub(r.origin, S.center); // Vetor da camera até o centro da esfera
    double a = vec3_dot(r.direction, r.direction);
    double b = 2 * vec3_dot(oc, r.direction);
    double c = vec3_dot(oc, oc) - S.radius * S.radius;
    double delta = b*b - 4 * a * c;
    return (delta < 0) ? -1.0 : ((-b - sqrt(delta)) / (2 * a));
}

void add_sphere(sphere_list* list, sphere data) {
    // Create a new node
    sphere_node* new_node = (sphere_node*)malloc(sizeof(sphere_node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        // The list is empty, set the new node as the head
        list->head = new_node;
    } else {
        // Find the last node and append the new node
        sphere_node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

vec3 ray_color(ray r, sphere_list list) {
    vec3 unit_direction = unit_vector(r.direction);
    vec3 n_unit = unit_direction;
    double t_min = 0, t_max = DBL_MAX;

    sphere_node* next = list.head;

    while(next != NULL) {
        double t = hit_sphere(next->data, r);
        if(t > t_min && t < t_max) {
                vec3 n = vec3_sub(ray_at(r, t), next->data.center);
                n_unit = unit_vector(n);
        }
        next = next->next;
    }

    if((n_unit.x != unit_direction.x) || (n_unit.y != unit_direction.y) | (n_unit.z != unit_direction.z)) {
        return vec3_scale(vec3_sum(2, n_unit, (vec3){1, 1, 1}), 0.5);
    }

    double t = 0.5 * (unit_direction.y + 1.0);
    return vec3_sum(2, vec3_scale((vec3) {1.0, 1.0, 1.0}, (1.0-t)), vec3_scale((vec3) {0.5, 0.7, 1.0}, t));
}
