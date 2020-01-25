#include "sports.h"
#include <iostream>

using namespace std;

void sportsType::setSalary(int cSal) //Function takes user input variable cSal as argument
                                     //and assigns it to coachSalary in class
{
    coachSalary = cSal;
}

void sportsType::printSalary()      //Function prints the newly assigned coachSalary variable
{
    cout << "Salary of the coach: " << coachSalary << endl;
}