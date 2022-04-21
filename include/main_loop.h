#ifndef MAIN_LOOP_H_
#define MAIN_LOOP_H_

#include <vector>

#include <GLFW/glfw3.h>

#include "benchmark.h"
#include "scene.h"

class MainLoop
{
public:
    MainLoop(GLFWwindow *window, const std::vector<Benchmark *> &benchmarks);
    virtual ~MainLoop()=default;

    virtual void before_scene_setup();
    void reset();
    bool step();
protected:
    enum SceneSetupStatus {
        SceneSetupStatusUnknown,
        SceneSetupStatusSuccess,
        SceneSetupStatusFailure,
        SceneSetupStatusUnsupported
    };
    /* data */
    GLFWwindow* window_;
    const std::vector<Benchmark *> &benchmarks_;
    Scene *scene_;
    SceneSetupStatus scene_setup_status_;
    unsigned int score_;
    unsigned int benchmarks_run_;
    std::vector<Benchmark *>::const_iterator bench_iter_;
private:
};


#endif