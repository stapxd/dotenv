#pragma once

#include <unordered_map>
#include <string>

class dotenv {
public:
    static void config(const std::string& path = ".env");
    static const std::string& get(const std::string& key);

private:
    dotenv() = default;
    ~dotenv() = default;

    static std::unordered_map<std::string, std::string> m_Env;

};