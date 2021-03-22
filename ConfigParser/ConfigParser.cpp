#include "ConfigParser.h"

ConfigParser::ConfigParser(const std::string &file){
    // Extract the file extension from the filename
    std::string ext = boost::filesystem::extension(file);
    // use the right parser depending on the file extension and store the parsed file in tree
    if (ext == ".json") {
        boost::property_tree::read_json(file, tree);
    } else if (ext == ".info"){
        boost::property_tree::read_info(file, tree);
    } else if (ext == ".ini") {
        boost::property_tree::read_ini(file, tree);
    } else if (ext == ".xml"){
        boost::property_tree::read_xml(file, tree);
    } else {
        throw std::invalid_argument("Unsupported file extension '" + ext
                                    + "'. File '" + file + "' can't be read by ConfigParser.");
    }
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
            throw std::runtime_error("List does not contain objects. "
                                     "Use 'getList<T>(const std::string &key)' instead. - Returning empty list.");
        } else {
            // storing instances of ConfigParsers each containing a subtree instead
            lst_.push_back(ConfigParser(val.second.get_child("")));
        }
    }
    return lst_;
}