#include<iostream>

#include<iomanip>

using namespace std;

int main()

{

int numberOfInsects;

//prompt and read the number of insects

cout << "How many insects do you have? ";

cin >> numberOfInsects;

//create arrays to store insects names and speeds

string insectNames[numberOfInsects];

double speeds[numberOfInsects];

//read the insect's names and their speeds

cout << "Enter insect's names and their measured speeds : " << endl;

for(int i = 0; i < numberOfInsects; i++)

{

cin >> insectNames[i];

cin >> speeds[i];

}

//sort the speed in descending order (using bubble sort technique)
string tempName;
double tempSpeed;

for(int i = 0; i < numberOfInsects - 1; i++)
{
    for(int j = 0; j < (numberOfInsects - i - 1); j++)
    {
//sort the names and speed based on speeds
        if(speeds[j] < speeds[j+1])
        {
        tempName = insectNames[j];
        insectNames[j] = insectNames[j+1];
        insectNames[j+1] = tempName;
        tempSpeed = speeds[j];
        speeds[j] = speeds[j+1];
        speeds[j+1] = tempSpeed;
        }
    }
}

//display the insects names and speed

cout << endl << endl << left << setw(20) << "Insect Name" << "\t" << "speed" << endl;

for(int i = 0; i < numberOfInsects; i++)

{

cout << left << setw(20) << insectNames[i] << "\t" << speeds[i] << endl;

}

//display the fastest insect

cout << "The fastest insect is " << insectNames[0] << endl;

return 0;

}
