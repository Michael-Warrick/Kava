#pragma once

#include <iostream>
#include <string>

class Debug
{
public:
    explicit Debug() = default;
    ~Debug() = default;

    static void Log(const std::string &message);
private:
    /* data */
};
