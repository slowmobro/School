#include <iostream>
#include <cctype>>

using namespace std;

int main()
{
    char grade; //declare variable for input
    cout << "Please enter your midterm grade: " << endl; //prompt for input
    cin >> grade; //assign input to grade variable

    grade = toupper (grade); //convert lowercase input to uppercase
    switch (grade) //switch structure to compare inputs to outputs
    {
    case 'A':
        cout << "Excellent." << endl;
        break;
    case 'B':
        cout << "Very Good." << endl;
        break;
    case 'C':
        cout << "Passing." << endl;
        break;
    case 'D':
    case 'F':
        cout << "Not Good. Go study." << endl;
        break;
    default:
        cout << "That is not a possible grade." << endl;
    }
    return 0;
    
}