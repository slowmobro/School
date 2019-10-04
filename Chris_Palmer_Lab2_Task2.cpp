#include <iostream>

using namespace std;
int main ()
{
    //Declare variables
    double score1, score2, score3, score4,
        averageScore;
    //Request user input of test scores
    cout << "PLease enter the first test score" << endl;
    cin >> score1;
    cout << "and the second test score" << endl;
    cin >> score2;
    cout << "and the third test score" << endl;
    cin >> score3;
    cout << "and the fourth test score" << endl;
    cin >> score4;

    averageScore = (score1+score2+score3+score4) / 4; //Calculate total score and average
   
    cout << "The average test score is " << averageScore; //Display result to user

    return 0;
}