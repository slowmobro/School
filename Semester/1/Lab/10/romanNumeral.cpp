#include <iostream>
#include <string>
#include "romanNumeral.h"
using namespace std;

//Function to output the converted integer
void romanType::printPositiveInteger() const
{
    cout << num;
}

//Function to output the unconverted Roman numeral
void romanType::printRoman() const
{
    cout << romanNum;
}
//Function to set string variable of unconverted Roman numeral
//and call the conversion function
void romanType::setRoman(string rString)
{
    romanNum = rString;
    romanToPositiveInteger();
}
//Function to convert roman numeral string to integer formant
void romanType::romanToPositiveInteger()
{
    int sum = 0; //Stores total value of the roman numerals

    int length = romanNum.length(); //Calculates length of romanNum string

    int i; //Variable to iterate loop

    int previous = 1000; //Variable to store previous roman numeral value, default 1000

    for (i = 0; i < length; i++) //for loop to run through roman numeral string
    {
        //Switch statement for every possible character of the string
        switch (romanNum[i])
        {
        case 'M':                    //For each case we take the current value of the character
            sum += 1000;             //and add it to sum variable
            if (previous < 1000)     //Then check if previous value was less
                sum -= 2 * previous; //If it was, we subtract 2 * the previous value and
            previous = 1000;         //exit the switch structure
            break;
        case 'D':
            sum += 500;
            if (previous < 500)
                sum -= 2 * previous;
            previous = 500;
            break;
        case 'C':
            sum += 100;
            if (previous < 100)
                sum -= 2 * previous;
            previous = 100;
            break;
        case 'L':
            sum += 50;
            if (previous < 50)
                sum -= 2 * previous;
            previous = 50;
            break;
        case 'X':
            sum += 10;
            if (previous < 10)
                sum -= 2 * previous;
            previous = 10;
            break;
        case 'V':
            sum += 5;
            if (previous < 5)
                sum -= 2 * previous;
            previous = 5;
            break;
        case 'I':
            sum += 1;
            previous = 1;
        }
    }
    num = sum; //The converted number is then assigned to the calculated sum
}

//Constructor
//Sets default values of romanNum string and num variable to I and 1
romanType::romanType()
{
    romanNum = 'I';
    num = 1;
}

//Constructor
//Sets roman numeral string to the input value rString and calls conversion function
romanType::romanType(string rString)
{
    romanNum = rString;
    romanToPositiveInteger();
}