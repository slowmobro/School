#include <iostream>
#include <fstream>

using namespace std;

struct fluidType
{
    string fluidName;
    int temperature;
    double specificGravity;
};

int main()
{
    fluidType fluidList[55];

    ifstream inData;
    inData.open("input.txt");
    

    for (int i = 0; i < 55; i++)
        inData >> fluidList[i].fluidName >> fluidList[i].temperature >> fluidList[i].specificGravity;

    for (int j = 0; j < 55; j++)
       { cout << fluidList[j].fluidName << endl;
        cout << fluidList[j].temperature << endl;
        cout << fluidList[j].specificGravity << endl;

       }
inData.close;
return 0;
}