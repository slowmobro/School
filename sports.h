#ifndef SPORTS_H
#define SPORTS_H
#include <string>

using namespace std;

class sportsType
{
    public:
        string sportName;
        string teamName;
        int numberOfPlayers;
        double teamPayroll;
        void setSalary(int);    //Function to set coach salary
        void printSalary();     //Function to print coach salary
    private:
        int coachSalary;
};

#endif