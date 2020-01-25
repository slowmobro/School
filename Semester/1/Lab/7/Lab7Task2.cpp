#include <iostream>

using namespace std;

//Declare function prototypes
void getTime(int &hours24, int &minutes);
void giveTime(int hours, int minutes, char AMPM);
void timeConvert(int &hours, char &AMPM);

int main()
{
    //Declare variables
    int hours, minutes;
    char AMPM, ans;

    //Enter do...while loop
    do
    {
        getTime(hours, minutes);        //Call time input function
        timeConvert(hours, AMPM);       //Call time conversion function
        giveTime(hours, minutes, AMPM); //Call time output function

        //Prompt to continue
        cout << "Enter Y or y to continue,"
             << "any other input will quit program" << endl;
        //Read input
        cin >> ans;
    } while ('Y' == ans || 'y' == ans); //Determine if loop should continue

    return 0;
}

void getTime(int &hours24, int &minutes)
{
    //Declare variable for the colon that will be in the input
    char colon;
    //Prompt for time
    cout << "Enter 24 hour time in format HH:MM" << endl;
    //Assign values to variables
    cin >> hours24 >> colon >> minutes;
}
void timeConvert(int &hours, char &AMPM)
{
    if (hours > 12) //Afternoon conversion
    {
        hours -= 12;
        AMPM = 'P';
    }
    else if (hours == 12) //Noon conversion
        AMPM = 'P';
    else if (hours == 0) //Midnight conversion
    {
        hours += 12;
        AMPM = 'A';
    }
    else //Morning conversion
        AMPM = 'A';
}

//I had a bug where if the minutes input contained a zero ex. 12:04
//then the output would be 12:4 since the 0 was not a significant digit 
//to the double value
//This statement adds the 0 back in if the minute value is below 10, 
//otherwise it outputs as normal

void giveTime(int hours, int minutes, char AMPM)
{
    cout << "Time in 12 hour format: " << endl
         << hours << ":";
    if (minutes < 10)
        cout << "0" << minutes << " "
             << AMPM << "M" << endl;
    else
        cout << minutes << " "
             << AMPM << "M" << endl;
}