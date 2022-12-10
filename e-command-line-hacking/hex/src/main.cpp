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
    ("d,decimal","convert hex numbers to there decimal value", cxxopts::value<bool>()->default_value("false"))
    ("f,file", "File name  TODO", cxxopts::value<std::string>())
    ;
    //("d,debug", "Enable debugging") // a bool parameter
    //("i,integer", "Int param", cxxopts::value<int>())
    //("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))

    auto res = options.parse(argc, argv);

    if (res.count("help")){
        cout << options.help()<< endl;
        exit(0); 
    }
    if (res.count("version")){
        cout << "hex version: "<< VERSION << endl;
        exit(0);
    }
    bool decimal = res["decimal"].as<bool>();

    string str,str2,delim = " ";
    vector<string> words{};
    size_t pos = 0;
    int num;
    
    ////test string
    //this is a this is a2 t2st to see if this 16 sure would work
    string result;
    Converter Convert;
    while(true){
        str="";
        getline (cin,str);
        if (std::cin.eof()==1) {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        str=str +" ";
        str2="0x";

        while ((pos = str.find(delim)) != string::npos) {
            words.push_back(str.substr(0, pos));
            str.erase(0, pos + delim.length());
        }

        if (!decimal) {
            cout << "welcome to Hex to convert all you decimal numbers to there hex value :" << endl;
            /// this is to handle hex to decimal conversion from string including spaces and decimal numbers
            for (const auto &str : words ) {
                if (str >= "0" && str <="9") {
                    if (str>="a"&& str<="f"){}
                    num = stoi(str);
                    cout <<"0x"<< converter.hexConverter(num)<<" ";
                }
                else{
                    cout << str <<" ";
                }
            }
        }
        else{
            cout << "welcome to Hex to convert all you hex numbers to there decimal value :" << endl;
            /// this is to handle decimal to hex conversion from string including spaces and hex numbers  
            for (const auto &str : words ) {
                if (str.find(str2) != string::npos) {
                    str.substr(2);
                    cout << converter.decConverter(str)<<" ";
                }
                else{
                    cout << str <<" ";
                }
            }
        }
        cout << endl;
        words.clear();

    }

    cerr << "oh oh, something went wrong" << endl;
    return -1;
}