//
// Created by halin on 2023-09-18.
//

#include <iostream>
#include <fstream>
#include "vec.h"
#include "ray.h"

vec ray_color(ray r) {
    vec unit_direction = unit_vector(r.direction());
    double a = 0.5*(unit_direction.z() + 1.0);

    return (1.0-a)*vec(1.0, 1.0, 1.0) + a*vec(0.5, 0.7, 1.0);
}

int main() {
    /*
     * Open Image File to Write.
     */
    std::ofstream fout;
    fout.open("image.ppm");
    if (!fout) {
        std::cout << "Failed to open image.ppm file.";
        return 0;
    }

    /*
     * Set image size and viewport size.
     */
    int aspect_ratio[2] = {16, 9};
    int image_scale = 30;
    double viewport_scale = 0.1;
    int image_width = aspect_ratio[0] * image_scale;
    int image_height = aspect_ratio[1] * image_scale;
    double viewport_width = aspect_ratio[0] * viewport_scale;
    double viewport_height = aspect_ratio[1] * viewport_scale;

    /*
     * Write image size in File.
     */
    fout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    /*
     * Camera Setting.
     */
    vec camera_pos(0, 0, 0);
    vec focal_length(1, 0, 0);
    vec camera_angle(0, 0, 1);
    vec view_proj = camera_angle - dot(focal_length, camera_angle) / focal_length.lensq() * focal_length;

    vec pix_dv = -unit_vector(view_proj) * viewport_height / image_height;
    vec pix_du = unit_vector(cross(pix_dv, focal_length)) * viewport_width / image_width;
    vec pix0 = focal_length - pix_du * image_width / 2 - pix_dv * image_height / 2;

    std::cout << "pix_du:\t" << pix_du[0] << '\t' << pix_du[1] << '\t' << pix_du[2] << '\n';
    std::cout << "pix_dv:\t" << pix_dv[0] << '\t' << pix_dv[1] << '\t' << pix_dv[2] << '\n';

    /*
     * Image Processing.
     */
    for (int j = 0; j < image_height; ++j) {
        std::cout << "\rProcessing.. " << j + 1 << " of " << image_height << std::flush;
        for (int i = 0; i < image_width; ++i) {
            vec pix = pix0 + ((i + 0.5) * pix_du) + ((j + 0.5) * pix_dv);

            vec rgb = ray_color(ray(camera_pos, pix));

            int ir = static_cast<int>(255.999 * rgb[0]);
            int ig = static_cast<int>(255.999 * rgb[1]);
            int ib = static_cast<int>(255.999 * rgb[2]);

            fout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    fout.close();
    return 0;
}