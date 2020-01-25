#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include<string>
#include <fstream>
#include <time.h>

using namespace std;

void Map(int [], string [], int); //Assign shuffled numbers to cards
int GetSize(); //Determine size of deck required to shuffle
int RandomInt(int); //Calculate random integer to shuffle numbers with
bool TestDeck(int [], int size); //Test that there are 4 of each suite card in deck no more / less
void PrintListString(string [], int, string); //Print list of shuffled cards
void PrintListInt(int [], int, string);  //Print list of shuffled numbers
void FilePrintListStr(string [], int); //Print shuffled card list to file
void FilePrintListInt(int [], int);  //Print shuffled number list to file
void Menu();
void CreateDeck(string [], int); //Most of deck creation process



int main()
{
    Menu();

    return 0;
}

void CreateDeck(string cards[], int size)
{
    int avail_cards[size];  //keeps a list of the cards we can put in our deck, if a card is used 4 times
    int current_size = size; //this variable will be decremented
    int times_card_used[size]; //this is used for the shuffling, lets us know how many times we have used each card as we move it to our final, shuffled deck

    int shuffled[size*4]; // array for our deck, with each integer representing a different card

    for(int i=0; i< size; i++) //initialize array
        avail_cards[i] = i;

    for(int i=0; i< size; i++) //initialize array
        times_card_used[i] = 4;

    int temp_index = -1;
    for(int i=0; i<size*4; i++)
    {
        temp_index = RandomInt(current_size);
        shuffled[i]= avail_cards[temp_index];   //use that random index, to see which card to insert at shuffled[i]
        times_card_used[avail_cards[temp_index]]--; //mark that we used that card

        //used index is "removed" from the list by shifting the numbers
        //then a current_size variable let's us know how much of array we can use
        //later in the course, you can use dynamic arrays to actually shrink the array
        //instead of keeping track with the current_size
        if(times_card_used[avail_cards[temp_index]] == 0)
        {
            for(int j = temp_index; j < current_size-1; j++)
                avail_cards[j]= avail_cards[j+1];
            current_size--;
        }
    }

    PrintListInt(shuffled, size, "Shuffled Numbers");

    //a deck with just number would be counter-intuitive for cards like king and queen
    //convert each integer to a string, and insert into the structure that holds our final deck
    //do this only if test passed
    if(TestDeck(shuffled, size) == true) //Call deck testing function and check its return for true/false
    {
        Map(shuffled, cards, size); //Call map function to assign strings to shuffled deck array

        PrintListString(cards, size, "Shuffled Cards"); //Call print to screen function

        FilePrintListStr(cards, size); //Call print to file function
    }
    else
        cout<<"Test failed\n";

}

void Menu()
{
    srand (time(NULL));

    int action = -1; //action allows us to navigate the menu, we choose 0 to exit, 1 to create a deck of cards
    while(action!=0)
    {

        system("CLS"); //this clears the screen
        cout<<setw(20)<<"Menu"<<endl;
        cout<<setw(30)<<std::left<<"Create Deck of Cards:"<<"1\n";
        cout<<setw(30)<<std::left<<"Exit:"<<"0\n";

reenter: //if we select an invalid menu item, we return here
        cout<<"Action:";
        cin>> action;
        cout<<endl;

        if(action == 1)  //if user wants to create deck of cards
        {
            int size = GetSize(); //Call function to determine number of cards of each suite
            string cards[size*4]; //create an array for actual deck, which has 4 of each card
            CreateDeck(cards, size);
        }
        else if(action == 0)
            break;
        else
        {
            cout<<"Please enter valid Menu item\n";
            goto reenter;
        }
    }
}

void FilePrintListInt(int shuffled[], int size)
{
    //output deck to file, if the test is successful
    string filename;
    cout<<"Enter file name:";
    cin>>filename;

    ofstream myfile(string(filename).c_str());
    if(myfile.is_open())
    {
        for(int i=0; i<size*4; i++)
            myfile<<shuffled[i]<<endl;
    }
    else
        cout<<"File could not open\n";
    myfile.close();
}

void FilePrintListStr(string cards[], int size)
{
    //output deck to file, if the test is successful
    string filename;
    cout<<"Enter file name:";
    cin>>filename;

    ofstream myfile(string(filename).c_str());
    if(myfile.is_open())
    {
        for(int i=0; i<size*4; i++)
            myfile<<cards[i]<<endl;
    }
    else
        cout<<"File could not open\n";
    myfile.close();
}

void PrintListString(string cards[], int size, string ShuffleCards)
{
    cout<<ShuffleCards<<endl;
    for(int i=0; i< size*4; i++)
        cout<<cards[i]<<endl;
    cout<<endl;
}

void PrintListInt(int shuffled[], int size, string ShuffleNum)
{
    cout<<ShuffleNum<<endl;
    for(int i=0; i< size*4; i++)
        cout<<shuffled[i]<<endl;
    cout<<endl;
}

bool TestDeck(int shuffled[], int size)
{
    //we test to see if our card deck has the right number of each card
    bool pass = true;
    int counter = 0;
    cout<<"Testing\n";

    //cycle through the numbers representing our cards
    for(int i=0; i<size; i++)
    {
        counter = 0;
        //for each number, go through the whole array and count how many times we see it
        for(int j = 0; j<size*4; j++)
        {
            if(shuffled[j] == i)
                counter++;
        }

        if(counter != 4)  //if we didn't see it 4 times, we did something wrong
        {
            pass = false;
            cout<<"Shuffle Wrong "<<i<<" not properly assigned";
            cout<<"Found "<<counter<<" times in shuffled list\n";
            exit (EXIT_FAILURE);
        }
        else //otherwise, all good, but output this to let us know our test is working
            cout<<i<<" found "<<counter<<" times"<<endl;
    }
    cout<<"Test successful\n\n";
}

int RandomInt(int current_size)
{
    return rand() % current_size; // get random index
}

int GetSize()
{
    int size = -1;
enterCards:
    cout<<"Enter Number of Individual Cards:"; //in standard deck 13 cards: Ace, 2, 3, 4, 5, ... Jack, Queen, King
    cin>>size;
    if(size<5 || size>13)
    {
        cout<<"Values should be in range between 5 and 13"<<endl;
        goto enterCards;
    }
    return size;
}

void Map(int shuffled[], string cards[], int size)
{
    for(int i=0; i<size*4; i++)
    {
        if(shuffled[i] == 0)
            cards[i]= "1";
        else if(shuffled[i] == 1)
            cards[i]= "2";
        else if(shuffled[i] == 2)
            cards[i]= "3";
        else if(shuffled[i] == 3)
            cards[i]= "4";
        else if(shuffled[i] == 4)
            cards[i]= "5";
        else if(shuffled[i] == 5)
            cards[i]= "6";
        else if(shuffled[i] == 6)
            cards[i]= "7";
        else if(shuffled[i] == 7)
            cards[i]= "8";
        else if(shuffled[i] == 8)
            cards[i]= "9";
        else if(shuffled[i] == 9)
            cards[i]= "10";
        else if(shuffled[i] == 10)
            cards[i] = "J";
        else if(shuffled[i] == 11)
            cards[i] = "Q";
        else if(shuffled[i] == 12)
            cards[i] = "K";
        else
        {
            cout<<"Something wrong\n";
            cout<<"at index "<<i<<" found card "<<cards[i]<<endl;
            exit (EXIT_FAILURE);
        }
    }
    cout<<"Map Successful\n\n";
}
