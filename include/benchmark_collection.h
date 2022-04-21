#ifndef BENCHMARK_COLLECTION_H_
#define BENCHMARK_COLLECTION_H_

#include <vector>
#include <string>

#include "benchmark.h"

class BenchmarkCollection
{
public:
    BenchmarkCollection(/* args */)=default;
    ~BenchmarkCollection()=default;

    void add(const std::vector<std::string> &benchmarks);

    void populate_from_options();
    bool needs_decoration();

    const std::vector<Benchmark *>& benchmarks();

    void print();//fortest
private:
    bool benchmarks_contain_normal_scenes();
    /* data */
    std::vector<Benchmark *> benchmarks_;
};

#endif