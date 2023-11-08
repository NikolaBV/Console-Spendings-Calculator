#ifndef SPENDINGS_CALCULATOR_H
#define SPENDINGS_CALCULATOR_H

#include <string>

class SpendingsCalculator {
    public:
        SpendingsCalculator();
        void Run();
        void PrintMenu();
        void GetUserInput();
        bool doesDayCSVFileExist(const std::string& filename);
        void CreateCSVFile(const std::string& filename);
        bool isCSVFileEmpty(std::string& filename);
        void menuForCSVFileActions(std::string& filename);
        void editCSVFile(std::string& filename);
        void printContentsOfCSVFile(std::string& filename);
};
#endif // SPENDINGS_CALCULATOR_H