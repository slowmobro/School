#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
    double Celsius, Fahrenheit; //declare variables

cout << "Enter temperature in Celsius: " << endl; //request temp input
cin >> Celsius;

Fahrenheit = (Celsius * 1.8)+32; //convert F to C

cout << "Celsius Entered: " << setprecision(2) <<fixed << Celsius << endl
    << "Temperature in Fahrenheit: " << Fahrenheit << endl; //display results

return 0; 
}