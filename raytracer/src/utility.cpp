#include "utility.h"
#include "base64.h"
#include "gzip/compress.hpp"


nlohmann::json::object_t image_to_json(const img_t &img){
    auto ret = nlohmann::json::object();
    ret["type"] = "image";
    ret["rows"] = img.rows();
    ret["cols"] = img.cols();
    auto element_size = sizeof(img_t::value_type);
    ret["element_size"] = element_size;

    auto size_in_bytes = img.size() * element_size;
    auto compressed = gzip::compress(reinterpret_cast<const char*>(img.data()), size_in_bytes);
    ret["data"] = base64_encode(compressed);
    return ret;
}

vec3 read_vec3_from_json(const nlohmann::json::array_t &o) {
    if (o.size() != 3){
        throw runtime_error{"vector size mismatch"};
    }
    vec3 ret;
    int_t counter = 0;
    for(auto it = o.begin(); it != o.end(); ++it){
        ret[counter++] = *it;
    }
    return ret;
}

mat3 read_mat3_from_json(const nlohmann::json::array_t &o) {
    if (o.size() != 9){
        throw runtime_error{"vector size mismatch"};
    }
    mat3 ret;
    int_t counter = 0;
    for(auto it = o.begin(); it != o.end(); ++it){
        ret(counter /3 , counter % 3) = *it;
        ++counter;
    }
    return ret;
}
