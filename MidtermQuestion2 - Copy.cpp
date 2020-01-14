#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //variables for all file information as well as file manipulation
    string name, city;
    int hours;
    char gender;
    bool flag=1;

    cout << "Please enter the name of the athlete, hours practiced, city of residence, and gender" << endl;

    while (flag !=0)
    {
        cin >> name >> hours >> city >> gender;
        cout << "Enter 0 to exit data entry or 1 to continue" << endl;
        cin >> flag;
    }
    //cout << setfill(" ");
    cout << "Name" << setw(10) << "Hours" << setw(10) << "City"
         << setw(15) << "Gender" << endl;
    //cout << setfill("-") << setw(55);

        cout << name << setw(10) << hours << setw(10) << city
         << setw(15) << gender << endl;
        
return 0;
}