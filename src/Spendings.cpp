/*
Simple spendings calculator in C++ to excercise using all datatypes,
 operators, loops, conditional statements, arrays and functions with parameters
*/

/*
   1. Main menu with a switch case menu in which you can choose which day of the week
   you are going to be loading in spendings for
   2. The spendings have to be saved after the program is closed. This will be done by on choosing a day of the week
   from the menu, the program will check if there is a CSV file with the name of the day in the folder. If there is
   it will print the existing data to the console, if not it will create a CSV file and prompt you to write your savings in
   
*/
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

//Function Declarations
void PrintMenu();
void GetUserInput();
bool doesDayCSVFileExist(const string& directory, const string& filename);
void CreateCSVFile(const string& directory, const string& filename);
bool isCSVFileEmpty(const string& directory, const string& filename);
void menuForCSVFileActions(string filename);
void editCSVFile(string filename);
void printContetsOfCSVFile(string filename);

//<summery> Reshih da izpolzvam maisv za da moje pri printirane na menuto na consolata
//da moje da se iterira prez nego vmesto da se copy i pasteva edno i sushto
//</summery>
int lengthOfDaysOfTheWeek = 6;

string CSVFilesdirectory = "E:\\Programming\\C++\\Console-Spendings-Calculator\\csv\\";
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

    do
    {
        cout << "Choose a day with its number: ";
        cin >> input;
    } while(input < 1 || input > 7);
    

    switch(input)
    {
        case 1:
        doesDayCSVFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\csv","Monday");
        fullPath =  CSVFilesdirectory + "/" + daysOfTheWeek[0] + ".csv";

        //TODO Take this logic out in a seperate function
        // This ef else statement underneath in a "IsFileEmpty()" function
        if(isCSVFileEmpty(CSVFilesdirectory, daysOfTheWeek[0]))
        {
           menuForCSVFileActions(daysOfTheWeek[0]);
        }
        else
        {
            printContetsOfCSVFile(daysOfTheWeek[0]);
            printContetsOfCSVFile(daysOfTheWeek[0]);
        }
        break;
        case 2:
        cout << "Tuesday\n";
        doesDayCSVFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\csv","Tuesday");
        break;
        case 3:
        cout << "Wednesday";
        doesDayCSVFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\csv","Wednesday");
        break;
        case 4:
        cout << "Thursday";
        doesDayCSVFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\csv","Thursday");
        break;
        case 5:
        cout << "Friday";
        doesDayCSVFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\csv","Friday");      
        break;
        case 6:
        cout << "Saturday";
        doesDayCSVFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\csv","Saturday");
        break;
        case 7:
        cout << "Sunday";
        doesDayCSVFileExist("E:\\Programming\\C++\\Console-Spendings-Calculator\\csv","Sunday");
        break;
        default:
        cout << "No such day of the week!" << endl;
        break;
    }
}

void menuForCSVFileActions(string filename)
{
    system("cls");
    cout         << "No spendings for this day.\n";
    cout         << "Press E to start editing the file\n"
                 << "Press B to go back to the menu\n"
                 << "Press Q to quit the program\n" ;

        char ch = _getch();

        if (ch == 'e' || ch == 'E') 
        {
            editCSVFile(filename);
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
void editCSVFile(string filename)
{  
     
}

void printContetsOfCSVFile(string filename)
{
    ifstream inputFile(CSVFilesdirectory + filename + ".csv");

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
bool doesDayCSVFileExist(const string& directory, const string& filename) {
    string fullPath = directory + "/" + filename + ".csv";
    ifstream file(fullPath);

    if (file.good()) {
        
        file.close();
        return true;
    }
    else
    {
        CreateCSVFile(directory, filename);
        return false;
    }
}

//<summery> Suzdava CSVov file s ime 
//passnato kato argument na funkciqta s nqkakav primeren input v CSVoviq file
//</summery>
void CreateCSVFile(const string& directory, const string& filename)
{
    string fullPath = directory + "/" + filename + ".csv";
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

bool isCSVFileEmpty(const string& directory, const string& filename)
{
    string fullPath = directory + "/" + filename + ".csv";
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
        CreateCSVFile(directory, filename);
        return true;
    }
}



