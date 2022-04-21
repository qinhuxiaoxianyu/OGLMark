#include <iostream>

#include "benchmark_collection.h"
#include "default_benchmarks.h"

void BenchmarkCollection::add(const std::vector<std::string> &benchmarks){
    for (std::vector<std::string>::const_iterator iter = benchmarks.begin(); iter != benchmarks.end(); iter++){
        benchmarks_.push_back(new Benchmark(*iter));
    }
}

void BenchmarkCollection::populate_from_options(){
    if (true){
        //annotate
    }

    if (true){
        //globaloption::benchmakrs
    }

    if (true){
        //globaloption::benchmark_files
    } 

    if (!benchmarks_contain_normal_scenes()){
        add(DefaultBenchmarks::get());
    }
}

bool BenchmarkCollection::needs_decoration(){
    for (std::vector<Benchmark *>::const_iterator iter = benchmarks_.begin(); iter != benchmarks_.end(); iter++){
        //todo something
    }
    return false;
}

const std::vector<Benchmark *>& BenchmarkCollection::benchmarks(){
    return benchmarks_;
}

void BenchmarkCollection::print(){
    //std::cout<<"here!"<<std::endl;
    benchmarks_[0]->print();
}

bool BenchmarkCollection::benchmarks_contain_normal_scenes(){
    for (std::vector<Benchmark *>::const_iterator iter = benchmarks_.begin(); iter != benchmarks_.end(); iter++){
        //
        return true;
    }
    return false;
}