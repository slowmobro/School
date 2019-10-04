#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double firstNum, secondNum; //declare variables

    cout << "Enter two positive numbers: "; //prompt for input
    cin >> firstNum >> secondNum; //assign input to variables
    cout << endl;

    if (firstNum <= 0 || secondNum <= 0) //Check if either of inputs are positive
        cout << "Both numbers must be positive." << endl;
    else if (firstNum == secondNum) //Check if both positive numbers are equal
        cout << firstNum + secondNum << endl; //If they are, output sum of numbers
    else if (firstNum <= 2) //Check if first number is less than or equal to 2
        cout << pow(secondNum, firstNum) << endl; //If it is, output second number raised to power of first
    else 
        cout << firstNum * secondNum << endl; //If first number is greater than 2, output product of both numbers 

    return 0;
}
