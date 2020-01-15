#include <iostream>
#include <iomanip>

using namespace std;

//Declare function prototypes 
void initialize (double list[], int size);
void print (double list[], int size);

int main()
{
    //Declare array with 50 components
    double alpha[50];

    //Call both functions to initialize the array and print the results
    initialize(alpha, 50);
    print (alpha, 50);

return 0;
}

//Function to initialize the array
void initialize(double list[], int size)
{
    int count;
    for (count =0; count < 25; count++) //Set the first 25 components to the square of the counter
        list[count] = count * count;
    for (count = 25; count < size; count++) //Set the last 25 components to 3* counter
        list[count] = 3 * count;
}

void print(double list[], int size)
{
    int count;
    for (count = 0; count < size; count++) //Count the entire array
    {
        cout << setw(4) << list[count] << " "; //Output all values separated evenly
        if ((count+1) % 10 == 0) //Determine if there are 10 values in a single line
            cout << endl; //Skip to the next line for the next 10 values
    }
    cout << endl;
}