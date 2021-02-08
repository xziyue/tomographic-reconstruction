#pragma once

#include "raytracing_object.h"

class camera {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    camera(fp_t plane_center_z,
           int_t rows, int_t cols,
           fp_t pixel_size=0.05);

    int_t get_rows() const;

    int_t get_cols() const;

    vec3 get_pixel_pos(int_t i, int_t j) const;

    ray get_ray(int_t i, int_t j, fp_t z=100.0) const;

    img_t get_empty_image() const;

private:
    vec3 plane_center, plane_i, plane_j, plane_normal, plane_origin;
    int_t rows, cols;
};