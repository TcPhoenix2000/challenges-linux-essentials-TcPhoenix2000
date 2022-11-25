#include <iostream>
#include <string>
#pragma once
#include <string>
namespace hex{
    class Converter{
        public:
            Converter();
            std::string hexConverter(int value);
            void decConverter(int value);

        //     std::string DexToHecConverter(std::string string);
        //     std::string HexToDecConverter(std::string string);
        // private:
        //     std::string stringParser(std::string string);
    };
}