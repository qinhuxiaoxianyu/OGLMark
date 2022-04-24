#ifndef GLOBAL_OPTION_H_
#define GLOBAL_OPTION_H_

#include <string>
#include <vector>

class GlobalOption{
private:
    /* data */
public:
    GlobalOption(/* args */)=default;
    ~GlobalOption()=default;

    enum FrameEnd{
        FrameEndDefault,
        FrameEndNone,
        FrameEndSwap,
        FrameEndFinish,
        FrameEndReadPixels
    };
/*
    static int width;
    static int height;
*/
    static bool parse_args(int argc, char **argv);
    static void print_help();

    static std::vector<std::string> benchmarks;
    static std::vector<std::string> benchmark_files;
    static bool validate;
    static std::string data_path;
    static FrameEnd frame_end;
    static std::pair<int,int> size;
    static bool list_scenes;
    static bool show_all_options;
    static bool show_debug;
    static bool show_help;
    static bool reuse_context;
    static bool run_forever;
    static bool annotate;
    static bool offscreen;
    //static GLVisualConfig visual_config;
};

#endif