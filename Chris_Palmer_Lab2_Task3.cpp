#include <iostream>

using namespace std;
int main ()
{
    //Declare all variables
    double totalCost, milkPrice, cartonVolume, milkProfit, totalMilk, cartonProfit, totalProfit;
    int cartonTotal;
    /*I've set the various numbers in this problem to their own variables so that they may be changed
    to adjust for price fluctuations and make the program more versatile*/
    milkPrice = 0.38;
    milkProfit = 0.27;
    cartonVolume = 3.78;

    //Request amount of milk
    cout << "Please enter amount of milk in liters" << endl;
    cin >> totalMilk;

    cartonTotal = static_cast<int>(totalMilk / cartonVolume); //calculate amount of cartons needed
    totalCost = totalMilk * milkPrice; //Calculate how much that much milk costs to produce
    totalProfit = milkProfit * cartonTotal; //Calculate total profit from those cartons

    cout << "The number of cartons is " << cartonTotal << endl
         << "The cost of producing this milk: $" << totalCost << endl
        << "The profit from this production: $" << totalProfit << endl; //Output all results

    return 0;
        
}