#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //Declare variables
    ifstream infile;
    infile.open("volcano.txt");
    int counter = 0;
    struct volcano
    {
        char type;
        double time;
        double reading;
    };

    while (infile)
    {
        string fill;
        getline(infile, fill);
        counter++;
    }

    volcano volcanoArray[counter];

    for (int i = 0; i < counter; i++)
    {
        volcanoArray[i].type = ' ';
        volcanoArray[i].time = 0.00;
        volcanoArray[i].reading = 0.00;
    }

    for (int i = 0; i < counter; i++)    
    {
        infile >> volcanoArray[i].type; 
        //infile.ignore(' ');
        infile >> volcanoArray[i].time;
        infile >> volcanoArray[i].reading;
       // infile.ignore(100, '\n');
    }

    infile.close();


   return 0; 
}