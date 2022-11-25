// compile with g++ main.cpp -o hex
// run with :  hex
#include <iostream>
#include <string>
#include "cxxopts.hpp"
#include "converter.h"

#define VERSION "0.0.1"

using namespace hex;
using namespace std;

Converter converter;

int main(int argc, const char* argv[]){
    cxxopts::Options options("Hex", "convert decimal numbers to there hex value\n");

    options.add_options()
    ("v,version","print version")
    ("h,help","print usage")
    ("p,prefix","TODO", cxxopts::value<bool>()->default_value("false"))
    ("d,decimal","TODO", cxxopts::value<bool>()->default_value("false"))
    ;
    //("d,debug", "Enable debugging") // a bool parameter
    //("i,integer", "Int param", cxxopts::value<int>())
    //("f,file", "File name", cxxopts::value<std::string>())
    //("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))

    auto result = options.parse(argc, argv);

    if (result.count("help")){
        cout << options.help()<< endl;
        exit(0); 
    }
    if (result.count("version")){
        cout << "hex version: "<< VERSION << endl;
        exit(0);
    }
    bool prefix = result["prefix"].as<bool>();
    bool decimal = result["decimal"].as<bool>();

    string str;
    string delim = " ";
    vector<string> words{};
    size_t pos = 0;
    int num;
    
    //cout << "welcome to Hex to convert all you decimal numbers to there hex value :" << endl;

    ////test string
    //this is a this is a2 t2st to see if this 16 sure would work
    while(true){
        str="";
        getline (cin,str);
        str=str +" ";

        /// this is to handle hex to decimal conversion from string including spaces and decimal numbers 
        while ((pos = str.find(delim)) != string::npos) {
            words.push_back(str.substr(0, pos));
            str.erase(0, pos + delim.length());
        }
        for (const auto &str : words ) {
            if (str >= "0" && str <="9") {
                if (str>="a"&& str<="f"){}
                num = stoi(str);
                cout <<"0x"<< converter.hexConverter(num)<<" ";
            }else{
                cout << str <<" ";
            }
        }
        cout << endl;
        words.clear();
    }

    cerr << "oh oh, something went wrong" << endl;
    return -1;
}