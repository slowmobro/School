#ifndef ROMANNUMERAL_H
#define ROMANNUMERAL_H

#include <string>
using namespace std;

class romanType
{
public:
//Constructor
//Sets default values of both romanNum to 'I' and num to 1
romanType();
//print function to output the integer value of the roman numeral after conversion
void printPositiveInteger() const;
//print function to output the roman numeral value stored in the romanNum string
void printRoman() const;
//Constructor
//Takes a string as an argument and sets romanNum to the value of the string then 
//calls the romanToPositiveInteger function to be converted to decimal format   
romanType(string);
//Sets roman numeral to the string value and calls romanToPostiveInteger function
void setRoman(string);
//Converts roman numeral to an integer
void romanToPositiveInteger();

private:
    string romanNum; //String var stores roman numeral version of num
    int num; //Int variable stores value of the roman numeral
};

#endif