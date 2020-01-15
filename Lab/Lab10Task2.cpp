#include <iostream>
#include <string>
#include "romanNumeral.h"
#include "romanNumeral.cpp"

using namespace std;

int main()
{
    //Declare variables 
    romanType roman;

    string romanString;

    //Request input of a roman numeral and assign and store it to a string
    cout << "Enter a number in Roman numeral format: ";
    cin >> romanString;
    cout << endl;

    roman.setRoman(romanString); //Call the conversion process

    //Output the original roman numeral and its converted value
    cout << "The converted value of Roman numeral " << romanString << " is ";
    roman.printPositiveInteger();
    cout << endl;

    return 0;
}