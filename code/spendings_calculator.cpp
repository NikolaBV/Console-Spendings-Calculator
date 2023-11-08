#include "headers/spendings_calculator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <conio.h>

using namespace std;

const int lengthOfDaysOfTheWeek = 6;
const string CSVFilesdirectory = "E:\\Programming\\C++\\Console-Spendings-Calculator\\csv\\";

string daysOfTheWeek[] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday",
};
SpendingsCalculator::SpendingsCalculator() {

}

void SpendingsCalculator::SpendingsCalculator::Run() {
    PrintMenu();
}

void SpendingsCalculator::PrintMenu()
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
void SpendingsCalculator::GetUserInput()
{
    int input;
 
    while(input < 1 || input > 7)
    {
        cout << "Choose a day with its number: ";
        cin >> input;
    }
    switch(input)
    {
        case 1:
        doesDayCSVFileExist("Monday");

        //TODO Take this logic out in a seperate function
        // This ef else statement underneath in a "IsFileEmpty()" function
        if(isCSVFileEmpty(daysOfTheWeek[0]))
        {
           menuForCSVFileActions(daysOfTheWeek[0]);
        }
        else
        {
            menuForCSVFileActions(daysOfTheWeek[0]);
        }
        break;
        case 2:
        cout << "Tuesday\n";
        doesDayCSVFileExist("Tuesday");
        break;
        case 3:
        cout << "Wednesday";
        doesDayCSVFileExist("Wednesday");
        break;
        case 4:
        cout << "Thursday";
        doesDayCSVFileExist("Thursday");
        break;
        case 5:
        cout << "Friday";
        doesDayCSVFileExist("Friday");      
        break;
        case 6:
        cout << "Saturday";
        doesDayCSVFileExist("Saturday");
        break;
        case 7:
        cout << "Sunday";
        doesDayCSVFileExist("Sunday");
        break;
        default:
        cout << "No such day of the week!" << endl;
        break;
    }
}

 void SpendingsCalculator::menuForCSVFileActions(std::string& filename)
{
    system("cls");
    cout         << "No spendings for this day.\n";
    cout         << "Press E to start editing the file\n"
                 << "Press B to go back to the menu\n"
                 << "Press Q to quit the program\n" ;

        char ch = _getch();

        if (ch == 'e' || ch == 'E') 
        {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            editCSVFile(filename);
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
void SpendingsCalculator::editCSVFile(string& filename)
{  
    ofstream outputFile(CSVFilesdirectory + filename + ".csv", ios::app);
    
     if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    
    outputFile.seekp(0, ios::end);
    if (outputFile.tellp() == 0) {
        // If the file is empty, write the header row
        outputFile << "description, price" << endl;
    }

    cout << "Enter your spending data for the day. To save and quit, type ':wq'. To quit without saving, type ':q'." << endl;
    while (true) {
        string input;
        cout << "Enter spending (name, price): ";
        getline(cin, input);

        if (input == ":wq") {
            cout << "Saving and quitting." << endl;
            break;
        } else if (input == ":q") {
            cout << "Quitting without saving." << endl;
            break;
        } else {
            outputFile << input << endl;
        }
    }

    outputFile.close();
}

void SpendingsCalculator::printContentsOfCSVFile(std::string& filename)
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
bool SpendingsCalculator::doesDayCSVFileExist(const string& filename) {
   
    ifstream file(CSVFilesdirectory + filename + ".csv");

    if (file.good()) {
        
        file.close();
        return true;
    }
    else
    {
        CreateCSVFile(filename);
        file.close();
        return false;
    }
}

//<summery> Suzdava CSVov file s ime 
//passnato kato argument na funkciqta s nqkakav primeren input v CSVoviq file
//</summery>
void SpendingsCalculator::CreateCSVFile(const std::string& filename)
{
    ofstream newFile(CSVFilesdirectory + filename + ".csv");
    if (!newFile.is_open()) {
        cerr << "Error: Failed to create the file " << CSVFilesdirectory + filename + ".csv" << endl;
    }

    

    newFile.close();
    cout << filename <<" was created";
    cin.get();
    system("cls");
    PrintMenu();
}

bool SpendingsCalculator::isCSVFileEmpty(string& filename)
{
    ifstream file(CSVFilesdirectory + filename + ".csv");

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
        CreateCSVFile(filename);
        return true;
    }
}