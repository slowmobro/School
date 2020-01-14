#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() 
{
    for(int i=0;i<40;i++) cout<<"-";
    string str = "Hello World!";
    int console_width = 40;// Width of console at Sololearn.
    int len = str.length();// Length of string.
    if(len%2==0) str += " ";
    cout<<setw((console_width/2)+len/2)\
    <<right<<str<<endl;
    for(int i=0;i<40;i++) cout<<"-";
}