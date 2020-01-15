#include <iostream>
#include "sports.h" //Include class file and function file
#include "sports.cpp"
using namespace std;

int main()
{

    sportsType soccer; //Declare variables for sportsType and coach salary (csal)
    int cSal;

    cout <<"Enter the name of the sport: ";
    cin >> soccer.sportName;

    cout <<"Enter the name of the team: ";
    cin >> soccer.teamName;

    cout << "Enter the number of the players: ";
    cin >> soccer.numberOfPlayers;

    cout << "Enter the team Payroll: ";
    cin >> soccer.teamPayroll;

    cout << "Enter the salary of the coach: ";
    cin >> cSal;

    soccer.setSalary(cSal); //run function to set coach salary to cSal variable


    cout<< "-----------------------------------------"<< endl;
    cout << "The Team:"<< endl
        << "Name of the sport: " << soccer.sportName << endl
        << "Name of the team: " << soccer.teamName << endl
        << "Number of the players: " << soccer.numberOfPlayers << endl
        << "Team Payroll: " << soccer.teamPayroll << endl;

    soccer.printSalary(); //run function to print the value of coach salary 

    cout << endl << endl;


    return 0;
}
