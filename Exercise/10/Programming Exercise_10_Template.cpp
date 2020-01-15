#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    int *p; //declare pointer variable p
    p = new int[10]; //declare dynamic array with pointer variable
    int sum = 0;
    int max;
    int salesPerson;

    ifstream inFile;

    inFile.open("cars.txt");

    for (int j = 0; j < 10; j++) //initialize all arrays components to 0
        p[j] = 0;

    for (int j = 0; j < 10; j++)
    {
        inFile >> p[j]; //Assign each car sales amount to each array component 
        sum = sum + p[j];
    }

    cout << "The total number of cars sold = " << sum << endl;

    max = p[0]; //change this to array as well
    salesPerson = 1;

    for (int j = 1; j < 10; j++) //Modified these to also indicate the dynamic array
        if (max < p[j])
        {
           max = p[j];
           salesPerson = j+1;
        }


    cout << "The salesperson selling the maximum number of cars is salesperson "
         << salesPerson << endl;

    cout << "Salesperson " << salesPerson << " sold "
         << max << " cars last month." << endl;


    cout << endl;


    inFile.close();

    delete []p; //Delete array

    return 0;
}

