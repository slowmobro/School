#include <iostream>
using namespace std;

//Define struct before functions
struct sportsType
{
    string sportName;
    string teamName;
    int numberOfPlayers;
    double teamPayroll;
    double coachSalary;
};

//Define void function prototypes
void sportInput(sportsType& soccer);
void sportOutput(sportsType& soccer);

int main()
{
    //Declare a struct "soccer" of type sportsType
    sportsType soccer;

    //Call input and output functions
    sportInput(soccer);
    sportOutput(soccer);

    return 0;
}

//Function for input
void sportInput(sportsType &soccer)
{
    cout << "Enter the name of the sport: " << endl; //Each line requests input for each member of the struct
    cin >> soccer.sportName;
    cout << "Enter the name of the team: " << endl;
    cin >> soccer.teamName;
    cout << "Enter the number of players: " << endl;
    cin >> soccer.numberOfPlayers;
    cout << "Enter the team payroll: " << endl;
    cin >> soccer.teamPayroll;
    cout << "Enter the salary coach's salary: " << endl;
    cin >> soccer.coachSalary;
}

//Function for output
void sportOutput(sportsType &soccer)
{
    cout << "-------------------------------------------------" << endl; //Formatting line
    cout << "The Team:\n";                                               //Each member outputs on separate lines
    cout << "Name of the sport: " << soccer.sportName << endl
         << "Name of the team: " << soccer.teamName << endl
         << "Number of players: " << soccer.numberOfPlayers << endl
         << "Team Payroll: $" << soccer.teamPayroll << endl
         << "Coach's Salary: $" << soccer.coachSalary << endl;
}