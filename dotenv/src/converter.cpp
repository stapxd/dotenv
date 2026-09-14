#include "converter.h"

#include <iostream>
#include <charconv>

int convert::str_to_int(const std::string& str)
{
    int result{};
    auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), result);

    if (ec == std::errc())
        return result;

    return -1;
}

float convert::str_to_float(const std::string& str) {
    float result{};
    auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), result);

    if (ec == std::errc())
        return result;

    return -1;
}
