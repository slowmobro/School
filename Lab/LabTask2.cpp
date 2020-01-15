#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double fee, hours; //Declare variables

    cout << "Enter the number of hours the car is parked: " << endl; //Prompt input
    cin >> hours; //Assign input to variable

    cout << fixed << showpoint; //Set output to two decimal places
    cout << setprecision(2);    

    if (hours <= 3) //Fee for 3 or less hours of parking
        fee = 5;
    else if (3 < hours && hours <=9) //Fee for between 3 and 9 hours of parking
        fee = 6 * static_cast<int>(hours + 1);
    else if (9 < hours && hours <= 24) //Fee for between 9 and 24 hours of parking
        fee = 60;

    cout << "Please pay: $" << fee << endl; //Output fee to user
return 0;   
}