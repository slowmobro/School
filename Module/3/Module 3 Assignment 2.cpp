#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{ 
    //Declare ALL variables
    double gallonCost, oilCost, maintCost, parkingCost, 
    annualGas, interestRate, monthInterest, downPayment, carCost,
    estMileage, carMPG, loanTerm, principle, carPayment, totalCost, monthCost;
    string carMake, carModel, carYear;

    //variable for monthly interest calc to limit operation confusion on my part
    double monthInterestOne;

    ofstream outFile;
    //Set variables
    gallonCost = 2.75;
    oilCost = 200.00; //$50 / 3 mo = $200 / year
    maintCost = 400.00;
    parkingCost = 306.00;
    //Open the output file
    outFile.open ("Car Cost.txt");
    //Ask for input
    cout << "Enter car make: " << endl;
    cin >> carMake;
    cout << "Enter car model: " << endl;
    cin >> carModel;
    cout << "Enter car year: " << endl;
    cin >> carYear;
    cout << "Enter car cost (USD): " << endl;
    cin >> carCost;
    cout << "Enter down payment (USD): " << endl;
    cin >> downPayment;
    cout << "Enter yearly interest rate (%): " << endl;
    cin >> interestRate;
    cout << "Enter loan term in months: " << endl;
    cin >> loanTerm;
    cout << "Enter car MPG: " << endl;
    cin >> carMPG;
    cout << "Enter estimated yearly mileage: " << endl;
    cin >> estMileage;

    //Calculate all the needed numbers
    //Total cost of gas per year
    annualGas = (estMileage / carMPG) * gallonCost;
    //Loan payment
    principle = carCost - downPayment;
    monthInterest = (interestRate /100) / 12;

    monthInterestOne = 1.0 + monthInterest;

    carPayment = principle * (monthInterest * pow(monthInterestOne, loanTerm)) / (pow(monthInterestOne,loanTerm)-1);
    //Total annual cost
    totalCost = annualGas + parkingCost + oilCost + maintCost + (carPayment *12);
    //Total monthly cost
    monthCost = totalCost / 12;

    /*Output to file, format to all line up correctly
    Not sure if there was a more intelligent way to get this formatting correct.
    I ended up doing them manually by counting characters. */
    outFile << fixed << showpoint << setprecision(2);
    outFile << setfill('*');
    outFile << "Car: " << carYear << " " << carMake << " " << carModel << endl
        << "Principle: " << setw(29)<< principle << endl
        << "Interest Rate: " << setw(21) << interestRate << "%" << endl
        << "Loan Term: " << setw(26) << loanTerm << " months" << endl
        << endl
        << "Monthly Loan Payment: " << setw(11) << "$" << carPayment << endl
        << "Yearly Fuel Cost: " << setw(15) << "$" << annualGas << endl
        << "Annual Maintenance Cost: " << setw(8) << "$" << maintCost << endl
        << "Annual Oil Change Cost: " << setw(9) << "$" << oilCost << endl
        << "Annual Parking Pass: " << setw(12) << "$" << parkingCost << endl
        << "Total Annual Cost: " << setw(14) << "$" << totalCost << endl
        << "Total Monthly Cost: " << setw(13) << "$" << monthCost << endl;

    outFile.close (); //Close output file
    return 0;

    }