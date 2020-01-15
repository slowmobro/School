#include <iostream>
#include <iomanip>
using namespace std;

//Define struct before functions
struct CDAccount
{
    double balance;
    double rate;
    int term;
};

//Define void function prototypes
void cdInput(CDAccount& CD);

int main()
{
    //Declare the struct variable
    CDAccount CD;

    //Call input function
    cdInput(CD);

    //Declare variables for the balance calculations
    double totalInterest, endBalance;
    
    //Calculate the interest generated over the term
    //and the total balance at the end of that term
    totalInterest = CD.balance * (CD.rate / 100.0) * (CD.term / 12.0);
    endBalance = CD.balance + totalInterest;

    //Output the term again along with the new mature balance
    cout << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "When your CD matures in " << CD.term << " months," << endl
         << "it will have a balance of $" << endBalance << endl;

    return 0;
}

//Function for input
void cdInput(CDAccount &CD)
{
    cout << "Enter account balance: " << endl; //Each line requests input for each member of the struct
    cin >> CD.balance;
    cout << "Enter account interest rate: " << endl;
    cin >> CD.rate;
    cout << "Enter the number of months till maturity (Between 1 and 12 months): " << endl;
    cin >> CD.term;
    if (CD.term < 1 || CD.term > 12)    //Not required but program checks for valid input
    {
        cout << "Error. Must between 1 and 12 months." << endl
             << "Enter the number of months till maturity" << endl;
        cin >> CD.term;
    }
}
