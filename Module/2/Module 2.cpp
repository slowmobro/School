#include <iostream>
using namespace std;
int main ()
{
    double length;
    double width;
    double area;
    double perimeter;

    cout << "Program to compute and output the ";
    cout << "perimeter and area of a rectangle.";
    // Fix this ^^ it prints very ugly and looks ugly 

    length = 6.0; //this also doesn't print to a new line
    width = 4.0;
    perimeter = 2 * (length + width);
    area = length * width;
/* This is how to make
    cout << "Length =" << length << endl;
    cout << "Width =" << width << endl;
    cout << "Perimeter =" << perimeter << endl;
    cout << "Area =" << area << endl;

return 0;
}