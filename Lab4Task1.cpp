#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double sideOne, sideTwo, sideThree; //Declare variables for each side of triangle

    cout << "Enter the lengths of the sides of a triangle: " << endl; //Prompt for user input of sides
    cin >> sideOne >> sideTwo >> sideThree; //Assign sides to variables

    if ((pow(sideOne, 2) == (pow(sideTwo, 2) + pow(sideThree, 2))) || //Check if any of the squared sides are the sum of the others squared
        (pow(sideTwo, 2) == (pow(sideOne, 2) + pow(sideThree, 2))) ||
        (pow(sideThree, 2) == (pow(sideTwo, 2) + pow(sideOne, 2))))
    {   
        cout << "You have entered a right triangle" << endl; //Output if triangle is right
    }
    else
        cout << "This is not a right triangle" << endl; //Output if triangle is not right

    return 0;
}