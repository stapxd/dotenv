#include "dotenv.h"
#include "core.h"

#include <fstream>

std::unordered_map<std::string, std::string> dotenv::m_Env;

void dotenv::config(const std::string& path) 
{
    std::ifstream file(path);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            size_t commentPos = line.find('#');
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string value = "";
                if (commentPos != std::string::npos) {
                    size_t count = commentPos - pos;
                    value = line.substr(pos + 1, count - 1);
                }
                else
                    value = line.substr(pos + 1);
                m_Env[key] = value;
            }
        }
    }
    else {
        DOTENV_ERROR("Could not open .env file");
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
