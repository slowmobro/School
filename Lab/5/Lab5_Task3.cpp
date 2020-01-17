#include <iostream>

using namespace std;

int main()
{
    int num1, num2, large, small; //Declare variables and intitialize the LCV
    bool flag = true;

    while (flag) //Enter loop
    {
        //Prompt for input
        cout << "Enter the numbers you would like to divide separated by returns: " << endl;
        cin >> num1 >> num2; //Assign inputs

        //Find the larger of the two numbers and assign accordingly 
        if (num1 > num2){
            large = num1;
            small = num2;
        }
        else{
            large = num2;
            small = num1;
        }

        //Determine large%small to see if the remainder is 0 and thus divisible, otherwise output error message
    
        if (large % small == 0){
            cout << small << " goes into " << large <<", " << large/small << " times " << endl;
        }
        else {
            cout << "These numbers are not divisible." << endl << endl;
        }

        //Prompt user to continue calculating or not 
        cout << "To continue type 1. \nTo exit type any other character." << endl;
        cin >> flag;
    }
    return 0;

}