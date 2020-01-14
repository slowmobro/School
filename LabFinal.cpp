//Attempted to write functions to process data and utilize private class variable
//I was unable to call functions due to some error I was making
//Compiler gave error message "a nonstatic member reference must be relative to a specific object"
//But I did attempt to utilize the class fully, thank you for your time 
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Declare class to hold laptop information
class laptopRate
{
public:
    string name;                        //string for name of laptop model
    int vBad, bad, ok, good, excellent; //int variables for number of each rating receieved
private:
    int total; //variable to store total of all review points
};

//Declare array of classes
laptopRate options[5];

int main()
{
    //Student information
    //Apologies, I do not have my UIN memorized
    cout << "Name: Christopher Layton Palmer" << endl
         << "UIN:  XXXXX" << endl
         << "CRN:  21001" << endl
         << "Date: 12/10/2019" << endl;
    cout << endl
         << endl;

    //Declare variables
    string dummy; //Dummy string siphons off "\r" windows return character

    //Declare file input variable and open input file
    ifstream inData;
    inData.open("laptopinput.txt");

    for (int x = 0; x < 5; x++)
    {
        getline(inData, options[x].name); //Read in name of laptop
        switch (x)                        //I have issue with working in WSL, windows return character
        {                                 //ruins my file input so I used a switch to delete it
        case 0:                           //as a work-around
            options[x].name.erase(17, 2);
            break;
        case 1:
            options[x].name.erase(15, 2);
            break;
        case 2:
            options[x].name.erase(22, 2);
            break;
        case 3:
            options[x].name.erase(14, 2);
            break;
        case 4:
            options[x].name.erase(16, 2);
            break;
        default:
            break;
        }
        inData >> options[x].vBad; //Remaining lines read in each consumer rating for the laptops
        inData >> options[x].bad;
        inData >> options[x].ok;
        inData >> options[x].good;
        inData >> options[x].excellent;
        getline(inData, dummy); //Dummy string gets ride of \r leftover on line
    }

    //Output results, first title followed by column headers
    cout << "Laptop Consumer's Reviews:" << endl
         << "==========================" << endl
         << endl;

    cout << left << setw(30) << "Laptop Name" << setw(10) << "Very Bad" << setw(8) << "Bad" << setw(8)
         << "OK" << setw(8) << "Good" << setw(13) << "Excellent"
         << "Total Points" << endl;
    cout << "======================================================================================" << endl;

    //For loop iterates through each laptop and prints the name and the number of each kind of review
    for (int j = 0; j < 5; j++)
    {
        int total = 0;
        total += options[j].vBad + (2 * options[j].bad) + (3 * options[j].ok) 
                + (4 * options[j].good) + (5 * options[j].excellent);

        cout << left << setw(30) << options[j].name << setw(10) << options[j].vBad << setw(8)
             << options[j].bad << setw(8) << options[j].ok << setw(10) << options[j].good
             << setw(13) << options[j].excellent << total << endl;
    }

    inData.close(); //Close input file
    return 0;
}
