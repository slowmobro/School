#include <map>
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string shape;
    cout << "Please enter the name of the figure: " << endl;
    cin >> shape;

    map<string, int> nameToNumSides = {{"triangle", 3},
    {"quadrilateral", 4}, {"pentagon", 5}, {"hexagon", 6},
    {"heptagon", 7}, {"octagon", 8}, {"nonagon", 9}, {"decagon", 10} }; 

    transform(shape.begin(), shape.end(), shape.begin(), ::toupper); 
    shape = tolower(shape);

    int numSides = nameToNumSides[shape];

    cout << "The number of the sides of a Triangle is:" << numSides << endl
        << "The sum of all the angles of a Triangle is: " << (numSides - 2) * 180 << endl;
}