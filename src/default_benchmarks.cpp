#include "default_benchmarks.h"

std::vector<std::string> DefaultBenchmarks::default_benchmarks;

void DefaultBenchmarks::populate(){
    default_benchmarks.push_back("default blank!");
}

const std::vector<std::string>& DefaultBenchmarks::get(){
    if (default_benchmarks.empty())
        populate();

    return default_benchmarks;
}