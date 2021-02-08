#pragma once

#include "general_def.h"
#include "nlohmann/json.hpp"

nlohmann::json::object_t image_to_json(const img_t &img);

vec3 read_vec3_from_json(const nlohmann::json::array_t &o);

mat3 read_mat3_from_json(const nlohmann::json::array_t &o);