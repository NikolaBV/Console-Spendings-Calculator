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
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

//Function Declarations
bool doesDayTextFileExist(const string& directory, const string& filename);
void CreateTextFile(const string& directory, const string& filename);
void PrintMenu();
void GetUserInput();
bool isTextFileEmpty(const string& directory, const string& filename);
void menuForTextFileActions(string filename);
void editTextFile(string filename);
void printContetsOfTextFile(string filename);

//<summery> Reshih da izpolzvam maisv za da moje pri printirane na menuto na consolata
//da moje da se iterira prez nego vmesto da se copy i pasteva edno i sushto
//</summery>

int lengthOfDaysOfTheWeek = 6;

string textFilesdirectory = "E:\\Programming\\C++\\Console-Spendings-Calculator\\txt\\";
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

//<summery> Prints the main menu on the console
//</summery>
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
    string fullPath;
    string directory = "E:\\Programming\\C++\\Console-Spendings-Calculator\\txt\\";

    do
    {
        cout << "Choose a day with its number: ";
        cin >> input;
    } while(input < 1 || input > 7);
    

    switch(input)
    {
        case 1:
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Monday");
        fullPath =  directory + "/" + daysOfTheWeek[0] + ".txt";
        if(isTextFileEmpty(directory, daysOfTheWeek[0]))
        {
           menuForTextFileActions(daysOfTheWeek[0]);
        }
        else
        {
            printContetsOfTextFile(daysOfTheWeek[0]);
        }
        break;
        case 2:
        cout << "Tuesday\n";
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Tuesday");
        fullPath =  directory + "/" + daysOfTheWeek[1] + ".txt";
        if(isTextFileEmpty(directory, daysOfTheWeek[1]))
        {
           menuForTextFileActions(daysOfTheWeek[1]);
        }
        else
        {
            printContetsOfTextFile(daysOfTheWeek[1]);
            editTextFile(daysOfTheWeek[0]);
        }
        break;
        case 3:
        cout << "Wednesday";
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Wednesday");
        break;
        case 4:
        cout << "Thursday";
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Thursday");
        break;
        case 5:
        cout << "Friday";
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Friday");      
        break;
        case 6:
        cout << "Saturday";
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Saturday");
        break;
        case 7:
        cout << "Sunday";
        doesDayTextFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\txt","Sunday");
        break;
        default:
        cout << "No such day of the week!" << endl;
        break;
    }
}

void menuForTextFileActions(string filename)
{
    system("cls");
    cout         << "No spendings for this day.\n";
    cout         << "Press E to start editing the file\n"
                 << "Press B to go back to the menu\n"
                 << "Press Q to quit the program\n" ;

        char ch = _getch();

        if (ch == 'e' || ch == 'E') 
        {
            editTextFile(filename);
            cout << "Go to the file editing menu (it doesnt exist yet, i am working on it)" << endl;
        } 
        else if (ch == 'b' || ch == 'B') 
        {
            //TODO Figure out a way to clear the console before printing the menu again
            system("cls");
            PrintMenu();       
        }
        else if(ch == 'q' || ch == 'Q')
        {
            return;
        }
}
void editTextFile(string filename)
{  
     cout << "Here will be the menu adding, removing and editing specific items in the file";
}

void printContetsOfTextFile(string filename)
{
    ifstream inputFile(textFilesdirectory + filename + ".txt");

    if (inputFile.is_open()) {
        std::string line;
        while (getline(inputFile, line)) {
            std::cout << line << std::endl;
        }

        inputFile.close();
    } else {
        std::cerr << "Unable to open the file." << endl;
    }
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
        cerr << "Error: Failed to create the file " << fullPath << endl;
    }
    newFile.close();
    cout << filename <<" was created";
    cin.get();
    system("cls");
    PrintMenu();
}

bool isTextFileEmpty(const string& directory, const string& filename)
{
    string fullPath = directory + "/" + filename + ".txt";
    ifstream file(fullPath);

    if(file.is_open())
    {
        char character;

        if(file.get(character))
        {
             file.close();
             return false;
        }
        file.close();
        return true;
    }
    else
    {
        cout << "The file doesn't exist";
        CreateTextFile(directory, filename);
        return true;
    }
}



