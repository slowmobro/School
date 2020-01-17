#include <iostream>
#include <fstream>
#include "bookInfo.h"
#include <string>
#include <iomanip>

using namespace std;

//This function reads in the title of a book and increments the book counter
//The rest of the information is ignored
void bookType::countBook()
{
    ifstream inData;
    inData.open("input.txt");
    string counter; //dummy variable to hold title strings
    bookCount = 0;  //initialize book counter variable
    int fill = 0;   //dummy variable to hold integers in data

    while (inData)
    {
        getline(inData, counter);
        bookCount++;
        getline(inData, counter);
        inData >> fill;
        inData >> fill;
        inData >> fill;
        inData.ignore(100, '\n');
    }

    inData.close();
}

//This function grabs the data out of the text file and assigns each line to its position
//in the array of structs
void bookType::gatherData()
{
    ifstream inData;
    inData.open("input.txt");

    for (int i = 0; i < bookCount; i++) //I use the bookcount variable from earlier to determine
                                        //The number of loop iterations and cycle through the array
    {
        getline(inData, bookArray[i].title);
        getline(inData, bookArray[i].author);
        inData >> bookArray[i].noOfPages;
        inData >> bookArray[i].publishYear;
        inData >> bookArray[i].lexileLevel;
        inData.ignore(100, '\n');
    }

    inData.close();
}

//This function makes a new array of only the lexile numbers
//This is because you cannot use arithmetic on struct members
//I use a for loop to initialize the array and then assign each lexile member to a new
//Position in the array
double bookType::lexAvg()
{
    int lexTotal = 0;         //Variable to hold total lexile level
    double lexAverage = 0.00; //Variable to hold the average
    double bookCountDouble = bookCount; //Convert int bookCount to double so division isn't truncated
    int lexNumbers[bookCount];

    for (int j = 0; j <= bookCount; j++)
        lexNumbers[j] = 0;

    for (int i = 0; i <= bookCount; i++)
    {
        lexNumbers[i] = bookArray[i].lexileLevel; //Array member is assigned
        lexTotal += lexNumbers[i];                //Total lexile level is added up by each array member
    }
    lexAverage = lexTotal / bookCountDouble; //Divide total lexile level by # of books
    return lexAverage;
}

//Finally we print the data
void bookType::printData()
{
    cout << setfill(' '); //Column headers formatting
    cout << left << setw(24) << "Book Title";
    cout << left << setw(20) << "Author";
    cout << left << setw(12) << "No. Pages";
    cout << left << setw(14) << "Published in ";
    cout << right << "Lexile Level" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < bookCount; i++) //For loop to cycle through struct members
    {
        cout << setfill(' ');
        cout << left << setw(24) << bookArray[i].title;
        cout << left << setw(20) << bookArray[i].author;
        cout << left << setw(12) << bookArray[i].noOfPages;
        cout << left << setw(15) << bookArray[i].publishYear;
        cout << left << setw(12) << bookArray[i].lexileLevel << endl;
    }

    cout << fixed << showpoint << setprecision(2); //Finally output average lexile level using the function
    cout << endl
         << "The average Lexile score is: " << lexAvg() << endl;
}
