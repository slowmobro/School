/*
 The following program is supposed to read the length and width
 of a rectangle from the user and then calculates the area of
 the rectangle. The program should write the area to an output file
 named output.txt. However, it fails to do so. Rewrite the program
 so that it accomplishes what it is intended to do. Make sure to
 include a statement to close the file. Also, write comments
 throughout the program to illustrate how you fixed the program.
*/

#include <iostream>
#include <fstream> //missing this header to enable file editing

using namespace std;

int main()
{
    double length, width;
    ofstream outFile; //ifstream is for input, changed to ofstream
    outFile.open("Output.txt"); //added command to open a file to write to
    
    //We are also missing the input from the user

    cout << "Please enter the length and width of the rectangle: " << endl;
    cin >> length >> width; 
    outFile << "Area = " << length * width << endl; //changed this to output as well

    outFile.close(); //closed file when done
    return 0;
}

