#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    //Declare the variables
    double x1, y1, x2, y2,
        side1, side2, distance;
    //Output instructions to user for coordinate input
    cout << "Please enter the values for x1, y1, x2, y2" << endl;
    //Take input from user and assign to variables
    cin >> x1 >> y1 >> x2 >> y2;

    //Compute sides of the right triangle

    side1 = x2 - x1;
    side2 = y2 - y1;
    //Calculate distance
    distance = sqrt(side1*side1 + side2*side2); 
    //Display results
    cout << "Distance between the two points is " <<distance << endl; 

    return 0; 
}