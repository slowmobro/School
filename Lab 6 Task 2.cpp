#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //Output what is being displayed
    cout << "The numbers between 1 and 100 divisible by 7 are:" << endl;
    //Declare variables for loop control variable and the sum of all these numbers
    int counter, sumNum = 0;
    for (counter = 1; counter <= 100; counter++) //Enter a for loop that counts from 1 to 100
        if (counter % 7 == 0)                    //Test if the counter number is divisible by 7
        { 
            cout << counter << endl;             //Output the number if it is
            sumNum = sumNum + counter;           //Add that number to the total if it is
        }
    //Output the sum of all these numbers
    cout << "The sum of all numbers between 1 and 100 divisible by 7 is: " << sumNum << endl; 

return 0;
}