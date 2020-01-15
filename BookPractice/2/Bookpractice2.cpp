#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    double preTaxIncome, postTaxIncome, postTaxIncomeMod, extraSpend, schoolSpend,
        selfBond, parentBond;

    preTaxIncome = (15.50 * 40) * 5;
    postTaxIncome = preTaxIncome - (preTaxIncome * 0.14);
    extraSpend = postTaxIncome * 0.10;
    postTaxIncomeMod = postTaxIncome;
    postTaxIncomeMod = postTaxIncomeMod - extraSpend;
    schoolSpend = postTaxIncomeMod * 0.01;
    postTaxIncomeMod = postTaxIncomeMod - schoolSpend;
    selfBond = postTaxIncomeMod * 0.25;
    postTaxIncomeMod = postTaxIncomeMod - selfBond;
    parentBond = static_cast<int>(selfBond) * 0.50;

    cout << fixed << setprecision(2)
         << "Income before taxes: $" << preTaxIncome << endl
         << "Income after taxes: $" << postTaxIncome << endl
         << "Money spent on clothes and misc: $" << extraSpend << endl
         << "Money spent on school supplies: $" << schoolSpend << endl
         << "Money spent on savings bonds: $" << selfBond << endl
         << "Money parents spent on savings bonds: $" << parentBond << endl
         << "Money leftover: " << postTaxIncomeMod << endl;

    return 0;
}