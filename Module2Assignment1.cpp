#include <iostream> 

using namespace std;

int main()
{
    //Declare variables
    int inputCost, dollar,
    halfdoll, quarter, dime, nickel, penny, change; 

    //Ask for cost input from user
    cout << "Please enter the cost of your item between 25 cents and 1 dollar in 5 " << endl    
         << "cent increments:" << endl;
    cin  >> inputCost;

    //Calculate change owed to user
    change = 100 - inputCost;

    //Break down total change into denominations
    dollar = change / 100;
    change = change % 100; //Take remainder from division and assign that to a new value of change
    halfdoll = change / 50; 
    change = change % 50; //Repeat this through each denomination until no there is no remainder
    quarter = change / 25;
    change = change % 25;
    dime = change / 10;
    change = change % 10;
    nickel = change / 5;
    change = change % 5;
    penny = change % 1;

    //Display change owed
    cout << "Your change is: " << 100 - inputCost << " cents" << endl
         << "Your change will be dispensed as:" << endl
         << "" << endl
         << "Dollars: " << dollar << endl
         << "Half Dollars: " << halfdoll << endl
         << "Quarters: " << quarter << endl
         << "Dimes: " << dime << endl
         << "Nickels: " << nickel << endl
         << "Pennies: " << penny << endl;

    return 0;
}
