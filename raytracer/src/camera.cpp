#include "camera.h"

camera::camera(fp_t plane_center_z,
               int_t rows, int_t cols,
               fp_t pixel_size) {

    this->rows = rows;
    this->cols = cols;
    plane_center = vec3{0.0, 0.0, plane_center_z};
    plane_i = vec3{0.0, -1.0, 0.0} * pixel_size;
    plane_j = vec3{1.0, 0.0, 0.0} * pixel_size;
    plane_normal = plane_i.cross(plane_j).normalized();
    plane_origin = plane_center - (fp_t) rows / 2.0 * plane_i - (fp_t) cols / 2.0 * plane_j;
}

int_t camera::get_rows() const {
    return rows;
}

int_t camera::get_cols() const {
    return cols;
}

vec3 camera::get_pixel_pos(int_t i, int_t j) const {
    assert(i >= 0 && i < get_rows());
    assert(j >= 0 && j < get_cols());
    return plane_origin + (i + 0.5) * plane_i + (j + 0.5) * plane_j;
}

ray camera::get_ray(int_t i, int_t j, fp_t z) const {
    vec3 origin = get_pixel_pos(i, j) - z * plane_normal;
    return ray(origin, plane_normal);
}

img_t camera::get_empty_image() const {
    img_t ret(get_rows(), get_cols());
    ret.fill(0.0);
    return ret;
}



