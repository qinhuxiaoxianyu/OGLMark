#include <iostream>
#include <getopt.h>
#include <cstring>

#include "global_option.h"

std::vector<std::string> GlobalOption::benchmarks;
std::vector<std::string> GlobalOption::benchmark_files;
bool GlobalOption::validate = false;
std::string GlobalOption::data_path = std::string(""/*GLMARK_DATA_PATH*/);
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

/*int GlobalOption::width = 800;//类的静态成员变量需要在类外分配内存空间
int GlobalOption::height = 600;
*/
static struct option long_options[] = {
    {"benchmark", required_argument , nullptr, 'b'},
    {"benchmark-file", required_argument , nullptr, 'f'},
    {"validate", no_argument, nullptr, 'v'},
    {"data-path", required_argument , nullptr, 'P'},
    {"frame-end", required_argument , nullptr, 'm'},
    {"off-screen", no_argument, nullptr, 'o'},
    {"visual-config", required_argument , nullptr, 'C'},
    {"reuse-context", no_argument, nullptr, 'R'},
    {"size", required_argument, nullptr, 's'},
    {"fullscreen", no_argument, nullptr, 'F'},
    {"list-scenes", no_argument, nullptr, 'l'},
    {"show-all-options", no_argument, nullptr, 'S'},
    {"run-forever", no_argument, nullptr, 'r'},
    {"annotate", no_argument, nullptr, 'a'},
    {"debug", no_argument, nullptr, 'd'},
    {"help", no_argument, nullptr, 'h'},
    {0, 0, 0, 0}
};

static GlobalOption::FrameEnd frame_end_from_str(const std::string &str){
    GlobalOption::FrameEnd m = GlobalOption::FrameEndDefault;
    if (str == "swap")
        m = GlobalOption::FrameEndSwap;
    else if (str == "finish")
        m = GlobalOption::FrameEndFinish;
    else if (str == "readpixels")
        m = GlobalOption::FrameEndReadPixels;
    else if (str == "none")
        m = GlobalOption::FrameEndNone;
    return m;
}

static void parse_size(const std::string& str, std::pair<int, int>& size){
    /*std::vector*/
    //todo something
}

bool GlobalOption::parse_args(int argc, char **argv){
    int option_index = -1;
    int c = 0;//getopt_long返回值是int类型
    const char* optname = "";
    while (c != -1){
        c = getopt_long(argc, argv, "b:f:vP:M:oC:rs:FlSradh", long_options, &option_index);

        switch (c){
        case 0:
            /*
            optname = long_options[option_index].name;//如果处理短命令，option_index会是啥？
            if (strcmp(optname, "a name of long option without short option") == 0){
                //todo something
            }//else if
            */
            break;
        case 'b': GlobalOption::benchmarks.push_back(optarg);break;
        case 'f': GlobalOption::benchmark_files.push_back(optarg);break;
        case 'v': GlobalOption::validate = true;break;
        case 'P': GlobalOption::data_path = optarg;break;
        case 'm': GlobalOption::frame_end = frame_end_from_str(optarg);break;
        case 'o': GlobalOption::offscreen = true;break;
        case 'C': /*GlobalOption::visual_config = GLVisualConfig(optarg);*/break;
        case 'R': GlobalOption::reuse_context = true;break;
        case 's': parse_size(optarg, GlobalOption::size);break;
        case 'F': GlobalOption::size = std::pair<int, int>(-1, -1);break;
        case 'l': GlobalOption::list_scenes = true;break;
        case 'S': GlobalOption::show_all_options = true;break;
        case 'r': GlobalOption::run_forever = true;break;
        case 'a': GlobalOption::annotate = true;break;
        case 'd': GlobalOption::show_debug = true;break;
        case 'h': GlobalOption::show_help = true;break;
        case '?':
        case ':':
        default:
            return false;
        }
    }
    return true;
}

void GlobalOption::print_help(){
    std::cout<<"A benchmark for Open GL (ES) 2.0\n"
           "\n"
           "Options:\n"
           "  -b, --benchmark BENCH  A benchmark or options to run: '(scene)?(:opt1=val1)*'\n"
           "                         (the option can be used multiple times)\n"
           "  -f, --benchmark-file F Load benchmarks to run from a file containing a\n"
           "                         list of benchmark descriptions (one per line)\n"
           "                         (the option can be used multiple times)\n"
           "  -v, --validate         Run a quick output validation test instead of \n"
           "                         running the benchmarks\n"
           "  -P, --data-path PATH   Path to glmark2 models, shaders and textures\n"
           "                         Default: " /*GLMARK_DATA_PATH*/ "\n"
           "  -m, --frame-end METHOD How to end a frame [default,none,swap,finish,readpixels]\n"
           "  -o, --off-screen       Render to an off-screen surface\n"
           "  -C, --visual-config C  The visual configuration to use for the rendering\n"
           "                         target: 'red=R:green=G:blue=B:alpha=A:buffer=BUF'.\n"
           "                         The parameters may be defined in any order, and any\n"
           "                         omitted parameters assume a default value of '1'\n"
           "  -R, --reuse-context    Use a single context for all scenes\n"
           "                         (by default, each scene gets its own context)\n"
           "  -s, --size WxH         Size of the output window (default: 800x600)\n"
           "  -F, --fullscreen       Run in fullscreen mode (equivalent to --size -1x-1)\n"
           "  -l, --list-scenes      Display information about the available scenes\n"
           "                         and their options\n"
           "  -S, --show-all-options Show all scene option values used for benchmarks\n"
           "                         (only explicitly set options are shown by default)\n"
           "  -r, --run-forever      Run indefinitely, looping from the last benchmark\n"
           "                         back to the first\n"
           "  -a, --annotate         Annotate the benchmarks with on-screen information\n"
           "                         (same as -b :show-fps=true:title=#info#)\n"
           "  -d, --debug            Display debug messages\n"
           "  -h, --help             Display help\n";
}