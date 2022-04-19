#ifndef SCENE_H_
#define SCENE_H_

#include <string>
#include <vector>
#include <map>

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
protected:
    GLFWwindow* window_;
    std::string name_;
    std::map<std::string, Option> options_;
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

#endif