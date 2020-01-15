#include <iostream>

using namespace std;

int main()

{

    float speed[20], temp;

    int i, j, n;

    string name[20], ss;

    cout << "Enter how many insects do you have: ";

    cin >> n;

    cout << "Enter name and speed :" << endl;

    for (i = 0; i < n; i++)

    {

        cin >> name[i];

        cin >> speed[i];
    }

    //sorting

    for (i = 0; i < n - 1; i++)

    {

        for (j = 0; j < n - i - 1; j++)

        {

            if (speed[j] < speed[j + 1])

            {

                temp = speed[j];

                speed[j] = speed[j + 1];

                speed[j + 1] = temp;

                ss = name[j];

                name[j] = name[j + 1];

                name[j + 1] = ss;
            }
        }
    }

    cout << endl
         << endl
         << "INSECT_NAME SPEED" << endl
         << "--------------------------" << endl;

    for (i = 0; i < n; i++)

    {

        cout << name[i] << " " << speed[i] << endl;
    }

    cout << "THE FATEST INSECT IS " << name[0];
}