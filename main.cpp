#include <iostream>
#include <fstream>
#include "vec.h"



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
    vec focal_length(1.0, 0, 0);
    vec camera_angle(0, 0, 1);
    vec view_proj = camera_angle - dot(focal_length, camera_angle) / focal_length.lensq() * focal_length;

    vec pix_dv = -unit_vector(view_proj) * viewport_height / image_height;
    vec pix_du = unit_vector(cross(pix_dv, focal_length)) * viewport_width / image_width;
//    vec pix_du = vec(viewport_width / image_width, 0, 0);
//    vec pix_dv = vec(viewport_height / image_height, 0, 0);
    vec pix0 = focal_length - pix_du * image_width / 2 - pix_dv * image_height / 2;


    for (int j = 0; j < image_height; ++j) {
        std::cout << "\rProcessing.. " << j + 1 << " of " << image_height << std::flush;
        for (int i = 0; i < image_width; ++i) {
            vec pix = pix0 + ((i + 0.5) * pix_du) + ((j + 0.5) * pix_dv);


            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            fout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    fout.close();
    return 0;
}