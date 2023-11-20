#ifndef SPENDINGS_CALCULATOR_H
#define SPENDINGS_CALCULATOR_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class SpendingsCalculator {
    public:
        SpendingsCalculator();
        void Run();
        int getCurrentWeek();
        void PrintMenu();
        void GetUserInput();
        void createWeeklySpendingsCSV();
        void findSpendingsForAlldaysOfTheWeek();
        void CreateCSVFile(const std::string& filename);
        bool isCSVFileEmpty(std::string& filename);
        void menuForCSVFileActions(std::string& filename);
        void editCSVFile(std::string& filename);
        void printContentsOfCSVFile(std::string& filename);
        bool isValidInputFormat(const std::string& input);
        double sumOfAllSpendings(const std::vector<std::string>& spendingValues);
        std::vector<std::vector<std::string>> readCSVFile(const std::string& filePath);
        std::vector<std::string> findColumn(const std::vector<std::vector<std::string>>& data, const std::string& columenName);
    private:
        int currentWeek;
};
#endif // SPENDINGS_CALCULATOR_H