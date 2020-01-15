#include <iostream>
using namespace std;

int main()
{
    int i;
    int value = 3;
    i = 0; //Initialize the control variable
    do //Begin the do...while loop
    {
        value = value * (i+1) + i; //Move statement to inside of loop
        i++;
    }
    while (i < 5); //Set exit condition for do...while loop
    
    cout << "value = " << value << endl;


    return 0;
}
