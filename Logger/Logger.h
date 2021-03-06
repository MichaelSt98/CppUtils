#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

#include "Color.h"

enum typelog {
    DEBUG,
    INFO,
    WARN,
    ERROR
};

struct structlog {
    bool headers = false;
    typelog level = WARN;
};

extern structlog LOGCFG;

class Logger {
public:
    Logger() {}
    Logger(typelog type);
    ~Logger();

    template<class T> Logger &operator<<(const T &msg) {
        if(msglevel >= LOGCFG.level) {
            std::cout << msg;
            opened = true;
        }
        return *this;
    }

private:
    bool opened = false;
    typelog msglevel = DEBUG;
    inline std::string getLabel(typelog type);
    inline Color::Modifier getColor(typelog type);
};

#endif //LOGGER_H
