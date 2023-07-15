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

    printf("P3\n%d %d\n255\n", W, H);
    for(int j=H-1;j >= 0;j--) {
        for(int i=0;i < W;i++) {
            double u = (double) i / (W - 1);
            double v = (double) j / (H - 1);
            ray r = {origin, vec3_sum(vec3_sub(lower_left_corner, origin), vec3_sum(vec3_scale(horizontal, u), vec3_scale(vertical, v)))};
            vec3 color;
            sphere S = {(vec3){0,0,-1}, 0.8};
            double t = hit_sphere(S, r);
            if(t > 0) {
                vec3 n = vec3_sub(ray_at(r, t), S.center);
                vec3 n_unit = unit_vector(n);
                color = vec3_scale(vec3_sum(n_unit, (vec3){1, 1, 1}), 0.5);
            } else {
                color = ray_color(r); 
            }
            putRGB(color);
        }
    }

    return 0;
}