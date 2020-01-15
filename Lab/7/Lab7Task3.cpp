#include <iostream>
#include <iomanip>

using namespace std;

//Declare function prototypes
void getLength(int &feet, double &inches);
void giveLength(int feet, double inches, double meters);
void lengthConvert(int feet, double inches, double& meters);

//Set constant variables for the lengths 
const double METERS_PER_FOOT = 0.3058;
const double INCHES_PER_FOOT = 12;

int main()
{
    //Declare variables
    int feet;
    double inches, meters;
    char ans;

    //Enter do...while loop to allow for program repetition
    do
    {
        getLength (feet, inches);      //Call length input function
        lengthConvert (feet, inches,meters);   //Call length conversion function
        giveLength (feet, inches, meters);  //Call length output function 

        //Prompt to continue
        cout << "Enter Y or y to continue,"
             << "any other input will quit program" << endl;
        //Read input
        cin >> ans;
    } while ('Y' == ans || 'y' == ans); //Determine if loop should continue

    return 0;
}

void getLength(int& feet, double& inches)
{
    //Prompt for length in feet
    cout << "Enter number of feet" << endl;
    cin >> feet;
    //Prompt for length in inches
    cout << "Enter number of inches" << endl;
    cin >> inches;
}

void lengthConvert(int feet, double inches, double& meters)
{
    //Set meters equal to meters/foot times the total length in feet/inches
    meters = METERS_PER_FOOT * (feet + inches/INCHES_PER_FOOT);
}

void giveLength (int feet, double inches, double meters)
{
    //Set decimal precision to 2 places
    cout << showpoint << fixed << setprecision(2);
    //Output original length input and conversion
    cout << "You entered: " << endl 
         << feet << " ft." << endl
         << inches << "in.\n" << endl
         << "The equivalent length in meters and centimeters is:" << endl
         << meters << endl;
}