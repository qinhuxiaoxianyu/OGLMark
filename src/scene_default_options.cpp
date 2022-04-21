#include <iostream>

#include "scene.h"

SceneDefaultOptions::SceneDefaultOptions(GLFWwindow* window):Scene(window, "default blank!"){
}

void SceneDefaultOptions::print(){////for test
    std::cout<<"window_:"<<window_<<std::endl;
    std::cout<<"name_:"<<name_<<std::endl;
    std::cout<<"startTime_:"<<startTime_<<std::endl;
    std::cout<<"lastUpdateTime_:"<<lastUpdateTime_<<std::endl;
    std::cout<<"currentFrame_:"<<currentFrame_<<std::endl;
    std::cout<<options_["show-fps"].acceptable_values[1]<<std::endl;
}