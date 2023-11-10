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
        void PrintMenu();
        void GetUserInput();
        bool doesDayCSVFileExist(const std::string& filename);
        void CreateCSVFile(const std::string& filename);
        bool isCSVFileEmpty(std::string& filename);
        bool isValidInputFormat(const std::string& input);
        void menuForCSVFileActions(std::string& filename);
        void editCSVFile(std::string& filename);
        void printContentsOfCSVFile(std::string& filename);
        std::vector<std::vector<std::string>> readCSVFile(const std::string& filePath);
        std::vector<std::string> findColumn(const std::vector<std::vector<std::string>>& data, const std::string& columenName);
        double sumOfAllSpendings(const std::vector<std::string>& spendingValues);
};
#endif // SPENDINGS_CALCULATOR_H