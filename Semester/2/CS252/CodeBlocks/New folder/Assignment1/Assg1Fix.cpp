#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct dimension
{
  double length;
  double width;
  double height;
};

struct fauna
{
  int id;
  string texture;
  string color;
  double health;
  dimension faunaSize;
  bool hostile;
};

struct character
{
  int id;
  string firstName;
  string lastName;
  double health;
  dimension characterSize;
};

struct structure
{
  int id;
  string texture;
  dimension structureSize;
};

void Menu();
void PrintCharacters();
void PrintStructures();
void PrintFauna(fauna gameFauna[], int);

int main()
{

  Menu();

  return 0;
}

void Menu()
{
  ifstream inData;
  inData.open("character.txt");

  character gameCharacter[7];
  fauna gameFauna[10];
  structure gameStructure[8];

  int characterAmount = 0;
  inData >> characterAmount;

  for (int counter = 0; counter < characterAmount; counter++)
  {

    inData >> gameCharacter[counter].id;
    inData >> gameCharacter[counter].firstName;
    inData >> gameCharacter[counter].lastName;
    inData >> gameCharacter[counter].health;
    inData >> gameCharacter[counter].characterSize.length;
    inData >> gameCharacter[counter].characterSize.width;
    inData >> gameCharacter[counter].characterSize.height;
  }
  inData.close();

  inData.open("fauna.txt");

  int faunaAmount = 0;
  inData >> faunaAmount;

  for (int counter = 0; counter <= faunaAmount; counter++)
  {

    inData >> gameFauna[counter].id;
    inData >> gameFauna[counter].texture;
    inData >> gameFauna[counter].color;
    inData >> gameFauna[counter].health;
    inData >> gameFauna[counter].faunaSize.length;
    inData >> gameFauna[counter].faunaSize.width;
    inData >> gameFauna[counter].faunaSize.height;
    inData >> gameFauna[counter].hostile;
  }
  inData.close();

  inData.open("structures.txt");

  int structureAmount = 0;
  inData >> structureAmount;

  for (int counter = 0; counter <= structureAmount; counter++)
  {

    inData >> gameStructure[counter].id;
    inData >> gameStructure[counter].texture;
    inData >> gameStructure[counter].structureSize.length;
    inData >> gameStructure[counter].structureSize.width;
    inData >> gameStructure[counter].structureSize.height;
  }
  inData.close();

  int action = -1;
  while (action != 0)
  {

    cout << setw(20) << "Menu" << endl;
    cout << setw(40) << std::left << "Print Fauna:" << right
         << "1\n";
    cout << setw(40) << std::left << "Print Characters:" << right
         << "2\n";
    cout << setw(40) << std::left << "Print Structures:" << right
         << "3\n";
    cout << setw(40) << std::left << "Print Averages:" << right
         << "4\n";
    cout << setw(40) << std::left << "Print Characters with Health in range:" << right
         << "5\n";
    cout << setw(40) << std::left << "Exit:"
         << "0\n";

  reenter:
    cout << "Action:";
    cin >> action;
    cout << endl;

    if (action == 1)
      PrintFauna(gameFauna, faunaAmount);
    else
        goto reenter;
  }
}

void PrintFauna(fauna gameFauna[10], int faunaAmount)
{
  for (int counter = 0; counter <= faunaAmount; counter++)
  {
    cout << left << setw(5) << "ID" << setw(6) << "Texture" << setw(10) << "Health" << setw(5) << "Length"
         << setw(5) << "Width" << setw(8) << "Height" << setw(3) << "Hostile" << endl
         << endl;
    cout << left << fixed << showpoint << setprecision(3) << setw(5) << gameFauna[counter].id
         << setw(6) << gameFauna[counter].texture
         << setw(10) << gameFauna[counter].color
         << setw(5) << gameFauna[counter].health
         << setw(5) << gameFauna[counter].faunaSize.length
         << setw(8) << gameFauna[counter].faunaSize.width
         << setw(3) << gameFauna[counter].faunaSize.height
         << gameFauna[counter].hostile << endl;
  }
}

void PrintCharacters()
{
}

void PrintStructures()
{
}
