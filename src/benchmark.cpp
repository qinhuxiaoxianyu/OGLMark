#include <iostream>

#include "benchmark.h"

Scene & get_scene_from_description(const std::string &s){
    //todo something
    return Benchmark::get_scene_by_name(s);
}

std::vector<Benchmark::OptionPair> get_options_from_description(const std::string &s){
    //todo something
    std::vector<Benchmark::OptionPair> options;
    return options;
}

std::map<std::string, Scene *> Benchmark::sceneMap_;//静态成员一定要再定义一下，类内只是声明，所以访问不到   

Benchmark::Benchmark(const std::string &s)
    :scene_(get_scene_from_description(s)), options_(get_options_from_description(s))
    {}

Scene& Benchmark::scene() const{
    return scene_;
}

void Benchmark::register_scene(Scene &scene){
    sceneMap_[scene.name()] = &scene;
}

Scene & Benchmark::get_scene_by_name(const std::string &name){
    std::map<std::string, Scene *>::const_iterator iter;

    if ((iter = sceneMap_.find(name)) != sceneMap_.end())
        return *(iter->second);
    /*
    else todo something
    */
}

void Benchmark::print(){
    //std::cout<<sceneMap_["default blank!"]->options_["show-fps"].acceptable_values[1]<<std::endl;
    std::cout<<scene_.options_["show-fps"].acceptable_values[1]<<std::endl;
}