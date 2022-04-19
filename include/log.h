#ifndef LOG_H_
#define LOG_H_

#include <string>

class Log{
private:
    /* data */
public:
    Log(/* args */)=default;
    ~Log()=default;

    static void info(std::string info);

};

#endif