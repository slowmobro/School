#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//Declare const variable for the size of the class
const int NO_OF_STUDENTS = 20;

//Define a struct to contain student data
struct studentType
{
    string firstName;
    string lastName;
    int testScore;
    char grade;
};

//Define function prototypes
void getData(ifstream &inFile, studentType sList[], int listSize);
void gradeCalculate(studentType sList[], int listSize);
int highestScore(const studentType sList[], int listSize);
void print(ofstream &outFile, const studentType sList[], int listSize);

int main()
{
    //Declare I/O stream variables
    ifstream inData;
    ofstream outData;

    //Declare an array of struct
    studentType studentList[NO_OF_STUDENTS];

    //Open input file
    inData.open("data.txt");

    //Validate the input file
    if (!inData)
    {
        cout << "The input file does not exist. Program is terminated." << endl;
        return 1;
    }

    //Open the output file
    outData.open("Output.txt");

    //Validate the output file
    if (!outData)
    {
        cout << "The output file cannot be opened. Program is terminated." << endl;
        return 1;
    }

    //Call functions
    getData(inData, studentList, NO_OF_STUDENTS);
    gradeCalculate(studentList, NO_OF_STUDENTS);
    print(outData, studentList, NO_OF_STUDENTS);

    //Close both files 
    inData.close;
    outData.close;

    return 0;
}

//Function to gather input
void getData(ifstream &inFile, studentType sList[], int listSize)
{
    //Loops run as many times as there are students
    for (int i = 0; i < listSize; i++)
        inFile >> sList[i].firstName >> sList[i].lastName >> sList[i].testScore;
}

//Function to calculate and store letter grades of students
void gradeCalculate(studentType sList[], int listSize)
{
    for (int i = 0; i < listSize; i++) //for statement runs through all students
    {
        switch (sList[i].testScore / 10) //Divide test score by 10
        {
        case 10: //90-100 is an A
        case 9:
            sList[i].grade = 'A';
            break;
        case 8: //80-89 is a B
            sList[i].grade = 'B';
            break;
        case 7: //70-79 is a C
            sList[i].grade = 'C';
            break;
        case 6: //60-69 is a D
            sList[i].grade = 'D';
            break;
        case 5: //59 and below is an F
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            sList[i].grade = 'F';
        }
    }
}

//Function to determine the highest score
int highestScore(const studentType sList[], int listSize)
{
    int hScore = sList[0].testScore; //Variable to hold highest score

    //For loop iterates through each student and compares scores, keeping the highest
    for (int i = 1; i < listSize; i++)
        if (hScore < sList[i].testScore)
            hScore = sList[i].testScore;

    return hScore; //Return the value of the highest test score
}

void print(ofstream &outFile, const studentType sList[], int listSize)
{
    //Use highest score function to find highest score
    int maxScore = highestScore(sList, listSize);

    //Write category headers to file
    outFile << setw(15) << "Student Name             "
            << setw(10) << "Test Score"
            << setw(7) << "Grade" << endl;

    //For loop runs through each component and prints to file
    for (int i = 0; i < listSize; i++)
        outFile << left << setw(25)
                << sList[i].lastName + ", " + sList[i].firstName
                << right << " " << setw(5) << sList[i].testScore
                << setw(6) << " " << sList[i].grade << endl;

    //Print highest test score
    outFile << endl
            << "Highest Test Score: " << maxScore << endl;
    outFile << "Students having the highest test score:" << endl;

    //Print all the students who's scores match the highest
    for (int i = 0; i < listSize; i++)
        if (sList[i].testScore == maxScore)
            outFile << sList[i].lastName + ", " + sList[i].firstName << endl;
}