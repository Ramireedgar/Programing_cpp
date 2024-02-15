#ifndef GROCERYANALYZER_H
#define GROCERYANALYZER_H

#include <map>
#include <string>

class GroceryAnalyzer {
public:
    // Constructor
    GroceryAnalyzer();

    void run();
private:
    void readInputFile();
    void writeBackupFile() const;
    void printFrequency() const;
    void printHistogram() const;

    // Private data members
    std::map<std::string, int> data;
};

#endif // GROCERYANALYZER_H
