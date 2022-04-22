#include "scene.h"

Scene::Option::Option(const std::string &nam, const std::string &val, const std::string &desc,
    const std::string &values):name(nam), value(val), default_value(val), description(desc),
    set(false){//函数声明时可以有默认值，定义时不能有
    //todo something about acceptabel_values
    acceptable_values.push_back("value one");//util::split
    acceptable_values.push_back("value two");
    acceptable_values.push_back("value three");
}

bool Scene::supported(bool show_errors){
    static_cast<void>(show_errors);
    return true;
}

bool Scene::load(){
    return true;
}

bool Scene::setup(){
    return true;
}

void Scene::update(){
    //todo somethingScene::
}

void Scene::draw(){
    //nothing
}

bool Scene::set_option(const std::string &opt, const std::string &val){
    std::map<std::string, Option>::iterator iter = options_.find(opt);

    if (iter == options_.end())
        return false;

    std::vector<std::string>& values(iter->second.acceptable_values);

    if (!values.empty() && std::find(values.begin(), values.end(), val) == values.end()){
        return false;
    }

    iter->second.value = val;
    iter->second.set = true;

    return true;
}

bool Scene::running(){
    return running_;
}

const std::string& Scene::name(){
    return name_;
}

void Scene::reset_options(){
    Option *opt = nullptr;
    for (std::map<std::string, Option>::iterator iter = options_.begin(); iter != options_.end(); iter++){
        opt = &(iter->second);

        opt->value = opt->default_value;
        opt->set = false;
    }
}

bool Scene::set_option_default(const std::string &opt, const std::string &val){
    std::map<std::string, Scene::Option>::iterator iter = options_.find(opt);

    if (iter == options_.end())
        return false;

    std::vector<std::string> &values = iter->second.acceptable_values;

    if (!values.empty() && 
        std::find(values.begin(), values.end(), val) == values.end())
    {
            return false;
    }

    iter->second.default_value = val;

    return true;   
}

const std::map<std::string, Scene::Option>& Scene::options(){
    return options_;
}

Scene::Scene(GLFWwindow* window, const std::string &name):
    window_(window), name_(name), startTime_(0), lastUpdateTime_(0), currentFrame_(0), running_(0),
    duration_(0), nframes_(0){
    options_["duration"] = Option("duration", "10.0",
                                         "The duration of each benchmark in seconds");
    options_["nframes"] = Option("nframes", "",
                                         "The number of frames to render");
    options_["vertex-precision"] = Option("vertex-precision",
                                                 "default,default,default,default",
                                                 "The precision values for the vertex shader (\"int,float,sampler2d,samplercube\")");
    options_["fragment-precision"] = Option("fragment-precision",
                                                   "default,default,default,default",
                                                   "The precision values for the fragment shader (\"int,float,sampler2d,samplercube\")");
    /* FPS options */
    options_["show-fps"] = Option("show-fps", "false",
                                         "Show live FPS counter",
                                         "false,true");
    options_["fps-pos"] = Option("fps-pos", "-1.0,-1.0",
                                         "The position on screen where to show FPS");
    options_["fps-size"] = Option("fps-size", "0.03",
                                         "The width of each glyph for the FPS");
    /* Title options */
    options_["title"] = Option("title", "",
                                      "The scene title to show");
    options_["title-pos"] = Option("title-pos", "-0.7,-1.0",
                                      "The position on screen where to show the title");
    options_["title-size"] = Option("title-size", "0.03",
                                           "The width of each glyph in the title");
}

Scene::~Scene(){//不做任何事
}
