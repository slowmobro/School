#include <iostream>
#include <cmath>

using namespace std;
//Declare function prototypes
void input(double&, double&, double&, double&, double&);
double calc (double&, double&, double&, double&);
//Set constant variable of gravity
const double g = 9.81;

int main()
{
    //Declare main function variables
    double V0, theta, x, H1, H2, y;
    double H1margin, H2margin;

    //Call functions
    input (V0, theta, x, H1, H2);
    calc (x, V0, theta, y);

    //Calculate safety area for human
    H1margin = y - H1;
    H2margin = y - H2;

    //If else statement to output whether human is safe or not depending on margins
    if (H1margin >= 1.00 && H2margin >= 1.00)
        cout << "Safe";
    else 
        cout << "Not Safe";

return 0;
}

//I use a series of if statements to check that the inputs are valid
void input (double& V0, double& theta, double& x, double& H1, double& H2)
{
    cout << "Enter the velocity" << endl;  
    cin >> V0;
        if (V0 < 0 || V0 > 100)
        {
            cout << "ERROR. Velocity must be between 0 and 100" << endl;
            cout << "Enter a valid value for velocity:" << endl;
            cin >> V0;
        }
    cout << "Enter the launch angle" << endl;
    cin >> theta;
        if (theta < 0 || theta > 90)
        {
            cout << "ERROR. Launch angle must be between 0 and 90" << endl;
            cout << "Enter a valid value for the launch angle:" << endl;
            cin >> theta;
        }
    cout << "Enter the distance from cannon to wall" << endl;
    cin >> x;
        if (x <0 || x > 1000)
        {
            cout << "ERROR. Distance must be between 0 and 1000" << endl;
            cout << "Enter a valid value for distance:" << endl;
            cin >> x;
        }
    cout << "Enter the height of the bottom of the hole" << endl;
    cin >> H1;
        if (H1 < 0 || H1 > 999) 
        {
            cout << "ERROR. Lower height must be between 0 and 999" << endl;
            cout << "Enter a valid value for lower height:" << endl;
            cin >> H1;
        }
    cout << "Enter the height of the top of the hole" << endl;
    //Here I use an else if statement to check both requirements, that H2 be greater
    //than H1 as well as H2 being less than 1000
    cin >> H2;
        if (H2 < H1)
        {
            cout << "ERROR. Upper height must be greater than bottom height" << endl;
            cout << "Enter a valid value for upper height" << endl;
            cin >> H2;
        }
        else if (H2 > 1000)
        {
            cout << "ERROR. Top height must be less than 1000" << endl;
            cout << "Enter a valid value for upper height:" << endl;
            cin >> H2;
        }
    //Not sure if I need a final else statement or not, but program seems to run fine without
}    
//Calculate the time it takes for the human to reach point y, represented by the return statement
double calc (double& x, double& V0, double& theta, double& y)
    {
        double t = x / (V0 * cos(theta));
        // double range = (V0 * t * cos(theta));
        //I played around with verifying that the cannonball range would be 
        //Greater than the distance to the wall but had difficulty 
        //Making this output any correct values 
        return y = (V0*t*sin(theta)) - (0.5*g*(t*t));
    }