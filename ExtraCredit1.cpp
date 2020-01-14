#include <iostream>

using namespace std;

int main()
{
    //Declare variables
    int total = 0, insectDay, day = 1;

    //For loop to run through all 7 days
    for (day; day <= 7; day++)
    {
        //Request input per day
        cout << "How many insects were collected on Day " << day << "?" << endl;
        //Assign input
        cin >> insectDay;
        //If statement checks for valid input and repeats input if needed
        if (insectDay < 0)
        {
            cout << "Insects must be zero or more." << endl;
            cout << "How many insects were collected on Day " << day << "?" << endl;
            cin >> insectDay;
        }
        //Update total count of all insects
        total += insectDay;
    }

    //Output total insect count 
    cout << endl << "Total insects collected: " << total << endl;

return 0;
}