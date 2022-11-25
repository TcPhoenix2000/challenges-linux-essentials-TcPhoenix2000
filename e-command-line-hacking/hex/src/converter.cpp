#include "converter.h"
#include <string>
// #include <iostream>

using namespace hex;
using namespace std;

Converter::Converter(){

};
string Converter::hexConverter(int num){
    int  rem, i=0;
    char hex[50];
    string str;
    while(num!=0)
    {
        rem = num%16;
        if(rem<10)
            rem = rem+48;
        else
            rem = rem+55;
        hex[i] = rem;
        i++;
        num = num/16;
    }
    for(i=i-1; i>=0; i--){
        str = str+hex[i];
    }
        return str;
};
void Converter::decConverter(int value){

};