#include "GroceryAnalyzer.h"
#include <iostream>
#include <fstream>

// Constructor
GroceryAnalyzer::GroceryAnalyzer() {
    // Read input file and populate data
    readInputFile();
}

// Public member function to start the program
void GroceryAnalyzer::run() {
    int choice;
    do {
        // Display menu
        std::cout << "Menu:\n";
        std::cout << "1. Search for an item and get its frequency\n";
        std::cout << "2. Print frequency of all items\n";
        std::cout << "3. Print histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string item;
            std::cout << "Enter the item you wish to look for: ";
            std::cin >> item;

            auto iter = data.find(item);
            if (iter != data.end()) {
                std::cout << "Frequency of " << item << ": " << iter->second << std::endl;
            }
            else {
                std::cout << "Item not found.\n";
            }
            break;
        }
        case 2:
            printFrequency();
            break;
        case 3:
            printHistogram();
            break;
        case 4:
            writeBackupFile();
            std::cout << "Exiting program. Backup saved to frequency.dat.\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }

        // Clear the input buffer to prevent infinite loop
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 4);
}

// Private member function to read input file
void GroceryAnalyzer::readInputFile() {
    std::ifstream inputFile("CS210_Project_Three_Input_File.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file.\n";
        exit(EXIT_FAILURE);
    }
    else {
        std::cout << "Input file opened successfully" << std::endl;
    }

    std::string item;
    while (inputFile >> item) {
        std::cout << "Read from file: " << item << std::endl;
        data[item]++; // Increment the frequency of the word
    }

    inputFile.close();
}

// Private member function to write backup file
void GroceryAnalyzer::writeBackupFile() const {
    std::ofstream backupFile("frequency.dat");
    if (!backupFile.is_open()) {
        std::cerr << "Error: Unable to open backup file.\n";
        exit(EXIT_FAILURE);
    }

    for (const auto& entry : data) {
        backupFile << entry.first << " " << entry.second << std::endl;
    }

    backupFile.close();
}

// Private member function to print frequency
void GroceryAnalyzer::printFrequency() const {
    std::cout << "Frequency of all items:\n";
    for (const auto& entry : data) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }
}

// Private member function to print histogram
void GroceryAnalyzer::printHistogram() const {
    std::cout << "Histogram:\n";
    for (const auto& entry : data) {
        std::cout << entry.first << " ";
        for (int i = 0; i < entry.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
