#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <iostream>
#include <fstream>
#include <string>

class ConfigParser {
public:
    ConfigParser(std::string file);
    ~ConfigParser();
};

#endif //CONFIGPARSER_H
