#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main (int argc, char** argv)
{
    ifstream input (argv[1]);
    ofstream output (argv[2]);
    cout << "This program received " << argc << " command parameters." <<
         endl;
    for (int i = 0; i < argc; ++i)
    {
        cout << "argv[" << i << "] is " << argv[i] << endl;
    }
    cout << "Now reading from " << argv[1] <<
         endl;
    cout << " and writing to " << argv[2] <<
         endl;
    string line;
    getline (input, line);
    while (input)
    {
        output << "I saw: " << line << endl;
        getline (input, line);
    }
    return 0;
}
