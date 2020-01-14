#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int sumVotes(int list[], int size);
int winnerIndex(int list[], int size);

int main()
{
    //Declare variables
    int numberOfCandidates;
    string *candidates;
    int *votes;
    int totalVotes;
    int i;

    //Prompt for name and vote input of candidates
    cout << "Enter the number of candidates: ";
    cin >> numberOfCandidates;
    cout << endl;

    //Create dynamic arrays to hold info
    candidates = new string[numberOfCandidates];
    votes = new int[numberOfCandidates];

    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "Enter the candidate's name and the votes "
         << " received by the candidate." << endl;

    //Enter loop to store each candidate's info
    for (i = 0; i < numberOfCandidates; i++)
        cin >> candidates[i] >> votes[i];

    //Call function to calc total votes
    totalVotes = sumVotes (votes, numberOfCandidates);

    //Print output
    cout << endl << endl;
    cout << "Candidate    Votes Received    % of Total Votes" << endl;
    cout << "------------------------------------------------" << endl;

    for (i = 0; i < numberOfCandidates; i++)
        cout << left << setw(10) << candidates[i]
         << right << " " << setw(10) << votes[i] << "  "
         //Convert votes to double for precision
         << setw(15) << (static_cast<double>(votes[i]) / static_cast<double>(totalVotes)) * 100 
         << endl;

    cout << "Total           " << totalVotes << endl;
    cout << "The Winner of the Election is: " << candidates[winnerIndex(votes, numberOfCandidates)]
         << endl;

    //Delete arrays
    delete [] candidates;
    delete [] votes;

    return 0;    
}

//Sum the votes by taking each vote and adding it to the sum 
int sumVotes (int list[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum = sum + list[i];
    return sum;
}

//Determine the winner by comparing each vote amount with the one before it
int winnerIndex(int list[], int size)
{
    int winInd = 0;

    for (int i = 0; i < size; i++)
        if (list[i] > list[winInd])
            winInd = i;

    return winInd;
}