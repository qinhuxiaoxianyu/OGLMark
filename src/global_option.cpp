#include <iostream>

#include "global_option.h"

int GlobalOption::width = 800;//类的静态成员变量需要在类外分配内存空间
int GlobalOption::height = 600;

bool GlobalOption::parse_args(int argc, char **argv){
    //
    return true;
}

void GlobalOption::print_help(){
    std::cout<<"this is help"<<std::endl;
}