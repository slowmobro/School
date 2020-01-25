#include <iostream>

using namespace std;

int main()
{
    int numBugs, totalBugs = 0, day = 1; //Declare variables for insects colllected per day, the total collected and a counter

    while (day <= 7) // Set counter to count up through 7
    {
        cout << "Enter the number of insects collected on Day: " << day << endl; //Prompt for data
        cin >> numBugs; //Assign data to bug variable

        totalBugs = numBugs + totalBugs; //Calculate the total amount of collected bugs thus far
        day++; //Increment day variable to move to next day
    }
    cout << "Total insects collected: " << totalBugs << endl; //Output total of collected bugs for 7 days 

return 0;
}