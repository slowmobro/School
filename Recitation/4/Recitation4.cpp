#include <iostream>

using namespace std;

int main()
{
    int total = 0, number; //initialized the loop control variable

    cout << "Enter the numbers to be added and end with -1: ";
    cin >> number;

    while (number != -1)
    {
        total = total + number;
        cin >> number; //Added input stream variable to allow program to advance to next data input
    }
    cout << endl;
    cout << "Total = " << total << endl;

    return 0;
}
