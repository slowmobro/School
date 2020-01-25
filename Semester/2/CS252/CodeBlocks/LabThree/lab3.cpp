#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    ifstream input ("data1.txt");
    string line;
    getline (input, line);
    while (input)
    {
        int count = 0;
        double sum = 0;
// Count and sum the numbers in the line
        istringstream lineIn (line);
        double num;
        while (lineIn >> num)
        {
            ++count;
            sum += num;
        }
        if (count > 0)
            cout << "Average over " << count << " numbers is " << sum/count << endl;
        else
            cout << "Cannot average 0 numbers." << endl;
        getline (input, line);
    }
    return 0;
}
