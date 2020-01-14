#ifndef LAPTOPREVIEWS_H
#define LAPTOPREVIEWS_H
#include <string>

using namespace std;

class laptopRate
{
public:
    string name;                        //string for name of laptop model
    int vBad, bad, ok, good, excellent; //int variables for number of each rating receieved
    void arrayDeclare();
    void dataGrab();
    int pointCount(int);

private:
    int total; //variable to store total of all review points
   
};

#endif