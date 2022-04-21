#include <iostream>

#include "benchmark.h"

std::map<std::string, Scene *> Benchmark::sceneMap_;//静态成员一定要再定义一下，类内只是声明，所以访问不到

Benchmark::Benchmark(/* args */)
{
}

Benchmark::~Benchmark()
{
}

void Benchmark::register_scene(Scene &scene){
    sceneMap_[scene.name()] = &scene;
}

void Benchmark::print(){
    std::cout<<sceneMap_["default blank!"]->options_["show-fps"].acceptable_values[1]<<std::endl;
}