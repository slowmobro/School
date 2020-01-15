#include <iostream>
#include <fstream> //Added fstream header
using namespace std;

int main()
{
    int cars[10];
    int sum = 0;
    int max;
    int salesPerson;

    ifstream inFile; //declared file steam variable
    inFile.open("cars.txt");

    for (int j = 0; j < 10; j++)
    {
        inFile >> cars[j];
        sum = sum + cars[j]; //added statement to sum the total number of cars as they are being read
    }

    cout << "The total number of cars sold = " << sum << endl;

    max = cars[0];
    salesPerson = 1; 

    for (int j = 1; j < 10; j++) 
        if (max < cars[j]) //changed max greater than to less than because 0 will always be less
        {
            max = cars[j];
            salesPerson = j+1;
            //Added +1 to salesPerson variable because that is how a company would count
            //1, 2, 3, etc. It is odd to say 0th salesperson 
        }

    cout << "The salesperson selling the maximum number of cars is salesperson "
         << salesPerson << endl;

    cout << "Salesperson " << salesPerson << " sold "
         << max << " cars last month." << endl;

    cout << endl;

    inFile.close();

    return 0;
}
