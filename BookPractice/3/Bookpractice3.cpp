#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double massOne, massTwo, dist, force;
    double k = 6.67e-11; //textbook deff of gravitational constant is wonky so I changed it

    cout << "Enter the mass of both objects separated by a space" << endl;
    cin >> massOne >> massTwo;
    cout << "Enter the distance between the two masses" << endl;
    cin >> dist;
    force = ((massOne * massTwo)*k / dist * dist);

    cout << "The force, F = " << force << endl;
}