#include <iostream>
#include <string>

//#include <glad/glad.h>//暂时用一下
#include <GLFW/glfw3.h>

#include "global_option.h"
#include "create_window.h"
#include "log.h"
#include "scene_collection.h"
#include "benchmark.h"
#include "benchmark_collection.h"
#include "main_loop.h"

//void processInput(GLFWwindow *window);
void do_benchmark(GLFWwindow *window);

int main(int argc, char *argv[]){
    if (!GlobalOption::parse_args(argc,argv)){
        return -1;
    }

    GlobalOption::print_help();
    
    GLFWwindow* window = create_window(GlobalOption::width, GlobalOption::height);
    if (window == nullptr){
        Log::info("Failed to create GLFW window");
        return -1;
    }

    SceneCollection scenes(window);
    scenes.register_scenes();
    //Benchmark::print();
    //scenes.print();

    do_benchmark(window);














/*
    while (!glfwWindowShouldClose(window))
    {

    }
    */
    //glfwTerminate();

    return 0;
}



void do_benchmark(GLFWwindow *window){
    BenchmarkCollection benchmark_collection;
    MainLoop *loop;

    benchmark_collection.populate_from_options();
    //benchmark_collection.print();//fortest

    if (benchmark_collection.needs_decoration())
        ;//todo something
    else   
        loop = new MainLoop(window, benchmark_collection.benchmarks());

    while (loop->step());
}