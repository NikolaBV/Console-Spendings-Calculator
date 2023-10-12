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
#include <string>

using namespace std;

//Function Declarations
bool doesDayTextFileExist(const string& directory, const string& filename);
void CreateTextFile(const string& directory, const string& filename);
void PrintMenu();
void GetUserInput();

//<summery> Reshih da izpolzvam maisv za da moje pri printirane na menuto na consolata
//da moje da se iterira prez nego vmesto da se copy i pasteva edno i sushto
//</summery>

int lengthOfDaysOfTheWeek = 6;

string daysOfTheWeek[] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday",
};

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
        cerr << "Error: Failed to create the file " << fullPath << std::endl;
    }

    newFile.close();
}

void PrintMenu()
{
    int counter = 1;

    cout << "Welcome to spendings calculator!" << endl;
    
    for(int i = 0; i <= lengthOfDaysOfTheWeek; i++)
    {
        cout << counter << ". " << daysOfTheWeek[i];
        counter++;
        cout << endl;
    }
    GetUserInput();
    
}

void GetUserInput()
{
    int input;
    do
    {
        cout << "Choose a day with its number: ";
        cin >> input;
    } while(input < 1 || input > 7);
    

    switch(input)
    {
        case 1:
        cout << "Monday\n";
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Monday");
        break;
        case 2:
        cout << "Tuesday\n";
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Tuesday");
        break;
        case 3:
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Wednesday");
        cout << "Wednesday";
        break;
        case 4:
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Thursday");
        cout << "Thursday";
        break;
        case 5:
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Friday");
        cout << "Friday";
        break;
        case 6:
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Saturday");
        cout << "Saturday";
        break;
        case 7:
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Sunday");
        cout << "Sunday";
        break;
        default:
        cout << "No such day of the week!" << endl;
        break;
    }
}