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
void PrintCharacters(character gameCharacter[], int);
void PrintStructures(structure gameStructure[], int);
void PrintFauna(fauna gameFauna[], int);
void PrintAvg(double, double, double, double, double, double, double, double, double);

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
  double sumLength = 0, sumWidth = 0, sumHeight = 0;

  for (int counter = 0; counter < characterAmount; counter++)
  {
    inData >> gameCharacter[counter].id;
    inData >> gameCharacter[counter].firstName;
    inData >> gameCharacter[counter].lastName;
    inData >> gameCharacter[counter].health;
    inData >> gameCharacter[counter].characterSize.length;
    inData >> gameCharacter[counter].characterSize.width;
    inData >> gameCharacter[counter].characterSize.height;
    sumLength += gameCharacter[counter].characterSize.length;
    sumWidth += gameCharacter[counter].characterSize.width;
    sumHeight += gameCharacter[counter].characterSize.height;
  }

  inData.close();
  double characterAvgLength = sumLength / characterAmount;
  double characterAvgWidth = sumWidth / characterAmount;
  double characterAvgHeight = sumHeight / characterAmount;

  inData.open("fauna.txt");

  int faunaAmount = 0;
  inData >> faunaAmount;
  sumLength = 0, sumWidth = 0, sumHeight = 0;

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
    sumLength += gameFauna[counter].faunaSize.length;
    sumWidth += gameFauna[counter].faunaSize.width;
    sumHeight += gameFauna[counter].faunaSize.height;
  }
  inData.close();

  double faunaAvgLength = sumLength / faunaAmount;
  double faunaAvgWidth = sumWidth / faunaAmount;
  double faunaAvgHeight = sumHeight / faunaAmount;

  inData.open("structures.txt");

  int structureAmount = 0;
  inData >> structureAmount;
  sumLength = 0, sumWidth = 0, sumHeight = 0;

  for (int counter = 0; counter <= structureAmount; counter++)
  {
    inData >> gameStructure[counter].id;
    inData >> gameStructure[counter].texture;
    inData >> gameStructure[counter].structureSize.length;
    inData >> gameStructure[counter].structureSize.width;
    inData >> gameStructure[counter].structureSize.height;
    sumLength += gameStructure[counter].structureSize.length;
    sumWidth += gameStructure[counter].structureSize.width;
    sumHeight += gameStructure[counter].structureSize.height;
  }
  inData.close();

  double structureAvgLength = sumLength / structureAmount;
  double structureAvgWidth = sumWidth / structureAmount;
  double structureAvgHeight = sumHeight / structureAmount;

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
    else if (action == 2)
      PrintCharacters(gameCharacter, characterAmount);
    else if (action == 3)
      PrintStructures(gameStructure, structureAmount);
    else if (action == 4)
      PrintAvg(faunaAvgLength, faunaAvgWidth, faunaAvgHeight, characterAvgLength, characterAvgWidth,
               characterAvgHeight, structureAvgLength, structureAvgWidth, structureAvgHeight);
    else if (action == 0)
      break;
    else
      goto reenter;
  }
}

void PrintFauna(fauna gameFauna[], int faunaAmount)
{
  cout << left << setw(5) << "ID" << setw(10) << "Texture" << setw(10) << "Color" << setw(10) << "Health" << setw(10) << "Length"
       << setw(10) << "Width" << setw(10) << "Height" << setw(10) << "Hostile" << endl
       << endl;
  for (int counter = 0; counter < faunaAmount; counter++)
  {

    cout << left << setw(5) << gameFauna[counter].id
         << setw(10) << gameFauna[counter].texture
         << setw(10) << gameFauna[counter].color
         << setw(10) << gameFauna[counter].health
         << setw(10) << gameFauna[counter].faunaSize.length
         << setw(10) << gameFauna[counter].faunaSize.width
         << setw(10) << gameFauna[counter].faunaSize.height
         << gameFauna[counter].hostile << endl;
  }
  cout << endl
       << endl;
}

void PrintCharacters(character gameCharacter[], int characterAmount)
{
  cout << left << setw(5) << "ID" << setw(10) << "FNAME" << setw(10) << "LNAME" << setw(10) << "Health" << setw(10) << "Length"
       << setw(10) << "Width" << setw(10) << "Height" << setw(10) << endl
       << endl;
  for (int counter = 0; counter < characterAmount; counter++)
  {

    cout << left << setw(5) << gameCharacter[counter].id
         << setw(10) << gameCharacter[counter].firstName
         << setw(10) << gameCharacter[counter].lastName
         << setw(10) << gameCharacter[counter].health
         << setw(10) << gameCharacter[counter].characterSize.length
         << setw(10) << gameCharacter[counter].characterSize.width
         << setw(10) << gameCharacter[counter].characterSize.height << endl;
  }
  cout << endl
       << endl;
}

void PrintStructures(structure gameStructure[], int structureAmount)
{
  cout << left << setw(5) << "ID" << setw(10) << "Texture" << setw(10) << setw(10) << "Length"
       << setw(10) << "Width" << setw(10) << "Height" << setw(10) << endl
       << endl;
  for (int counter = 0; counter < structureAmount; counter++)
  {

    cout << left << setw(5) << gameStructure[counter].id
         << setw(10) << gameStructure[counter].texture
         << setw(10) << gameStructure[counter].structureSize.length
         << setw(10) << gameStructure[counter].structureSize.width
         << setw(10) << gameStructure[counter].structureSize.height
         << endl;
  }
  cout << endl
       << endl;
}

void PrintAvg(double faunaAvgLength, double faunaAvgWidth, double faunaAvgHeight, double characterAvgLength,
              double characterAvgWidth, double characterAvgHeight, double structureAvgLength,
              double structureAvgWidth, double structureAvgHeight)
{
  cout << setw(10) << "      " << setw(20) << "Fauna" << setw(20) << "Structures" << setw(20) << "Characters" << endl;
  cout << setw(10) << "Length:" << setw(20) << faunaAvgLength << setw(20) << structureAvgLength << setw(20) << characterAvgLength << endl;
  cout << setw(10) << "Width:" << setw(20) << faunaAvgWidth << setw(20) << structureAvgWidth << setw(20) << characterAvgWidth << endl;
  cout << setw(10) << "Height:" << setw(20) << faunaAvgHeight << setw(20) << structureAvgHeight << setw(20) << characterAvgHeight << endl
       << endl;
}