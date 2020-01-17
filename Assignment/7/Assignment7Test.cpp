#include <iostream>
#include <iomanip>

using namespace std;

void input (char insects[], double insectSpeed[], int numInsect);
void sort(char insects[], double insectSpeed[], int numInsect);

int main()
{
    //Declare variable to store the number of insects to be entered
    int numInsect;

    //Declare arrays for insect names and speeds
    char insects[numInsect][20];
    double insectSpeed[numInsect];

    input (insects, insectSpeed, numInsect);
    sort (insects, insectSpeed, numInsect);

    cout << left << setw(10) << "Insect Name" 
         << setw(10) << right << "Speed" << endl;
    
    for (int j = 0; j < numInsect; j++)
        cout << insects[j] << endl 
             << insectSpeed[j];
return 0;
}
void input (char insects[], double insectSpeed[], int numInsect)
{
    //Prompt for input
    cout << "Enter the number of insects to be recorded: " << endl;
    cin >> numInsect;
    cout << "Enter insect's names and their measured speeds: " << endl;

    for (int i = 0; i < numInsect; i++)
       {
        cin.get(insects[i],20);
        cin >> insectSpeed[i];
       }
}

void sort(char insects[], double insectSpeed[], int numInsect)
{
    int index;
    int location;
    int temp_speed;
    string tempInsect;

    for (index = 0; index < numInsect - 1; index++)
    {
        for (location = index; location < numInsect - 1; location++)

        //Swap the fastest speed in the array with the first element
            if (insectSpeed[location] < insectSpeed[location+1])
            {
                tempInsect = insects[location];
                insects[location] = insects[location+1];
                insects[location+1] = tempInsect;
                temp_speed = insectSpeed[location];
                insectSpeed[location] = insectSpeed [location+1];
                insectSpeed[location+1] = temp_speed;
            }
    }
}