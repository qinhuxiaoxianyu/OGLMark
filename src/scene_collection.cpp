

#include "scene_collection.h"

void SceneCollection::add_scenes(GLFWwindow* window){
    Scene *sce;
    scenes_.push_back(sce);
}

SceneCollection::SceneCollection(GLFWwindow* window){
    add_scenes(window);
}

SceneCollection::~SceneCollection(){
    //销毁vector
}

void register_scenes(){
    //todo
}