#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Declare const variable for the number of fluids
const int NO_OF_FLUIDS = 55;

//Define a struct to contain fluid data
struct fluidType
{
    string fluidName;
    int temperature;
    double specificGravity;
};

//Define function prototypes
void getData(ifstream &inFile, fluidType fList[], int listSize);
double highestGravity(const fluidType fList[], int listSize);
void print(const fluidType fList[], int listSize);

int main()
{
    //Declare I/O stream variables
    ifstream inData;

    //Declare an array of type struct 
    fluidType fluidList[NO_OF_FLUIDS];

    //Open input file
    inData.open("input.txt");

    //Validate the input file
    if (!inData)
    {
        cout << "The input file does not exist. Program is terminated." << endl;
        return 1;
    }

    //Call functions
    getData(inData, fluidList, NO_OF_FLUIDS);
    print(fluidList, NO_OF_FLUIDS);

    //Close input file
    inData.close();

    return 0;
}

//Function to gather input from text file
void getData(ifstream &inFile, fluidType fList[], int listSize)
{
    //Loops run as many times as there are fluids
    for (int i = 0; i < listSize; i++)
        inFile >> fList[i].fluidName >> fList[i].temperature >> fList[i].specificGravity;
}

//Function to determine the highest specific gravity
double highestGravity(const fluidType fList[], int listSize)
{
    double hGrav = fList[0].specificGravity; //Variable to hold highest specific gravity

    //For loop iterates through each fluid's specific gravity
    //The current highest gravity is assigned to hGrav
    //If the next component of the array is higher than hGrav, the variable is reassigned
    for (int i = 1; i < listSize; i++)
        if (hGrav < fList[i].specificGravity)
            hGrav = fList[i].specificGravity;

    return hGrav; //Return the value of the highest specific gravity
}

void print(const fluidType fList[], int listSize)
{
    //Use highest gravity function to find highest specific gravity
    double maxGrav = highestGravity(fList, listSize);

    //Print highest specific gravity
    cout << "Highest Specific Gravity: " << maxGrav << endl;
    cout << "Fluid having the highest Specific Gravity:" << endl;

    //Print the fluid with the highest specific gravity
    for (int i = 0; i < listSize; i++)
        if (fList[i].specificGravity == maxGrav)
            cout << fList[i].fluidName << endl;
}