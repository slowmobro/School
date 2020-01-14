#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Declare a global variable for the value of z 
//So that it's value can be accessed anywhere in the program
double z; 
void trackVar(double& x, double y);

int main()
{
    double one, two;

    cout << fixed << showpoint << setprecision(2);
    cout << "Enter two numbers: ";
    cin >> one >> two;
    cout << endl;
    
    //Add z values to cout statements in main function
    trackVar(one, two);
    cout << "z = " << z  << ", one = " << one << ", two = " << two << endl;

    trackVar(two, one);
    cout << "z = " << z << ", one = " << one << ", two = " << two << endl;


    return 0;
}

void trackVar(double& x, double y)
{
    //delete z variable assignment within function block
    z = floor(x) + ceil(y);
    x = x + z;
    y = y - z;

    //Deleted the cout statement within the function
}
