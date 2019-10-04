#include <iostream>
#include <iomanip> //required to use setprecision
using namespace std;
int main()
{ 
    //Declare variables
    double pounds, kilos;
    //Prompt for user to input weight in kg
    cout << "Enter weight in kilograms: " << endl;
    cin >> kilos;
    //Calculate kilograms into pounds
    pounds = kilos * 2.2;
    cout << fixed; //Set this result to a float in fixed decimal format
    cout << "Your inputed weight in pounds: " << setprecision(2) << pounds; 
    //Finally set decimal places to 2 for final output

return 0;
}