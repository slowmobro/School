#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << setfill('*') << setw(37) << " " << endl;
    cout << setfill(' ');
    cout << left << "*"
         << " Programming Assignment 1" << setw(10) << right << "*" << endl;
    cout << left << "*"
         << " Computer Programming I" << setw(12) << right << "*" << endl;
    cout << left << "*"
         << " Author: Chris Palmer" << setw(14) << right << "*" << endl;
    cout << left << "*"
         << " Due Date: Thursday, Jan. 24" << setw(7) << right << "*" << endl;
    cout << setfill('*') << setw(37) << " " << endl;
    return 0;
}