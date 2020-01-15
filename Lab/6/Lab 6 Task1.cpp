#include <iostream>
#include <iomanip>

using namespace std;
int main ()
{
    //Declare variables
    int numItems;
    double price, priceTotal = 0.00;

    //Get input 
    cout << "How many items did you purchase today? " << endl;
    cin >> numItems;
    cout << "Enter the cost of each of the " << numItems << " items you purchased: " << endl;
    
    //Declare control variable and enter the for loop
    int counter; 

    for (counter = 1; counter <= numItems; counter++) //Start counting at 1 to denote the first item
        {
            cout << counter << ". ";
            cin >> price;
            priceTotal = priceTotal + price; //Calculate total price after each input
        }

    cout << "Your total is: " << fixed << setprecision(2) << priceTotal << endl; //Output total cost 
    return 0;

}