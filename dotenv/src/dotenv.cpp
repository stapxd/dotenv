#include "dotenv.h"

#include <fstream>

std::unordered_map<std::string, std::string> dotenv::m_Env;

void dotenv::config(const std::string& path) 
{
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find('=');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            m_Env[key] = value;
        }
    }
}

const std::string& dotenv::get(const std::string& key) 
{
    auto it = m_Env.find(key);
    if (it != m_Env.end()) {
        return it->second;
    }
    static const std::string empty;
    return empty;
}
