#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include <map>
#include <string>

#include "scene.h"

class Benchmark
{
public:
    Benchmark(/* args */);
    ~Benchmark();

    static void register_scene(Scene &scene);

    static void print();//fortest
private:
    /* data */
    static std::map<std::string, Scene *> sceneMap_;
};

#endif