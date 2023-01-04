// compile with g++ main.cpp -o hex
// run with :  hex
#include <iostream>
#include <fstream>
#include <string>
#include "cxxopts.hpp"
#include "converter.h"

#define VERSION "0.0.1"

using namespace hex;
using namespace std;

Converter converter;
bool from_terminal = true;
void convert(bool decimal, const vector<string>& words,bool from_terminal) {
  if (from_terminal) {
    if (!decimal) {
      cout << "Welcome to Hex to convert all your decimal numbers to their hex value:" << endl;
    } else {
      cout << "Welcome to Hex to convert all your hex numbers to their decimal value:" << endl;
    }
  }
  if (!decimal) {
    for (const auto& str : words) {
      if (str >= "0" && str <= "9") {
        if (str >= "a" && str <= "f") {}
        int num = stoi(str);
        cout << "0x" << converter.hexConverter(num) << " ";
      } else {
        cout << str << " ";
      }
    }
  } else {
    for (const auto& str : words) {
      if (str.find("0x") != string::npos) {
        string hex_str = str.substr(2);
        cout << converter.decConverter(hex_str) << " ";
      } else {
        cout << str << " ";
      }
    }
  }
  cout << endl;
}

vector<string> split(const string& str) {
  vector<string> tokens;
  string token;
  istringstream token_stream(str);
  while (getline(token_stream, token, ' ')) {
    tokens.push_back(token);
  }
  return tokens;
}

int main(int argc, const char* argv[]){
  cxxopts::Options options("Hex", "convert decimal numbers to there hex value\n");

  options.add_options()
  ("v,version","print version")
  ("h,help","print usage")
  ("d,decimal","convert hex numbers to there decimal value", cxxopts::value<bool>()->default_value("false"))
  ("f,file", "arg File name as input file (this does not change input file but returns changed file output as echo in terminal)", cxxopts::value<std::string>())
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

  if (res.count("file")) {
      string filename = res["file"].as<string>();
      fstream input_file;
      input_file.open(filename, ios::out | ios::in);
      if (input_file.is_open()) {
        // Read the contents of the file and process it as needed.
        string line;
        while (getline(input_file, line)) {
        // Process the line
        vector<string> words = split(line);
        convert(decimal, words,false);
        if(input_file.eof()){
          exit(0);
        }
        }
      }else {
          cerr << "Error: Unable to open file '" << filename << "'" << endl;
      }
      // Close the file when finished
      input_file.close();
  }
  string str,str2,delim = " ";
  vector<string> words{};
  size_t pos = 0;
  
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
    cout << endl;
    words.clear();
  }
  cerr << "oh oh, something went wrong" << endl;
  return -1;
}
