#pragma once

#include "general_def.h"

class ray {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    ray(const vec3 & origin, const vec3 &dir);
    vec3 eval(fp_t t) const;
    const vec3 &get_origin() const;
    const vec3 &get_dir() const;

private:
    vec3 origin;
    vec3 dir;
};

class rt_object {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    explicit rt_object();
    virtual ~rt_object() = default;

    void set_transform(const mat3 &tf);

    void apply_transform(const mat3 &tf);

    void save_transform();

    void restore_transform();

    virtual void intersect_transformed(const ray &r, itsc_t &itsc) const;

    void intersect(const ray &r, itsc_t &itsc) const;

    ray inv_transform_ray(const ray &r) const;

private:
    mat3 tf, inv_tf, tf_saved, inv_tf_saved;
};

class solid_object {
public:
    explicit solid_object(fp_t mu);
    virtual ~solid_object() = default;

    fp_t get_mu() const;

    fp_t attenuate(fp_t intensity, fp_t depth) const;

private:
    fp_t mu;
};

class rt_sphere : public rt_object, public solid_object {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    rt_sphere(const vec3 & origin, fp_t radius, fp_t mu);

    void intersect_transformed(const ray &r, itsc_t &itsc) const final;

private:
    vec3 origin;
    fp_t radius, radius2;
};

class rt_quadrilateral : public rt_object {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    rt_quadrilateral(const vec3 & base, const vec3 &p1, const vec3 &p2, bool use_v=true);

    void intersect_transformed(const ray &r, itsc_t &itsc) const final;
private:
    vec3 base, v1, v2, normal;
    mat3 m, inv_m;
    fp_t bdn;
};

class rt_cube : public rt_object, public solid_object {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    rt_cube(const vec3 &center, fp_t length, fp_t mu);

    void intersect_transformed(const ray &r, itsc_t &itsc) const final;

private:
    vector<rt_quadrilateral> sides;
};