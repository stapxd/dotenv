#include <iostream>
#include "dotenv.h"

int main() {
    dotenv::config(".env");

    std::string key = "POSTGRES_USER";
    const std::string& value = dotenv::get(key);

    if (!value.empty()) {
        std::cout << key << " = " << value << std::endl;
    } else {
        std::cout << key << " not found in .env file." << std::endl;
    }

    return 0;
}