/*
I have suffered a massive blank brain attack
I have failed to remember the proper variable declaration for file
manipulation. To attempt to demonstrate what knowledge I do have I
have written an appropriate loop to gather the information requested and
display it to the screen. I apologize for this incomplete file.
I recognize that my file does not close properly and that the total hours are incorrect.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //variables for all file information as well as file manipulation
    string name, city;
    int hours, totalHours;
    char gender;

    //Maybe this is how you declare this variable
    ifstream(inData);
    //Attempt to open file
    inData.open("input.txt");

    //cout << setfill(" "); //Unclear why setfill is not allowed with the extraction operator
    cout << "Name" << setw(10) << "Hours" << setw(10) << "City"
         << setw(15) << right << "Gender" << endl << endl;
    //cout << setfill("-") << setw(55);

    //EoF controlled while loop to gather data from file
    while (inData)
    {
        inData >> name >> hours >> city >> gender;
        totalHours += hours; //total the hours line by line
        //Output each line of file to the display
        cout << left << setw(10) << name << setw(10) << hours << setw(10) << city
             << setw(10) << right << gender << endl;
    }
    //Output total amount of hours
    cout << endl;
    cout << "The total number of training hours = " << totalHours << endl;

    //inData.close;// close input file, this command is not correct
    return 0;
}