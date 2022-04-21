#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include <map>
#include <string>
#include <vector>

#include "scene.h"

class Benchmark
{
public:
    typedef std::pair<std::string, std::string> OptionPair;

    ~Benchmark()=default;

    Benchmark(const std::string &s);

    Scene& scene() const;
    static void register_scene(Scene &scene);
    static Scene &get_scene_by_name(const std::string &name);

    /*static */void print();//fortest
    Scene &scene_;//fortest
private:
    /* data */
    //Scene &scene_;
    std::vector<OptionPair> options_;
    static std::map<std::string, Scene *> sceneMap_;
};

static Scene & get_scene_from_description(const std::string &s);
static std::vector<Benchmark::OptionPair> get_options_from_description(const std::string &s);

#endif