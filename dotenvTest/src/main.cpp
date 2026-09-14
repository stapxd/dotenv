#include <iostream>
#include "dotenv.h"
#include "converter.h"

int main() {
    dotenv::config(".env");

    std::string key = "NODE_ENV";
    const std::string& value = dotenv::get(key);

    if (!value.empty()) {
        std::cout << key << " = " << value << std::endl;
    } else {
        std::cout << key << " not found in .env file." << std::endl;
    }


    std::cout << "\n\n\n\n\n";
    try {
        std::cout << convert::str_to_int(dotenv::get("POSTGRES_PORT")) << "\n";

        std::cout << convert::str_to_int(dotenv::get("SOME_FLOAT")) << "\n";

        std::cout << convert::str_to_float(dotenv::get("SOME_FLOAT")) << "\n";

        std::cout << convert::str_to_int(dotenv::get("NODE_ENV")) << "\n";
    }
    catch (std::string err) {
        std::cout << err << "\n";
    }
    return 0;
}