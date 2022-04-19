#ifndef SCENE_COLLECTION_H_
#define SEENE_COLLECTION_H_

#include <vector>

#include <GLFW/glfw3.h>

#include "scene.h"

class SceneCollection
{
private:
    /* data */
    std::vector<Scene*> scenes_;

    void add_scenes(GLFWwindow* window);
public:
    SceneCollection(GLFWwindow* window);
    ~SceneCollection();

    void register_scenes();
};
 


#endif