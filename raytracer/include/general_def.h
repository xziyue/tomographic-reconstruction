#pragma once

#include "Eigen/Dense"
#include <vector>
#include <string>
#include <cmath>
#include <cassert>
#include <fstream>
#include <array>
#include <iostream>
#include <filesystem>

using namespace std;

using fp_t = double;
using img_fp_t = float;
using img_t = Eigen::Matrix<img_fp_t, -1, -1, Eigen::RowMajor>;

using int_t = int32_t;
using vec3 = Eigen::Vector3d;
using vec2 = Eigen::Vector2d;
using mat3 = Eigen::Matrix3d;
using mat2 = Eigen::Matrix2d;

using itsc_t = vector<fp_t>;

constexpr const fp_t eps = 1.0e-7;
