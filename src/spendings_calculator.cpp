#include "spendings_calculator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <conio.h>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <sstream>
#include <filesystem>

using namespace std;

const int lengthOfDaysOfTheWeek = 6;
const string CSVFilesdirectory = "csv\\";

string daysOfTheWeek[] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday",
};

struct Record {
    int week;
    double spendings;
};

SpendingsCalculator::SpendingsCalculator() {

}

void SpendingsCalculator::SpendingsCalculator::Run() {
    currentWeek = getCurrentWeek();
    createWeeklySpendingsCSV();
    PrintMenu();
}
void SpendingsCalculator::createWeeklySpendingsCSV()
{
    // Specify the directory path
    std::filesystem::path directoryPath("E:\\Programming\\C++\\Console-Spendings-Calculator\\csv\\");

    // Specify the file name
    std::string fileName = "WeeklySpendings.csv";

    // Combine the directory path and file name to create the full file path
    std::filesystem::path filePath = directoryPath / fileName;

    // Check if the file exists
    if (std::filesystem::exists(filePath)) {
        std::cout << "The file exists." << std::endl;
        return;
    } else {
        std::cout << "The file does not exist." << std::endl;
    }

    //
    ofstream newFile(CSVFilesdirectory + "WeeklySpendings" + ".csv");
    if (!newFile.is_open()) {
        cerr << "Error: Failed to create the file " << CSVFilesdirectory + "WeeklySpendings" + ".csv" << endl;
    }
    newFile.seekp(0, ios::end);
    if (newFile.tellp() == 0) {
        // If the file is empty, write the header row
        newFile << "Week, spendings" << endl;
    }
    newFile.close();
    cin.get();
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
    int input = 0;
 
    while(input < 1 || input > 7)
    {
        cout << "Choose a day with its number: ";
        cin >> input;
    }
    switch(input)
    {
        case 1:
        //TODO Take this logic out in a seperate function
        // This ef else statement underneath in a "IsFileEmpty()" function
        isCSVFileEmpty(daysOfTheWeek[0]);
        menuForCSVFileActions(daysOfTheWeek[0]);
        break;
        case 2:
        isCSVFileEmpty(daysOfTheWeek[1]);
        menuForCSVFileActions(daysOfTheWeek[1]);
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:  
        break;
        case 6:
        break;
        case 7:
        break;
        default:
        cout << "No such day of the week!" << endl;
        break;
    }
}

 void SpendingsCalculator::menuForCSVFileActions(std::string& filename)
{
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
            returnToMenu();     
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
        std::string input;

        cout << "Enter spending (name, price): ";
        getline(cin, input);

        
        if (input == ":wq") {
            cout << "Saving and quitting." << endl;
            break;
        } else if (input == ":q") {
            cout << "Quitting without saving." << endl;
            break;
        }
        else if (!isValidInputFormat(input)) {
            cout << "Invalid input format. Please use (description, price) format." << endl;
        }
         else {
                outputFile << input << endl;  
        }
    }

    outputFile.close();
     returnToMenu();
    // Read the file and calculate the sum after saving
    std::vector<std::vector<std::string>> data = readCSVFile(CSVFilesdirectory + filename + ".csv");
    
    // Exclude ":wq" from spendingValues
    std::vector<std::string> spendingValues;
    for (const auto& row : data) {
        if (row.size() > 1 && row[1] != ":wq") {
            spendingValues.push_back(row[1]);
        }
    }

    double sum = sumOfAllSpendings(spendingValues);
    updateWeeklySpendings(sum);
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
//Read the csv file and return the data
std::vector<std::vector<std::string>> SpendingsCalculator::readCSVFile(const std::string& filePath)
{
    // Vector to store CSV content
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filePath);
    std::string line;

    // Check if file cannot be opened and return empty data
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return data;
    }

    // Skip the first row (header)
    std::getline(file, line);

    // Get each row
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::istringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    file.close();
    return data;
}
//Find the values for a specific column based on its name and return them
std::vector<std::string> SpendingsCalculator::findColumn(const std::vector<std::vector<std::string>>& data, const std::string& columenName)
{
    std::vector<std::string> columnValues;
    size_t columnIndex = 0;
    if (!data.empty()) {
        // To find the specific column index
        for (const auto& header : data.front()) {
            if (header == columenName) {
                break;
            }
            ++columnIndex;
        }

        // Get column values after finding the index, start loop from 1 to skip the header row
        for (size_t i = 1; i < data.size(); ++i) {
            if (columnIndex < data[i].size()) {
                columnValues.push_back(data[i][columnIndex]);
            }
            else {
                // Push back empty string if the column doesn't have a value for that row
                columnValues.push_back("");
            }
        }
    }

    return columnValues;
}
//Calculate the sum of all spendings for that day based on the retrieved column values
double SpendingsCalculator::sumOfAllSpendings(const std::vector<std::string>& spendingValues)
{
    double sumOfAll = 0.0;
    std::vector<double> doubleSpendingsVector;

    for (const std::string& value : spendingValues) {
        if (value != ":wq") {
            try {
                size_t pos;  // Variable to capture the position of the first non-numeric character
                double convertedValue = std::stod(value, &pos);

                // Check if the entire string was converted (pos == value.length())
                // If not, skip this value
                if (pos == value.length()) {
                    doubleSpendingsVector.push_back(convertedValue);
                } else {
                    std::cerr << "Warning: Non-numeric characters found in value: \"" << value << "\". Skipping." << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                // Handle the invalid argument (e.g., print a warning message)
                std::cerr << "Warning: Invalid argument for value: \"" << value << "\". Skipping." << std::endl;
            }
        }
    }

    // Sum up all the elements inside the vector of doubles using accumulate
    sumOfAll = std::accumulate(doubleSpendingsVector.begin(), doubleSpendingsVector.end(), 0.0);
    std::cout << "Total spendings is: " << sumOfAll << std::endl;

    return sumOfAll;
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
bool SpendingsCalculator::isValidInputFormat(const std::string& input) {
    size_t commaPosition = input.find(',');
    if (commaPosition == std::string::npos || commaPosition == 0 || commaPosition == input.length() - 1) {
        return false;
    }
    return true;
}

int SpendingsCalculator::getCurrentWeek() 
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    // Assuming that the week starts from Sunday, tm_wday ranges from 0 (Sunday) to 6 (Saturday)
    int currentWeek = now->tm_yday / 7;
    return currentWeek + 1; // Add 1 to start counting from 1 instead of 0
}

void SpendingsCalculator::updateWeeklySpendings(double updatedSpending)
{
     // Read the current total spendings for the week from "WeeklySpendings.csv"
    std::vector<std::vector<std::string>> weeklySpendingsData = readCSVFile(CSVFilesdirectory + "WeeklySpendings.csv");

    // Find the column values for the week and spendings
    std::vector<std::string> weekValues = findColumn(weeklySpendingsData, "Week");
    std::vector<std::string> spendingsValues = findColumn(weeklySpendingsData, "spendings");

    // Find the index of the current week
    auto weekIndex = std::find(weekValues.begin(), weekValues.end(), std::to_string(currentWeek));

    // If the current week is found, update the corresponding spendings value
    if (weekIndex != weekValues.end()) {
        size_t index = std::distance(weekValues.begin(), weekIndex);

        // Update the spendings value for the current week
        if (index < spendingsValues.size()) {
            double currentSpendings = std::stod(spendingsValues[index]);
            currentSpendings += updatedSpending;

            // Update the spendings value in the vector
            spendingsValues[index] = std::to_string(currentSpendings);
        }
    } else {
        // If the current week is not found, add a new entry for the current week
        weekValues.push_back(std::to_string(currentWeek));
        spendingsValues.push_back(std::to_string(updatedSpending));
    }

    // Update the "WeeklySpendings.csv" file with the new spendings values
    std::ofstream weeklySpendingsFile(CSVFilesdirectory + "WeeklySpendings.csv");
    if (!weeklySpendingsFile.is_open()) {
        std::cerr << "Error: Unable to open WeeklySpendings.csv for writing." << std::endl;
        return;
    }

    // Write the header row
    weeklySpendingsFile << "Week, spendings" << std::endl;

    // Write the updated spendings values
    for (size_t i = 0; i < weekValues.size(); ++i) {
        weeklySpendingsFile << weekValues[i] << "," << spendingsValues[i] << std::endl;
    }

    weeklySpendingsFile.close();
}