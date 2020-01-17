#ifndef BOOKINFO_H
#define BOOKINFO_H
#include <string>

using namespace std;

class bookType
{
public:
    //Function to count the number of books
    void countBook();
    //Function to gather input data from text file and assign to memory
    void gatherData();
    //Function to calculate the average lexile level
    double lexAvg();
    //Function to print the data
    void printData();

private:
    struct bookInfo //I use a struct to hold the book details
    {
        string title;
        string author;
        int noOfPages;
        int publishYear;
        int lexileLevel;
    };
    int bookCount; //int variable to count books with
    bookInfo bookArray[8]; //I use an array to hold each struct of each book
};

#endif