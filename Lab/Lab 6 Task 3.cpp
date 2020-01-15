#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    int temp, minTemp = 0, totalTemp = 0, day = 1, i; //Declare variables 
    ifstream inData; //Declare input stream variable

    inData.open ("input.txt"); //Open input file

    inData >> temp; //Assign the first line of data to day 1 and new min temperature
    minTemp = temp;
    totalTemp = temp;

    cout << "Temperature Record:" << endl; //Display colums to organize following data output
    cout << left << setw(10) << "Month"
         << left << setw(3) << "Day"
         << right << setw(13) << "Temperature" << endl;
    
    cout << left << setw(10) << "January" //Display the first line of data we used to set variables
         << left << setw(3) << day
         << right << setw(13) << temp << endl;

for (i = 2; i <= 31; i++) //Enter a for loop counting from day 2 through 31
{
    inData >> temp; 
    totalTemp = totalTemp + temp; //Calc new total temp by adding each new temperature to itself
  
    cout << left << setw(10) << "January" //Display each new day and temperature
         << left << setw(3) << i
         << right << setw(13) << temp << endl;

    if (temp < minTemp) //If statement to determine the minimum
    {
        minTemp = temp;
        day = i;
    }
}
    cout << fixed << showpoint << setprecision(2); //Output the average temp, min temp, and day the min occured 
    cout << "The average temperature in January was " << totalTemp / 31.0 << endl;
    cout << "The minimum temperature was: " << minTemp << endl
         << "This occured on: " << "January " << day << endl;
    
    inData.close(); //Close input file
    
return 0;
}