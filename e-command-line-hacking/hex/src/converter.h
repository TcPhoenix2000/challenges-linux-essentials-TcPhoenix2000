#pragma once
#include <string>
namespace hex{
    class Converter{
        public:
            Converter();
            std::string hexConverter(int value);
            void decConverter(int value);
    };
}