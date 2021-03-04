//
// Created by Johannes Martin on 03.03.21.
//

#include "ConfigParser/ConfigParser.h"
#include "Logger/Logger.h"
#include "ProgressBar/ProgressBar.h"
#include "Timer/Timer.h"

#include "cxxopts.hpp"

structlog LOGCFG = {};

int main(int argc, char **argv){
    ConfigParser confP {ConfigParser("assets/config.conf")};
}

