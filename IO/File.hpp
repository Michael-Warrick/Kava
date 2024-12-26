#pragma once

#include <iostream>
#include <fstream>
#include <vector>

namespace IO {
    class File {
    public:
        static std::vector<char> Read(const std::string &fileName);
    private:
    };
}