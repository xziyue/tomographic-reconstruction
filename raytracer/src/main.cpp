#include "raytracing_object.h"
#include "camera.h"
#include "utility.h"

int main(int argc, char **argv) {

    if (argc < 3) {
        cout << "not enough aruments provided\n";
        exit(1);
    }

    if (!filesystem::exists(argv[1])){
        cout << "input file does not exist\n";
    }

    fstream infile{argv[1], ios::in | ios::binary};
    infile.seekg(0, ios::end);
    auto infile_length = infile.tellg();
    infile.seekg(0);
    string json_in(infile_length, '\0');
    infile.read(json_in.data(), json_in.size());
    infile.close();

    auto config = nlohmann::json::parse(json_in);

    auto cam_config = config["camera"];
    camera cam(cam_config["z"].get<fp_t>(),
            cam_config["rows"].get<int_t>(),
            cam_config["cols"].get<int_t>(),
            cam_config["pixel_size"].get<fp_t>());

    auto global_transformation = read_mat3_from_json(config["global_transformation"]);
    fp_t intensity = config["intensity"];

    vector<unique_ptr<rt_object>> scene;

    for (const auto &obj : config["objects"]) {
        if(obj["type"].get<string>() != "object"){
            throw runtime_error{"object does not belong in the scene"};
        }
        string shape = obj["shape"];
        mat3 transformation = read_mat3_from_json(obj["transformation"]);

        fp_t mu = obj["mu"];
        if (shape == "sphere") {
            vec3 center = read_vec3_from_json(obj["center"]);
            fp_t radius = obj["radius"];
            scene.emplace_back(make_unique<rt_sphere>(center, radius, mu));
        }else if(shape == "cube") {
            vec3 center = read_vec3_from_json(obj["center"]);
            fp_t length = obj["length"];
            scene.emplace_back(make_unique<rt_cube>(center, length, mu));
        }else{
            throw runtime_error{"unsupported shape"};
        }

        scene.back()->set_transform(transformation);
        scene.back()->apply_transform(global_transformation);
    }

    vector<fp_t> itsc;
    vector<tuple<fp_t, fp_t, int_t>> current_itsc;

    auto img = cam.get_empty_image();

    for (auto i = 0; i < cam.get_rows(); ++i){
        for(auto j = 0; j < cam.get_cols(); ++j){
            auto ray = cam.get_ray(i, j);

            for (int_t k = 0; k < scene.size(); ++k) {
                itsc.clear();
                scene[k]->intersect(ray, itsc);
                if (itsc.size() == 2){
                    assert(itsc[0] < itsc[1]);
                    current_itsc.emplace_back(make_tuple(itsc[0], itsc[1], k));
                }
            }

            if (current_itsc.empty()){
                img(i, j) = intensity; // no occlusion
            } else {
                sort(current_itsc.begin(), current_itsc.end());
                fp_t cur_intensity = intensity;
                for (const auto &itsc_info : current_itsc) {
                    fp_t depth = get<1>(itsc_info) - get<0>(itsc_info);
                    auto solid_obj_ptr = dynamic_cast<const solid_object*>(scene[get<2>(itsc_info)].get());
                    cur_intensity = solid_obj_ptr->attenuate(cur_intensity, depth);
                }
                img(i, j) = cur_intensity;
                current_itsc.clear();
            }

        }
    }

    nlohmann::json output;
    output["image"] = image_to_json(img);
    auto output_string = output.dump();

    fstream outfile{argv[2], ios::out | ios::binary};
    outfile.write(output_string.c_str(), output_string.size());
    outfile.close();

    return 0;
}
