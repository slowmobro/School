#include <iostream>
#include "bookInfo.h"
#include "bookInfo.cpp"
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //Declare class "books" of type bookType
    bookType books;
    //Call function to count books
    books.countBook();
    //Call the functions to input data and print data to user 
    books.gatherData();
    books.printData();
    

return 0;
}