#include <iostream>
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
}
string Converter::decConverter(string value){

   int len = value.length();
   int base = 1;
   int temp = 0;
   for (int i=len-1; i>=0; i--) {
      if (value[i]>='0' && value[i]<='9') {
         temp += (value[i] - 48)*base;
         base = base * 16;
      }
      else if (value[i]>='A' && value[i]<='F') {
         temp += (value[i] - 55)*base;
         base = base*16;
      }
   }
   string str = to_string(temp);
   return str;
}

