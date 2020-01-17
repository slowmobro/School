#include <iostream>
using namespace std;

int main()
{
    //Declare variables
    double orderAmount, price, totalPrice, discPrice, discount, discNum = 0;

    //Request input for number of packages
    cout << "How many packages were purchased?" << endl;
    cin >> orderAmount;

    //Calculate base price
    totalPrice = orderAmount * 99;

    //Use if else statements to determine discount amount and subsequent total
    //Reassign variables in the statements to simplify output later
    if (10 <= orderAmount && orderAmount <= 19)
    {
        discNum = 20;
        discount = totalPrice * 0.20;
        discPrice = totalPrice - discount;
    }
    else if (20 <= orderAmount && orderAmount <= 49)
    {
        discNum = 30;
        discount = totalPrice * 0.30;
        discPrice = totalPrice - discount;
    }
    else if (50 <= orderAmount && orderAmount <= 99)
    {
        discNum = 40;
        discount = totalPrice * 0.40;
        discPrice = totalPrice - discount;
    }
    else if (orderAmount >= 100)
    {
        discNum = 50;
        discount = totalPrice * 0.50;
        discPrice = totalPrice - discount;
    }
    else
    {
        discNum = 0;
        discount = 0;
        discPrice = totalPrice;
    }

    //Final if else statement to determine which output to use, with or without discount
    if (discNum > 0)
        cout << "This purchase qualifies for a " << discNum << "% discount." << endl
             << "The total amount of the discount is $" << discount << endl
             << "The total amount of the purchase is $" << discPrice << endl;
    else
        cout << "This purchase does not qualify for a discount." << endl
             << "The total amount of the purchase is $" << discPrice << endl;

    return 0;
}