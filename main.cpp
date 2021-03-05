//
// Created by Johannes Martin on 03.03.21.
//

#include <string>

#include "cxxopts.hpp"
#include "ConfigParser/ConfigParser.h"
#include "Logger/Logger.h"
#include "ProgressBar/ProgressBar.h"
#include "Timer/Timer.h"

structlog LOGCFG = {};

const std::string &TIMER_MODE_KEY { "timer" };
const std::string &PROGRESS_MODE_KEY { "progress-bar" };
const std::string &CONFIG_MODE_KEY { "config-parser" };

int main(int argc, char **argv){

    // initialize logger
    LOGCFG.headers = true;
    LOGCFG.level = INFO;

    // parse the configuration file
    ConfigParser confP {ConfigParser("ConfigParser/resources/config.json")};

    Logger(DEBUG) << "Version: " << confP.getVal<std::string>("info.version");
    std::string contribStr { "Contributors: " };
    for (auto contrib: confP.getList<std::string>("info.contributors")){
        contribStr += contrib + ", ";
    }
    Logger(DEBUG) << contribStr.substr(0, contribStr.size()-2);

    // initialize command line arguments parser
    cxxopts::Options options(confP.getVal<std::string>("program"), confP.getVal<std::string>("description"));

    auto timerMod = confP.getObj("modes."+TIMER_MODE_KEY);
    auto progressMod = confP.getObj("modes."+PROGRESS_MODE_KEY);
    auto configMod = confP.getObj("modes."+CONFIG_MODE_KEY);
    // generate usage modes from config file
    options.add_options()
            (timerMod.getVal<std::string>("opt")+","+TIMER_MODE_KEY,
                    timerMod.getVal<std::string>("description"))
            (progressMod.getVal<std::string>("opt")+","+PROGRESS_MODE_KEY,
                    progressMod.getVal<std::string>("description"))
            (configMod.getVal<std::string>("opt")+","+CONFIG_MODE_KEY,
                    configMod.getVal<std::string>("description"))
            ("h,help", "Show this help");

    // read command line arguments
    auto opts = options.parse(argc, argv);

    // print help on usage and exit, also do this when no options are specified
    if (opts.count("help") || argc < 2)
    {
        Logger(INFO) << options.help();
        exit(0);
    }

    if (opts.count(TIMER_MODE_KEY)){
        Logger(WARN) << "Demonstrator for 'Timer' not implemented yed. - Doing nothing.";
    }

    if (opts.count(PROGRESS_MODE_KEY)){
        Logger(WARN) << "Demonstrator for 'Progress' not implemented yed. - Doing nothing.";
    }

    if (opts.count(CONFIG_MODE_KEY)){
        std::string utilInfo {""};
        for(auto module: confP.getObjList("utils")){
            utilInfo += module.getVal<std::string>("module") + ": "
                    + module.getVal<std::string>("description");
            Logger(INFO) << utilInfo;
            utilInfo = "";
        }
    }
}

