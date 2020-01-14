#include <iostream>

using namespace std;

int main()
{
    int howScared =0;

    cout << "I have not coded in a while, I am scared" << endl
         << "On a scale of 1-10, how scared am I?" << endl;
    cin >> howScared;

    while (howScared != 11)
        switch (howScared)
        {
        case 0:
            cout << "Pfft, I got this" << endl;
            cin >> howScared;
            break;
        case 1:
        case 2:
            cout << "It may not be the best thing ever" << endl;
            cin >> howScared;

            break;
        case 3:
        case 4:
        case 5:
            cout << "I may be in for a big challenge" << endl;
            cin >> howScared;

            break;
        case 6:
        case 7:
            cout << "Oh my god what am I about to do" << endl;
            cin >> howScared;

            break;
        case 8:
        case 9:
            cout << "I'm scared please hold me" << endl;
            cin >> howScared;
            break;
        case 10:
            cout << "sjfiaslifunawliuniwng" << endl;
            cin >> howScared;

            break;
        default:
            cout << "Invalid input";
        }
    cin >> howScared;
    return 0;
}