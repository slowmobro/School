#include <iostream>

using namespace std;
int main()
{
    string shape;
    int Triangle, Quadrilateral, Pentagon, Hexagon,
        Heptagon, Octagon, Nonagon, Decagon;

    cout << "Please enter the name of the figure: " << endl;
    cin >> shape;

    Triangle = 3;
    Quadrilateral = 4;
    Pentagon = 5;
    Hexagon = 6;
    Heptagon = 7;
    Octagon = 8;
    Nonagon = 9;
    Decagon = 10;

    if ((shape == "Triangle") || (shape == "triangle"))
        cout << "The number of the sides of a Triangle is:" << Triangle << endl
             << "The sum of all the angles of a Triangle is: " << (Triangle - 2) * 180 << endl;
    else if ((shape == "Quadrilateral") || (shape == "quadrilaterial"))
        cout << "The number of the sides of a Quadrilateral is: " << Quadrilateral << endl
             << "The sum of all the angles of a Quadrilateral is: " << (Quadrilateral - 2) * 180 << endl;
    else if ((shape == "Pentagon") || (shape == "pentagon"))
        cout << "The number of the sides of a Pentagon is: " << Pentagon << endl
             << "The sum of all the angles of a Pentagon is: " << (Pentagon - 2) * 180 << endl;
    else if ((shape == "Hexagon") || (shape == "hexagon"))
        cout << "The number of the sides of a Hexagon is: " << Hexagon << endl
             << "The sum of all the angles of a Hexagon is: " << (Hexagon - 2) * 180 << endl;
    else if ((shape == "Heptagon") || (shape == "heptagon"))
        cout << "The number of the sides of a Heptagon is: " << Heptagon << endl
             << "The sum of all the angles of a Heptagon is: " << (Heptagon - 2) * 180 << endl;
    else if ((shape == "Octagon") || (shape == "octagon"))
        cout << "The number of the sides of a Octagon is: " << Octagon << endl
             << "The sum of all the angles of a Octagon is: " << (Octagon - 2) * 180 << endl;
    else if ((shape == "Nonagon") || (shape == "nonagon"))
        cout << "The number of the sides of a Nonagon is: " << Nonagon << endl
             << "The sum of all the angles of a Nonagon is: " << (Nonagon - 2) * 180 << endl;
    else if ((shape == "Decagon") || (shape == "decagon"))
        cout << "The number of the sides of a Decagon is: " << Decagon << endl
             << "The sum of all the angles of a Decagon is: " << (Decagon - 2) * 180 << endl;
    else
        cout << "You have entered an invalid shape name. Please try again" << endl;
    return 0;
}