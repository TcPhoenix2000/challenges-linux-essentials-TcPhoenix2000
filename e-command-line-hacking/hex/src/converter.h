#include <iostream>
#include <string>
#pragma once
#include <string>
namespace hex{
    class Converter{
        public:
            Converter();
            std::string hexConverter(int value);
            std::string decConverter(std::string value);
    };
}