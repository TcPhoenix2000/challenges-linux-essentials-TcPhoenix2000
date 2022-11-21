#include <iostream>
#include <string>
#pragma once
namespace hex{
    class Converter{
        public:
            Converter();            
            std::string ConvertStr(std::string string);

        //     std::string DexToHecConverter(std::string string);
        //     std::string HexToDecConverter(std::string string);
        // private:
        //     std::string stringParser(std::string string);
    };
}