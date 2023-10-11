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
bool doesDayTextFileExist(const string& directory, const string& filename);
void CreateTextFile(const string& directory, const string& filename);
void PrintMenu(); 

int main()
{
   PrintMenu();
}

//<summery> Proverqva dali sushtestvuva s fail s ime koeto sme dali
//Kato argument i ako ne go suzdava
//</summery>
bool doesDayTextFileExist(const string& directory, const string& filename) {
    string fullPath = directory + "/" + filename + ".txt";
    ifstream file(fullPath);

    if (file.good()) {
        
        file.close();
        return true;
    }
    else
    {
        CreateTextFile(directory, filename);
        return false;
    }
}


//<summery> Suzdava textov file s ime 
//passnato kato argument na funkciqta s nqkakav primeren input v textoviq file
//</summery>
void CreateTextFile(const string& directory, const string& filename)
{
    string fullPath = directory + "/" + filename + ".txt";
    ofstream newFile(fullPath);
    if (!newFile.is_open()) {
        std::cerr << "Error: Failed to create the file " << fullPath << std::endl;
    }

    newFile.close();
}

void PrintMenu()
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
        cout << "Monday\n";
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Monday");
        break;
        case 2:
        cout << "Tuesday\n";
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Tuesday2");
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
        break;
    }
}