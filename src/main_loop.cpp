#include "main_loop.h"

MainLoop::MainLoop(GLFWwindow *window, const std::vector<Benchmark *> &benchmarks):
    window_(window), benchmarks_(benchmarks){
    reset();
}

void MainLoop::before_scene_setup(){}

void MainLoop::reset(){
    scene_ = 0;
    scene_setup_status_ = SceneSetupStatusUnknown;
    score_ = 0;
    benchmarks_run_ = 0;
    bench_iter_ = benchmarks_.begin();
}

bool MainLoop::step(){
    if (!scene_){
        while (bench_iter_ != benchmarks_.end()){
            scene_ = &((*bench_iter_)->scene());

            if (scene_->name().empty())
                ;//(*bench_iter_)->setup_scene();
            else
                break;
            //next_benchmark();
        }

        if (bench_iter_ != benchmarks_.end()){
            before_scene_setup();
            /* if (!Options::reuse_context)
                canvas_.reset();*/
            scene_ = &((*bench_iter_)->setup_scene());
        }
    }
}