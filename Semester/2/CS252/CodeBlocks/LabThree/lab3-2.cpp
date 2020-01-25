#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream input ("data2.txt");
    while (!input.eof())
    {
        int k = -12345;
        input >> k;
        cout << k << endl;
    }
    return 0;
}

