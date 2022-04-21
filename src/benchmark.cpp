#include <iostream>

#include "benchmark.h"

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
    std::cout<<*(sceneMap_["default blank!"]).options_["show-fps"].acceptable_values[1]<<std::endl;
}