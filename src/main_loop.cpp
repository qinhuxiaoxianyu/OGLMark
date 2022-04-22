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
            if (!scene_->running()){
                if (!scene_->supported(false))
                    scene_setup_status_ = SceneSetupStatusUnsupported;
                else
                    scene_setup_status_ = SceneSetupStatusFailure;
            }
            else {
                scene_setup_status_ = SceneSetupStatusSuccess;
            }
            //todo something
            //after_scene_setup();log_scene_info();
        }
        else {
            return false;
        }
    }

    //bool should_quit = canvas_.should_quit();
    //processInput(window);

    if (scene_ ->running() /*&& !should_quit*/)
        draw();

    return true;
}

void MainLoop::draw(){
    //window_.clear();

    scene_->draw();
    scene_->update();

    //window_.update();
}