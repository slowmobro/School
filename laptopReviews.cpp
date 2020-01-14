#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "laptopReviews.h"

using namespace std;

void arrayDeclare()
{
   laptopRate options[5];
}

void dataGrab()
{
    string dummy; //Dummy string siphons off "\r" windows return character

    //Declare file input variable and open input file
    ifstream inData;
    inData.open("laptopinput.txt");

    for (int x = 0; x < 5; x++)
    {
        getline(inData, options[x].name); //Read in name of laptop
        switch (x)                        //I have issue with working in WSL, windows return character
        {                                 //Ruins my file input so I used a switch strucutre as a dirty
        case 0:                           //work-around
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
        inData >> options[x].vBad;  //Remaining lines read in each consumer rating for the laptops
        inData >> options[x].bad;
        inData >> options[x].ok;
        inData >> options[x].good;
        inData >> options[x].excellent;
        getline(inData, dummy);     //Dummy string gets ride of \r leftover on line 
        
    }
    inData.close(); //Close input file
}

int laptopRate::pointCount(int)
{
    total; 
}
