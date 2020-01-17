#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main ()
{
    //Declare input and output stream variables
    ifstream inFile;
    ofstream outFile;
    //Declare variables
    string firstName, lastName, department;
    double grossSalary, bonus, taxRate,
    distanceTraveled, travelTime, costPerCup;
    int numSoldCups;


    double paycheck, averageSpeed, salesAmount;
    //Open input and output files
    inFile.open ("inData.txt");
    outFile.open("outData.txt");

    outFile << fixed << showpoint << setprecision(2);

    //Read input data

    inFile >> firstName >> lastName >> department;
    inFile >> grossSalary >> bonus >> taxRate;
    inFile >> distanceTraveled >> travelTime;
    inFile >> numSoldCups >> costPerCup;

    //Output known data to output file
    outFile << "Name: " << firstName << " " << lastName << ", "
            << "Department: " << department << endl;
    //Pay
    outFile << "Monthly Gross Salary: $" << grossSalary
            << ", Monthly Bonus: " << bonus << "%, Taxes: "
            << taxRate << "%" << endl
            << "Paycheck: $";
    
    //Calc paycheck amount
    paycheck = grossSalary * (1+bonus / 100) * (1-taxRate / 100);
    outFile << paycheck
            << endl << endl;
    //Speed
    outFile << "Distance traveled: " << distanceTraveled
            << " miles, Travel Time:" << travelTime << " hours" << endl;
    //Calc average speed
    averageSpeed = distanceTraveled / travelTime;

    outFile <<"Aveerage Speed: " <<averageSpeed
            <<" miles per hour" << endl << endl;
//Coffee
    outFile << "Number of Coffee Cups Sold: " << numSoldCups
            << ", Cost: $" << costPerCup << " per cup" << endl;
    //Calc cost of coffee total
    salesAmount = numSoldCups * costPerCup;

    outFile << "Sales Amount = $" << salesAmount
            << endl;
    
//Close both files
inFile.close();
outFile.close();

return 0;
}