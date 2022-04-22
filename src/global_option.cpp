#include <iostream>

#include "global_option.h"

std::vector<std::string> GlobalOption::benchmarks;
std::vector<std::string> GlobalOption::benchmark_files;
bool GlobalOption::validate = false;
//std::string GlobalOption::data_path = std::string(GLMARK_DATA_PATH);
GlobalOption::FrameEnd GlobalOption::frame_end = GlobalOption::FrameEndDefault;
std::pair<int,int> GlobalOption::size(800, 600);
bool GlobalOption::list_scenes = false;
bool GlobalOption::show_all_options = false;
bool GlobalOption::show_debug = false;
bool GlobalOption::show_help = false;
bool GlobalOption::reuse_context = false;
bool GlobalOption::run_forever = false;
bool GlobalOption::annotate = false;
bool GlobalOption::offscreen = false;
//GLVisualConfig GlobalOption::visual_config;

int GlobalOption::width = 800;//类的静态成员变量需要在类外分配内存空间
int GlobalOption::height = 600;

bool GlobalOption::parse_args(int argc, char **argv){
    //
    return true;
}

void GlobalOption::print_help(){
    std::cout<<"this is help"<<std::endl;
}