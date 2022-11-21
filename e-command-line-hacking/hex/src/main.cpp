// compile with g++ main.cpp -o hex
// run with :  hex
#include <iostream>
#include <string>
#include "converter.h"

using namespace hex;
using namespace std;

int main(){
    string str;
    string result;
    Converter Convert;
    cout << "welcome to Hex to convert all you decimal numbers to there hex value :" << endl;
    while(true){
        getline (cin,str);
        cout << Convert.ConvertStr(str) <<endl;
    }

    cerr << "oh oh, something went wrong" << endl;
    return -1;
}