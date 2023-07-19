#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "vec3.h"
#include "ray.h"
#include "objects.h"

#define W 1280
#define H 720


void putRGB(vec3 color) {
    printf("%d %d %d\n", (int) (color.x * 255.999), (int) (color.y * 255.999), (int) (color.z * 255.999));
}

int main() {
    double vp_width = 8, vp_height = 4.5, focal_length = 1;
    vec3 origin = {0, 0, 0};
    vec3 horizontal = {vp_width, 0, 0};
    vec3 vertical = {0, vp_height, 0};
    vec3 lower_left_corner = (vec3) {origin.x - horizontal.x / 2 - vertical.x / 2, origin.y - horizontal.y / 2 - vertical.y / 2, origin.z - horizontal.z / 2 - vertical.z / 2 - focal_length};
    sphere_list list; list.head = NULL;
    // add_sphere(&list, (sphere) {(vec3){0,-100.5,-1}, 100});
    // add_sphere(&list, (sphere) {(vec3){0, 0, -20}, 17.0});
    // add_sphere(&list, (sphere) {(vec3){0, 0, -1}, 0.5});

    printf("P3\n%d %d\n255\n", W, H);
    for(int j=H-1;j >= 0;j--) {
        for(int i=0;i < W;i++) {
            double u = (double) i / (W - 1);
            double v = (double) j / (H - 1);

            // Raio r = (LLC - ORIGIN) + HORIZ * u + VERT * v
            ray r = {origin, vec3_sum(3, vec3_sub(lower_left_corner, origin), vec3_scale(horizontal, u), vec3_scale(vertical, v))};
            vec3 color = ray_color(r, list);
            
            // double t = hit_sphere(S, r);
            // if(t > 0) {
            //     vec3 n = vec3_sub(ray_at(r, t), S.center);
            //     vec3 n_unit = unit_vector(n);
            //     color = vec3_scale(vec3_sum(2, n_unit, (vec3){1, 1, 1}), 0.5);
            // } else {
            //     color = ray_color(r); 
            // }
            putRGB(color);
        }
    }

    return 0;
}