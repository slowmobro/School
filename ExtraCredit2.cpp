#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Function to double bacteria each hour 
int growthCount (int bacteriaA, int hours);

int main()
{
/*This for loop counts by 3 from 0 to 24
On the left, every third hour is printed
Next to that we take the value of i and set that as the hour
to use in the growth function */
for (int i = 0; i <= 24; i= i + 3)
    cout << i << setw(30) << growthCount(2,i) << setw(30) << endl;
for (int x = 0; x <= 24; x= x + 3)
    cout << x << setw(30) << growthCount (2, x) << setw(30) << endl;
    

return 0;
}

int growthCount (int bacteriaCount, int hours)
{
    bacteriaCount = 1; //we start with a single bacteria
    for (int i = 0; i < hours; i++) //Each hour the bacteria double 
        bacteriaCount = bacteriaCount * 2;
    return bacteriaCount; //Return the bacteria for each hour 
}