#include <iostream>
#include <iomanip>

using namespace std;

//Function prototype for sorting the sales by amount
void sort(double list[], int Days_Week[], int length);

const int DAYS = 7; //constant variable representing the days in a week

int main()
{
    //Declare arrays to store sales and days of week
    double sales[DAYS];
    int week[7] = {1, 2, 3, 4, 5, 6, 7};

    //Variable to store the total amount of sales in the week
    double total = 0;

    for (int day = 0; day < DAYS; day++)
    {
        //Request input for sales
        cout << "Enter the sales for day " << day + 1 << ": $";
        cin >> sales[day];

        //Check for valid input (sales >= 0)
        while (sales[day] < 0)
        {
            cout << "\nSales must be greater than or equal to 0.\n"
                 << "Enter the sales for day " << day + 1 << ": $";
            cin >> sales[day];
        }
        //Update total sales
        total += sales[day];
    }
    //Call the sorting function
    sort(sales, week, DAYS);

    //Output sales total 
    cout << "\nTotal Sales: $" << total << endl;

    //Output the output column headers
    cout << setw(10) << left << "Day" << setw(10) << "Sales" << endl;

    //For loop to print the contents of both sorted arrays, week day and sales
    for (int i = 0; i < DAYS; i++)
    {
        cout << setw(10) << week[i] << setw(10) << sales[i] << endl;
    }
    return 0;
}

void sort(double list[], int Days_Week[], int length)
{
    int index;
    int smallestIndex;
    int location;
    int temp, temp_day;

    for (index = 0; index < length - 1; index++)
    {
        smallestIndex = index;

        //Find the index of the smallest sales element
        for (location = index + 1; location < length; location++)
            if (list[location] < list[smallestIndex])
                smallestIndex = location;

        //Swap the smallest sales element in the array with the first element
        temp = list[smallestIndex];
        list[smallestIndex] = list[index];
        list[index] = temp;

        //Swap the days of the days array in this same order
        temp_day = Days_Week[smallestIndex];
        Days_Week[smallestIndex] = Days_Week[index];
        Days_Week[index] = temp_day;
    }
}