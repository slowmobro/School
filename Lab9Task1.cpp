#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Define struct computerType
struct computerType
{
    string manufac;
    string model;
    string process;
    int ram; //in GB
    int hdd; //in GB
    int year;
    double price;
};

//Define function prototypes
void compInput(computerType& build);
void compOutput(computerType& build);

int main()
{
    //Declare struct variable
    computerType build;

    //Call functions
    compInput(build);
    compOutput(build);

return 0;
}

//Input function
//Uses getline to read each language input line as an entire string
//And normal cin with >> operator to read the numerical inputs
void compInput(computerType& build)
{
    cout << "Enter the name of the manufacturer: " << endl; //Each line requests input for each member of the struct
    getline (cin, build.manufac);
    cout << endl;

    cout << "Enter the model of the computer: " << endl;
    getline (cin, build.model);
    cout << endl;

    cout << "Enter processor type: " << endl;
    getline (cin, build.process);
    cout << endl;

    cout << "Enter the size of RAM (in GB): " << endl;
    cin >> build.ram;
    cout << endl;

    cout << "Enter the size of hard drive (in GB): " << endl;
    cin >> build.hdd;
    cout << endl;

    cout << "Enter the year the computer was built: " << endl;
    cin >> build.year;
    cout << endl;

    cout << "Enter the price: " << endl;
    cin >> build.price;
    cout << endl;
}

//Function for output
void compOutput(computerType& build)
{
    //Set decimal precision to 2 places for prices ending in 00
    //Output each member of the struct on separate lines
    cout << fixed << showpoint << setprecision(2);
    cout << "Manufacturer: " << build.manufac << endl
         << "Model: " << build.model << endl
         << "Processor: " << build.process << endl
         << "RAM: " << build.ram << " GB" << endl
         << "Hard drive size: " << build.hdd << " GB" << endl
         << "Year built: " << build.year << endl
         << "Price: $" << build.price << endl
         << endl;
}