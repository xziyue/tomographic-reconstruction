#include "raytracing_object.h"

ray::ray(const vec3 &origin, const vec3 &dir) {
    this->origin = origin;
    this->dir = dir;
    this->dir.normalize();
}

vec3 ray::eval(fp_t t) const {
    return origin + t * dir;
}

const vec3 &ray::get_origin() const {
    return origin;
}

const vec3 &ray::get_dir() const {
    return dir;
}

rt_object::rt_object() {
    set_transform(mat3::Identity());
    save_transform();
}

ray rt_object::inv_transform_ray(const ray &r) const{
    vec3 origin = inv_tf * r.get_origin();
    vec3 dir = inv_tf * r.get_dir();
    return ray(origin, dir);
}

void rt_object::set_transform(const mat3 &tf) {
    this->tf = tf;
    this->inv_tf = tf.inverse().eval();
}

void rt_object::apply_transform(const mat3 &tf) {
    save_transform();
    this->tf = (tf * this->tf).eval();
    this->inv_tf = this->tf.inverse().eval();
}

void rt_object::save_transform() {
    tf_saved = tf;
    inv_tf_saved = inv_tf;
}

void rt_object::restore_transform() {
    tf = tf_saved;
    inv_tf = inv_tf_saved;
}

void rt_object::intersect_transformed(const ray &r, itsc_t &itsc) const {
    throw runtime_error{"this method is not implemented"};
}

void rt_object::intersect(const ray &r, itsc_t &itsc) const {
    auto tf_ray = inv_transform_ray(r);
    intersect_transformed(tf_ray, itsc);
}


solid_object::solid_object(fp_t mu) : mu{mu} {

}

fp_t solid_object::get_mu() const {
    return mu;
}

fp_t solid_object::attenuate(fp_t intensity, fp_t depth) const {
    // using the expectation of Poisson distribution
    return intensity * exp(-mu * depth);
}

rt_sphere::rt_sphere(const vec3 &origin, fp_t radius, fp_t mu) : solid_object(mu) {
    this->origin = origin;
    this->radius = radius;
    this->radius2 = radius * radius;
}

void rt_sphere::intersect_transformed(const ray &r, itsc_t &itsc) const {
    assert(itsc.empty());
    vec3 l = origin - r.get_origin();
    fp_t proj_length = l.dot(r.get_dir());
    if (proj_length < eps){
        return;
    }
    fp_t center_dist2 = l.dot(l) - proj_length * proj_length;
    if (center_dist2 < radius2 - eps) {
        fp_t span = sqrt(radius2 - center_dist2);
        itsc.push_back(proj_length - span);
        itsc.push_back(proj_length + span);
    }
}

rt_quadrilateral::rt_quadrilateral(const vec3 &base, const vec3 &p1, const vec3 &p2, bool use_v) {
    this->base = base;
    if (use_v){
        v1 = p1;
        v2 = p2;
    }else{
        v1 = p1 - base;
        v2 = p2 - base;
    }

    normal = v1.cross(v2).normalized();
    bdn = base.dot(normal);

    m.col(0) = v1;
    m.col(1) = v2;
    m.col(2) = normal;
    inv_m = m.inverse().eval();
}

void rt_quadrilateral::intersect_transformed(const ray &r, itsc_t &itsc) const {
    fp_t denom = normal.dot(r.get_dir());
    if(denom < eps){
        //return;
    }
    fp_t t = (bdn - r.get_origin().dot(normal)) / denom;
    vec3 plane_loc = r.eval(t);
    vec3 plane_xyz = inv_m * (plane_loc - base);
    assert(abs(plane_xyz[2]) < eps);
    if ( plane_xyz[0] >= eps && plane_xyz[1] >= eps && plane_xyz[0] <= 1.0 - eps && plane_xyz[1] <= 1.0 - eps) {
        itsc.push_back(t);
    }
}

rt_cube::rt_cube(const vec3 &center, fp_t length, fp_t mu) : solid_object(mu){
    vec3 unit_x = vec3(1.0, 0, 0.0) * length;
    vec3 unit_y = vec3(0.0, 1.0, 0.0) * length;
    vec3 unit_z = vec3(0.0, 0.0, 1.0) * length;

    vec3 base = center - 0.5 * (unit_x + unit_y + unit_z);

    sides.reserve(6);
    sides.emplace_back(rt_quadrilateral(base, unit_x, unit_y));
    sides.emplace_back(rt_quadrilateral(base + unit_z, unit_x, unit_y));
    sides.emplace_back(rt_quadrilateral(base, unit_x, unit_z));
    sides.emplace_back(rt_quadrilateral(base + unit_y, unit_x, unit_z));
    sides.emplace_back(rt_quadrilateral(base, unit_y, unit_z));
    sides.emplace_back(rt_quadrilateral(base + unit_x, unit_y, unit_z));
}

void rt_cube::intersect_transformed(const ray &r, itsc_t &itsc) const {
    assert(itsc.empty());
    for (const auto &side : sides){
        side.intersect_transformed(r, itsc);
    }
    if (itsc.size() < 2){
        itsc.clear();
    }
    sort(itsc.begin(), itsc.end());
}
