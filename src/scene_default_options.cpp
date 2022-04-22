#include <iostream>

#include "scene.h"
#include "benchmark.h"
#include "log.h"

SceneDefaultOptions::SceneDefaultOptions(GLFWwindow* window):Scene(window, "default blank!"){
}

bool SceneDefaultOptions::set_option(const std::string &opt, const std::string &val){
    defaultOptions_.push_back(std::pair<std::string, std::string>(opt, val));
    return true;
}

bool SceneDefaultOptions::setup(){
    const std::map<std::string, Scene *> &scenes = Benchmark::sceneMap();
    for (std::list<std::pair<std::string, std::string> >::const_iterator iter = defaultOptions_.begin(); iter != defaultOptions_.end(); iter++){
        for (std::map<std::string, Scene *>::const_iterator scene_iter = scenes.begin(); scene_iter != scenes.end(); scene_iter++){
            Scene &scene = *(scene_iter->second);
            /* 
             * Display warning only if the option value is unsupported, not if
             * the scene doesn't support the option at all.
             */
            if (!scene.set_option_default(iter->first, iter->second) &&
                scene.options().find(iter->first) != scene.options().end())
            {
                Log::info("Warning: Scene doesn't accept default value for option \n");
            }
        }
    }

    return true;
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void SceneDefaultOptions::draw(){
            // input
        // -----
        processInput(window_);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window_);
        glfwPollEvents();
}

void SceneDefaultOptions::print(){////for test
    std::cout<<"window_:"<<window_<<std::endl;
    std::cout<<"name_:"<<name_<<std::endl;
    std::cout<<"startTime_:"<<startTime_<<std::endl;
    std::cout<<"lastUpdateTime_:"<<lastUpdateTime_<<std::endl;
    std::cout<<"currentFrame_:"<<currentFrame_<<std::endl;
    std::cout<<options_["show-fps"].acceptable_values[1]<<std::endl;
}