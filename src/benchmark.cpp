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

Scene& Benchmark::setup_scene(){
    scene_.reset_options();
    load_options();

    scene_.load();
    scene_.setup();

    return scene_;
}

void Benchmark::register_scene(Scene &scene){
    sceneMap_[scene.name()] = &scene;
}

Scene & Benchmark::get_scene_by_name(const std::string &name){
    std::map<std::string, Scene *>::const_iterator iter;

    //if ((iter = sceneMap_.find(name)) != sceneMap_.end())
        return *(iter->second);
    //return 
    /*
    else todo something
    */
}

const std::map<std::string, Scene *>& Benchmark::sceneMap(){
    return sceneMap_;
}

void Benchmark::print(){
    //std::cout<<sceneMap_["default blank!"]->options_["show-fps"].acceptable_values[1]<<std::endl;
    std::cout<<scene_.options_["show-fps"].acceptable_values[1]<<std::endl;
}

void Benchmark::load_options(){
    for (std::vector<OptionPair>::iterator iter = options_.begin(); iter != options_.end(); iter++){
        ;//错误处理
        /*
        if (!scene_.set_option(iter->first, iter->second)){
            std::map<std::string, Scene::Option>::const_iterator opt_iter = scene_.options().find(iter->first);
            if (opt_iter == scene_.options().end()) {
                Log::info("Warning: Scene '%s' doesn't accept option '%s'\n",
                          scene_.name().c_str(), iter->first.c_str());
            }
            else {
                Log::info("Warning: Scene '%s' doesn't accept value '%s' for option '%s'\n",
                          scene_.name().c_str(), iter->second.c_str(), iter->first.c_str());
            }
        }
        */
    }
}