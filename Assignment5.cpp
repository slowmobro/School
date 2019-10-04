#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
   ifstream inData; //Declare ifstream variable and open the input file
   inData.open("input.txt");

   //Variables for everything including highest value of temperature, 
   //name of that substance, and a line counter
   string substanceName, highSubstance; 
   int counter;
   double boilPoint, totalTemp, max=0;

   //Set up and display column headers
   cout << "Common Chemicals and Substances: " << endl; 
   cout << endl;
   cout << left << setw(20) << "Substance" << right << " " << "Boiling Point" << endl;
   cout << setw(35) << setfill('-') << " " << endl;
   cout << setw(35) << setfill(' ') << " " << endl;

   //Read first line of file
   inData >> substanceName >> boilPoint;
   //While loop to iterate through each line after that, using EOF controller
   while (inData)
   {
      counter++; //Increment counter to count each line in the file to calculate the average 

      boilPoint = int (boilPoint); //Convert doubles to ints to match sample output

      totalTemp += boilPoint; //Set total temp by adding each new boil point

      if (boilPoint > max) //If loop to determine max boilpoint 
      {
         max = boilPoint;
         highSubstance = substanceName; //Also determine which substance has the highest boil point 
      }
      //Display the file data
      cout << left << setw(20) << substanceName
           << right << " " << left <<  boilPoint << endl;
      inData >> substanceName >> boilPoint;
   
   }
   cout << fixed << setprecision(2); //Set average temp to 2 decimal places
   cout << "The average boiling point is: " << totalTemp / counter  << endl; //Output average boil point
   cout << "The substance with the highest boiling point is: " << highSubstance << endl;//Output substance w/ high boil poii
   cout << "The highest boiling point is: " << max << endl; //Output maximum boil point

   inData.close(); //Close file 
   return 0;
}