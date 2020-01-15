#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

//Declare grading function prototype
char examGrade(int score);

int main()
{
    //Declare variables
    int i, score, len;
    int noOfQuestions = 20;
    char ID[9];
    char ch;
    ifstream infile;

    //Declare pointer variables
    char* keyString;    //Char pointer to store the answer key
    char* answerString; //Char pointer to store the student's answers

    //Open input file
    infile.open("input.txt");
    if (!infile)
    {
        cout << "Cannot open input file. Program terminated." << endl;
        return 1;
    }

    //Create dynamic arrays for answer key and student answers
    keyString = new char[noOfQuestions + 1];
    answerString = new char[noOfQuestions + 1];

    //Read in the answer key
    cout << "Processing Data" << endl;
    infile.get(keyString, noOfQuestions + 1);

    //Output the answer key
    cout << "Key: " << keyString << endl
         << endl;

    //Set up output formatting
    cout << left << setw(15) << "Student ID"
         << setw(25) << "Student Answers"
         << setw(10) << "Score"
         << setw(10) << "Grade" << endl;

    //Read in data for first student
    infile >> ID;
    infile.get(ch); //This will read in the whitespace character between ID and answers

    infile.get(answerString, noOfQuestions + 1); //Reads in characters of answer to answer array

    //Loop through remaining information
    while (infile)
    {
        len = strlen(answerString);
        for (i = len; i < noOfQuestions; i++) //fill missing characters in string with whitespace
            answerString[i] = ' ';

        answerString[noOfQuestions] = '\0';

        //Initialize score variable to 0
        score = 0;

        for (i = 0; i < noOfQuestions; i++) //Loop through each answer in the char string
            if (answerString[i] != ' ')     //If no answer, nothing happens because 0 points
            {
                if (answerString[i] == keyString[i]) //Check if answer matches key for that question
                {
                    score = score + 2; //Correct answers earn 2 points
                }
                else
                {
                    score = score - 1; //Wrong answers lose a point
                }
            }
    
        //Output all data
        cout << left << setw(15) << ID
             << setw(25) << answerString
             << setw(10) << score
             << setw(10) << examGrade(score) << endl;
        
        //Read in the next line of data
        infile >> ID;
        infile.get(ch);
        infile.get(answerString, noOfQuestions +1 );
    }

    cout << endl;

    //Close input file
    infile.close();

    //Delete the arrays
    delete [] keyString;
    delete [] answerString;

return 0;
}

//Grading function
char examGrade(int score)
{
    switch (static_cast<int>(score / 40.0 * 10))
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return 'F';
    case 6:
        return 'D';
    case 7:
        return 'C';
    case 8:
        return 'B';
    case 9:
    case 10:
        return 'A';
    default:
        return 'F';
    }
}