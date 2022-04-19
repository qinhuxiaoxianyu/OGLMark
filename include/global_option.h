#ifndef GLOBAL_OPTION_H_
#define GLOBAL_OPTION_H_

class GlobalOption{
private:
    /* data */
public:
    GlobalOption(/* args */)=default;
    ~GlobalOption()=default;

    static int width;//屏幕宽
    static int height;//屏幕高

    static bool parse_args(int argc, char **argv);
    static void print_help();
};

#endif