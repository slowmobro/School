#include <iostream>

using namespace std;

int main()
{
    int num1, num2; //declare variables for numbers to calculate and operator
    char operatorSymbol;


    cout << "Enter two integers: " << endl; //Request input
    cin >> num1 >> num2; //Assign input to variables
    cout << "Enter operator: + (addition), - (subtraction)," << endl //Get input for operator selection
         << " * (multiplication), / (division): " << endl;
    cin >> operatorSymbol; //Assign inputted operator to variable

    switch (operatorSymbol)
    {
        case '+':
            cout << num1 << "+" << num2 << "=" << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << "-" << num2 << "=" << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << "*" << num2 << "=" << num1 * num2 << endl;
            break;
        case '/':
            if (num2 == 0)
                cout << num1 << "/" << num2 << "=" << "ERROR:Cannot divide by zero" << endl;
            else            
                cout << num1 << "/" << num2 << "=" << num1 / num2 << endl;
            break;
        default:
            cout << "Invalid Entry. Please try again." << endl;
    return 0;
    }




}
