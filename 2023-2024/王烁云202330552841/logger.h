// logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <string>

//日志类用来记录用户操作
class Logger {
public:
    static void log(const std::string& message);
};

#endif