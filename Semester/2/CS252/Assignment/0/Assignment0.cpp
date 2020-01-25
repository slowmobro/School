#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;


void PrintListInt(int arr[], int size, string sortedDeck);
void PrintListString(int arr[], int size, string sortedDeck);
void FilePrintList(int arr[], int size);
int RandomInt (int ceiling);
int GetSize(); //finished??
void Menu();
void Map(int arr[], string arr[], int); //Finished??
bool TestDeck(int arr[], int);
void CreateDeck(string []);

int main()
{

  srand(time(NULL));

  int action = -1; //action allows us to navigate the menu, we choose 0 to exit, 1 to create a deck of cards
  while (action != 0)
  {

    system("CLS"); //this clears the screen
    cout << setw(20) << "Menu" << endl;
    cout << setw(30) << std::left << "Create Deck of Cards:"
         << "1\n";
    cout << setw(30) << std::left << "Exit:"
         << "0\n";

  reenter: //if we select an invalid menu item, we return here
    cout << "Action:";
    cin >> action;
    cout << endl;

    if (action == 1)
    { //if user wants to create deck of cards
      CreateDeck(cards[], GetSize());
      int size = GetSize();
      string cards[size * 4];    //create an array for actual deck, which has 4 of each card
      int avail_cards[size];     //keeps a list of the cards we can put in our deck, if a card is used 4 times
      int current_size = size;   //this variable will be decremented
      int times_card_used[size]; //this is used for the shuffling, lets us know how many times we have used each card as we move it to our final, shuffled deck

      int shuffled[size * 4]; // array for our deck, with each integer representing a different card

      for (int i = 0; i < size; i++) //initialize array
        avail_cards[i] = i;

      for (int i = 0; i < size; i++) //initialize array
        times_card_used[i] = 4;

      int temp_index = -1;
      for (int i = 0; i < size * 4; i++)
      {
        shuffled[i] = avail_cards[temp_index];      //use that random index, to see which card to insert at shuffled[i]
        times_card_used[avail_cards[temp_index]]--; //mark that we used that card

        //used index is "removed" from the list by shifting the numbers
        //then a current_size variable let's us know how much of array we can use
        //later in the course, you can use dynamic arrays to actually shrink the array
        //instead of keeping track with the current_size
        if (times_card_used[avail_cards[temp_index]] == 0)
        {
          for (int j = temp_index; j < current_size - 1; j++)
            avail_cards[j] = avail_cards[j + 1];
          current_size--;
        }
      }

      cout << "Shuffled Numbers" << endl;
      for (int i = 0; i < size * 4; i++)
        cout << shuffled[i] << endl;
      cout << endl;

      //we test to see if our card deck has the right number of each card
      bool pass = true;
      int counter = 0;
      cout << "Testing\n";

      //cycle through the numbers representing our cards
      for (int i = 0; i < size; i++)
      {
        counter = 0;
        //for each number, go through the whole array and count how many times we see it
        for (int j = 0; j < size * 4; j++)
        {
          if (shuffled[j] == i)
            counter++;
        }

        if (counter != 4)
        { //if we didn't see it 4 times, we did something wrong
          pass = false;
          cout << "Shuffle Wrong " << i << " not properly assigned";
          cout << "Found " << counter << " times in shuffled list\n";
          exit(EXIT_FAILURE);
        }
        else //otherwise, all good, but output this to let us know our test is working
          cout << i << " found " << counter << " times" << endl;
      }
      cout << "Test successful\n\n";

    Map(shuffled[], cards[], size);

        cout << "Shuffled Cards" << endl;
        for (int i = 0; i < size * 4; i++)
          cout << cards[i] << endl;
        cout << endl;

        //output deck to file, if the test is successful
        string filename;
        cout << "Enter file name:";
        cin >> filename;

        ofstream myfile(string(filename).c_str());
        if (myfile.is_open())
        {
          for (int i = 0; i < size * 4; i++)
            myfile << cards[i] << endl;
        }
        else
          cout << "File could not open\n";
        myfile.close();
      }
      else
        cout << "Test failed\n";
    }
    else if (action == 0)
      break;
    else
    {
      cout << "Please enter valid Menu item\n";
      goto reenter;
    }
  }
  return 0;
}
int GetSize()
{
    int size = -1;
    enterCards:
      cout << "Enter Number of Individual Cards:"; //in standard deck 13 cards: Ace, 2, 3, 4, 5, ... Jack, Queen, King
      cin >> size;
      if (size < 5 || size > 13)
      {
        cout << "Values should be in range between 5 and 13" << endl;
        goto enterCards;
      }
      return size;
}

void PrintListInt(int arr[], int size, string sortedDeck)
{

}

int RandomInt (int ceiling)
{
    temp_index = rand() % current_size;         // get random index
    return temp_index;
}

void Menu()
{

}

void Map(int shuffled[], string cards[], int size)
{
     //a deck with just number would be counter-intuitive for cards like king and queen
      //convert each integer to a string, and insert into the structure that holds our final deck
      //do this only if test passed
      if (pass == true)
      {

        for (int i = 0; i < size * 4; i++)
        {
          if (shuffled[i] == 0)
            cards[i] = "1";
          else if (shuffled[i] == 1)
            cards[i] = "2";
          else if (shuffled[i] == 2)
            cards[i] = "3";
          else if (shuffled[i] == 3)
            cards[i] = "4";
          else if (shuffled[i] == 4)
            cards[i] = "5";
          else if (shuffled[i] == 5)
            cards[i] = "6";
          else if (shuffled[i] == 6)
            cards[i] = "7";
          else if (shuffled[i] == 7)
            cards[i] = "8";
          else if (shuffled[i] == 8)
            cards[i] = "9";
          else if (shuffled[i] == 9)
            cards[i] = "10";
          else if (shuffled[i] == 10)
            cards[i] = "J";
          else if (shuffled[i] == 11)
            cards[i] = "Q";
          else if (shuffled[i] == 12)
            cards[i] = "K";
          else
          {
            cout << "Something wrong\n";
            cout << "at index " << i << " found card " << cards[i] << endl;
            exit(EXIT_FAILURE);
          }
        }
        cout << "Map Successful\n\n";
}
