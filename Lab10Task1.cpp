#include <iostream>
#include "juiceMachine.h"
#include "juiceMachine.cpp"
using namespace std;

void showSelection();
void sellProduct(dispenserType& product, cashRegister& pCounter);

int main()
{
    cashRegister counter;
    dispenserType orange(100, 50);
    dispenserType apple(100, 65);
    dispenserType mango(75, 80);
    dispenserType strawberryBanana(100, 85);

    int choice;

    showSelection();
    cin >> choice;

    while (choice != 9)
    {
        switch (choice)
        {
        case 1:
            sellProduct(orange, counter);
            break;
        case 2:
            sellProduct(apple, counter);
            break;
        case 3:
            sellProduct(mango, counter);
            break;
        case 4:
            sellProduct(strawberryBanana, counter);
            break;
        default:
            cout << "Invalid selection." << endl;
        }

        showSelection();
        cin >> choice;
    }
}

void showSelection()
{
    cout << "*** Welcome to Shelly's Juice Shop ***" << endl
         << "To select an item, enter " << endl
         << "1 for orange juice (50 cents)" << endl
         << "2 for apple juice (65 cents)" << endl
         << "3 for mango juice (80 cents)" << endl
         << "4 for strawberry-banana juice (85 cents)" << endl
         << "9 to exit" << endl;
}

void sellProduct(dispenserType& product, cashRegister& pCounter)
{
    int amount;
    int amount2;

    if (product.getNoOfItems() > 0)
    {
        cout << "Please deposit " << product.getCost() << " cents" << endl;
        cin >> amount;

        if (amount < product.getCost())
        {
            cout << "Please deposit another " << product.getCost() - amount << " cents" << endl;
            cin >> amount2;
            amount = amount + amount2;
        }

        if (amount >= product.getCost())
        {
            pCounter.acceptAmount(amount);
            product.makeSale();
            cout << "Collect your item at the bottom and enjoy" << endl;
        }
        else
            cout << "The amount is not enough. Collect what you deposited." << endl;

        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl
             << endl;
    }
    else
        cout << "Sorry, this item is sold out." << endl;
}