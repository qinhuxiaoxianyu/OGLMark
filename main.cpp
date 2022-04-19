#include <iostream>
#include <string>

//#include <glad/glad.h>//暂时用一下
#include <GLFW/glfw3.h>

#include "global_option.h"
#include "create_window.h"
#include "log.h"
#include "scene_collection.h"

void processInput(GLFWwindow *window);

int main(int argc, char *argv[]){
    if (!GlobalOption::parse_args(argc,argv)){
        Log::info("error!");
        return -1;
    }
    else{
        Log::info("succed!");    
    }

    GlobalOption::print_help();
    
    GLFWwindow* window = create_window(GlobalOption::width, GlobalOption::height);
    if (window == nullptr){
        Log::info("Failed to create GLFW window");
        return -1;
    }

    SceneCollection scenes(window);

















    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();

    return 0;
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}