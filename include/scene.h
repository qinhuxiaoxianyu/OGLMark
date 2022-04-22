#ifndef SCENE_H_
#define SCENE_H_

#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

#include <GLFW/glfw3.h>

class Scene{
public:
    virtual ~Scene();

    class Option{
    public:
        Option(const std::string &nam, const std::string &val, const std::string &desc,
            const std::string &values = "");
        Option()=default;

        std::string name;
        std::string value;
        std::string default_value;
        std::string description;
        std::vector<std::string> acceptable_values;
        bool set;
    };

    virtual bool supported(bool show_errors);
    virtual bool load();
    virtual bool setup();
    virtual void update();
    virtual void draw();
    virtual bool set_option(const std::string &opt, const std::string &val);
    bool running();
    const std::string &name();
    void reset_options();
    bool set_option_default(const std::string &opt, const std::string &val);
    const std::map<std::string, Option>& options();

    virtual void print(){}//for test

    std::map<std::string, Option> options_;//fortest
    std::string name_;//fortest
protected:
    GLFWwindow* window_;
    //std::string name_;
    //std::map<std::string, Option> options_;
    double startTime_;
    double lastUpdateTime_;
    unsigned currentFrame_;
    bool running_;
    double duration_;      // Duration of run in seconds
    unsigned nframes_;

    Scene(GLFWwindow* window, const std::string &name);
private:
    /* data */
};

class SceneDefaultOptions : public Scene
{
public:
    SceneDefaultOptions(GLFWwindow* window);
    ~SceneDefaultOptions()=default;
    bool set_option(const std::string &opt, const std::string &val);
    bool setup();
    void draw();
    void print();//for test
private:
    /* data */
    std::list<std::pair<std::string, std::string> > defaultOptions_;
};

#endif