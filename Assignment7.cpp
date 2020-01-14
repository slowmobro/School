#include <iostream>
#include <iomanip>

using namespace std;

void input (string insects[], double insectSpeed[], int numInsect);
void sort(string insects[], double insectSpeed[], int numInsect);

int main()
{
    //Declare variable to store the number of insects to be entered
    int numInsect;

    //Request and gather input for size of array required 
    cout << "Enter the number of insects to be recorded: " << endl;
    cin >> numInsect;

    //Declare arrays for insect names and speeds
    string insects[numInsect];
    double insectSpeed[numInsect];

    //Call functions
    input (insects, insectSpeed, numInsect);
    sort (insects, insectSpeed, numInsect);

    //Output relevant data with columns and a for loop to iterate through array components
    cout << endl << left << setw(10) << "Insect Name" 
         << "\t" << "Speed\n" << endl;
    
    for (int j = 0; j < numInsect; j++)
        cout << left << setw(10) << insects[j] << "\t"
             << fixed << showpoint << setprecision(2)
             << insectSpeed[j] << endl;

    cout << endl << "The fastest insect is the " << insects[0] << endl;

return 0;
}

void input (string insects[], double insectSpeed[], int numInsect)
{
    //Prompt for input
    cout << "Enter insect's names and their measured speeds: " << endl;
    //For loop to gather data from user
    for (int i = 0; i < numInsect; i++)
       {
        cin >> insects[i];
        cin >> insectSpeed[i];
       }
}

void sort(string insects[], double insectSpeed[], int numInsect)
{
    int index;
    int location;
    double temp_speed;
    string tempInsect;

    for (index = 0; index < numInsect - 1; index++)
    {
        for (location = 0; location < (numInsect - index - 1); location++)
        {
        //Swap the fastest speed in the array with the first element
        //This checks to see if the next array component is larger 
        //If so, it swaps the positions of the two components 
        //This loop runs until no value is larger than the one before it 
            if (insectSpeed[location] < insectSpeed[location+1])
            {
                tempInsect = insects[location]; //Set tempvar to current location
                insects[location] = insects[location+1]; //Swap current location with next
                insects[location+1] = tempInsect; //Set tempvar to next location to repeat process
                temp_speed = insectSpeed[location]; //Same for speeds
                insectSpeed[location] = insectSpeed[location+1];
                insectSpeed[location+1] = temp_speed;
            }
        } 
    }
}