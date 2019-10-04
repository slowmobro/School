///*************************************************************
/// Author: D.S. Malik
///
/// Program: nth Fibonacci number
/// Given the first two numbers of a Fibonacci sequence, this
/// determines and outputs the desired number of the Fibonacci
/// sequence.
///*************************************************************

#include <iostream>

using namespace std;

int main()
{
    ///Declare variables
    int previous1;
    int previous2;
    int current;
    int counter;
    int nthFibonacci;


    ///Prompt the user for the first two Fibonacci (previous1 and previous2).
    cout << "Enter the first two Fibonacci "
         << "numbers: ";                          //Step 1

    ///Read (Get) the first two Fibonacci numbers
    cin >> previous1 >> previous2;                //Step 2
    cout << endl;

    ///Output the first two Fibonacci numbers. (Echo input.)
    cout << "The first two Fibonacci numbers are "
         << previous1 << " and " << previous2
         << endl;                                 //Step 3

    ///Prompt the user for the position of the desired Fibonacci number.
    cout << "Enter the position of the desired "
         << "Fibonacci number: ";                 //Step 4

    ///Get the desired Fibonacci number
    cin >> nthFibonacci;                          //Step 5
    cout << endl;



    switch (nthFibonacci) 
    {
    case 'nthFibonacci == 1':                        //Step 6.a
          current = previous1;
          break;
    case 'nthFibonacci == 2':                   //Step 6.b
          current = previous2;
          break;
    default:                                          //Step 6.c
    {
        ///Initialize counter to 3
        counter = 3;                              //Step 6.c.1

        ///Calculate the next Fibonacci number
        while (counter <= nthFibonacci)
        {
            current = previous2 + previous1;      //Step 6.c.2
            previous1 = previous2;                //Step 6.c.3
            previous2 = current;                  //Step 6.c.4
            counter++;                            //Step 6.c.5
        }//end while
    }//end else
    }
     ///Output the nth Fibonacci number
    cout << "The Fibonacci number at position "
         << nthFibonacci << " is " << current
         << endl;                                 //Step 7

    return 0;
}//end main
