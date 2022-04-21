

#include "scene_collection.h"
#include "benchmark.h"

void SceneCollection::add_scenes(GLFWwindow* window){
    scenes_.push_back(new SceneDefaultOptions(window));
}

SceneCollection::SceneCollection(GLFWwindow* window){
    add_scenes(window);
}

SceneCollection::~SceneCollection(){
    //销毁vector
}

void SceneCollection::register_scenes(){
    for (std::vector<Scene*>::const_iterator iter = scenes_.begin(); iter != scenes_.end(); iter++){
        Benchmark::register_scene(**iter);
    }
}

const std::vector<Scene*>& SceneCollection::get(){
    return scenes_;
}

void SceneCollection::print(){//fortest
    scenes_[0]->print();
}