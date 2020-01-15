#include <iostream>
#include <fstream> //required to open and manipulate a file

using namespace std;

int main ()
{
    //Declare variables and set the pay increase as a constant
    double currentSal, newSal, monthSal, retroPay;
    const double payIncrease = 0.076;
    //Also declare an output file stream variable
    ofstream outData;
    //Open the file
    outData.open("Output.txt");
    //Request user to input current salary
    cout << "Please input current salary: " << endl;
    cin >> currentSal;
    //Calculate new salary
    newSal = currentSal * (1 + payIncrease);
    //Calculate new monthly salary
    monthSal = newSal / 12;
    //Calculate retroactive pay for past 6 months by halving annual salary
    retroPay = (newSal - currentSal)/2;
    //Display results to user
    cout << "Your new salary is: $" << newSal << endl
         << "Your new monthly salary is: $" << monthSal << endl
         << "Your retroactive pay due is: $" << retroPay << endl;

    //Finally we print these results to Output.txt
    outData << "Your new salary is: $" << newSal << endl
            << "Your new monthly salary is: $" << monthSal << endl
            << "Your retroactive pay due is: $" << retroPay << endl;
    //Then close file
    outData.close();
    
return 0;
}