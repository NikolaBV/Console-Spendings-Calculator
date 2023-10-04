/*
Simple spendings calculator in C++ to excercise using all datatypes,
 operators, loops, conditional statements, arrays and functions with parameters
*/

/*
   1. Main menu with a switch case menu in which you can choose which day of the week
   you are going to be loading in spendings for
   2. The spendings have to be saved after the program is closed. This will be done by on choosing a day of the week
   from the menu, the program will check if there is a text file with the name of the day in the folder. If there is
   it will print the existing data to the console, if not it will create a text file and prompt you to write your savings in
   
*/
#include <iostream>
#include <fstream>

using namespace std;

//Function Declarations
bool doesDayTextFileExist(string filename);
void CreateTextFile(string filename); 

int main()
{
    int input;
    cout << "Welcome to spendings calculator!" << endl;

    cout << "1. Monday\n"
    "2. Tuesday\n"
    "3. Wednesday\n"
    "3. Thursday\n"
    "5. Friday\n"
    "6. Saturday\n"
    "7. Sunday\n";

    cout << "Choose a day with its number: ";
    cin >> input;
    
    switch(input)
    {
        case 1:
        cout << "Monday";
        doesDayTextFileExist("Monday");
        break;
        case 2:
        cout << "Tuesday";
        break;
        case 3:
        cout << "Wednesday";
        break;
        case 4:
        cout << "Thursday";
        break;
        case 5:
        cout << "Friday";
        break;
        case 6:
        cout << "Saturday";
        break;
        case 7:
        cout << "Sunday";
        break;
        default:
        cout << "No such day of the week!" << endl;
        return 1;
        break;
    }

}

//<summery> Proverqva dali sushtestvuva s fail s ime koeto sme dali
//Kato argument i ako ne go suzdava
//</summery>
bool doesDayTextFileExist(string filename) 
{
    ifstream file(filename + ".txt");
    if(file.good())
    {
        cout << "Yes\n";
        return true;
    }
    else
    {
        cout << "Yok\n";
        CreateTextFile(filename);
        return false;
    }
    return false;
}


//<summery> Suzdava textov file s ime 
//passnato kato argument na funkciqta s nqkakav primeren input v textoviq file
//</summery>
void CreateTextFile(string filename)
{
    ofstream outputFile(filename + ".txt");

    if(outputFile.is_open())
    {
        
    }
    else
    {
        cerr << "Error opening the file\n";
    }
    outputFile << "Hello, World!" << endl;
    outputFile << "This is a text file created using C++." << endl;
}