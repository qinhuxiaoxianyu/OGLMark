#ifndef DEFAULT_BENCHMARKS_H_
#define DEFAULT_BENCHMARKS_H_

#include <vector>
#include <string>

class DefaultBenchmarks
{
private:
    /* data */
    static std::vector<std::string> default_benchmarks;

    //static void populate(std::vector<std::string>& benchmarks);
    static void populate();
public:
    DefaultBenchmarks(/* args */)=default;
    ~DefaultBenchmarks()=default;

    static const std::vector<std::string>& get();
};


#endif