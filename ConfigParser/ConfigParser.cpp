#include "ConfigParser.h"

ConfigParser::ConfigParser() : ConfigParser(static_cast<std::string>(ConfigParser::DEFAULT_CONFIG_FILE)){}

ConfigParser::ConfigParser(const std::string &file){
    // Parse the XML into the property tree.
    boost::property_tree::read_json(file, tree);
}

ConfigParser::ConfigParser(const boost::property_tree::ptree &subtree) : tree { subtree } {}

ConfigParser ConfigParser::getObj(const std::string &key){
    return ConfigParser(tree.get_child(key));
}

std::list<ConfigParser> ConfigParser::getObjList(const std::string &key) {
    std::list <ConfigParser> lst_;
    BOOST_FOREACH(const boost::property_tree::ptree::value_type &val,tree.get_child(key))
    {
        if(val.second.empty()){
            std::cerr << "List does not contain objects. Please use 'getList<T>(const std::string &key)'instead."
                                  << " - Returning empty list." << std::endl;
        } else {
            // storing instances of ConfigParsers each containing a subtree instead
            lst_.push_back(ConfigParser(val.second.get_child("")));
        }
    }
    return lst_;
}