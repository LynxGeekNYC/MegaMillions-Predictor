#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <json/json.h> // Include a JSON library like jsoncpp
#include <cmath>
#include <thread>
#include <mutex>

// Function to generate all possible combinations of 5 numbers from 1 to 70 and Mega Ball from 1 to 25
void generateAllCombinations(std::set<std::string>& allCombinations) {
    for (int a = 1; a <= 70; ++a) {
        for (int b = a + 1; b <= 70; ++b) {
            for (int c = b + 1; c <= 70; ++c) {
                for (int d = c + 1; d <= 70; ++d) {
                    for (int e = d + 1; e <= 70; ++e) {
                        for (int megaBall = 1; megaBall <= 25; ++megaBall) {
                            allCombinations.insert(std::to_string(a) + "," + std::to_string(b) + "," +
                                std::to_string(c) + "," + std::to_string(d) + "," + std::to_string(e) + "," +
                                std::to_string(megaBall));
                        }
                    }
                }
            }
        }
    }
}

// Function to load drawn numbers from JSON file
void loadDrawnNumbers(const std::string& jsonFilePath, std::set<std::string>& drawnCombinations) {
    std::ifstream jsonFile(jsonFilePath);
    Json::Value jsonData;
    Json::Reader reader;

    if (!reader.parse(jsonFile, jsonData)) {
        std::cerr << "Failed to parse JSON file." << std::endl;
        return;
    }

    for (const auto& draw : jsonData["data"]) {
        std::string combination;
        for (int i = 0; i < 5; ++i) {
            combination += draw[i].asString() + ",";
        }
        combination += draw[5].asString(); // Mega Ball
        drawnCombinations.insert(combination);
    }
}

// Function to save missing combinations to a CSV file
void saveToCSV(const std::string& csvFilePath, const std::set<std::string>& missingCombinations) {
    std::ofstream csvFile(csvFilePath);
    csvFile << "Combination" << std::endl;
    for (const auto& combination : missingCombinations) {
        csvFile << combination << std::endl;
    }
}

int main() {
    // File paths
    const std::string jsonFilePath = "lottery_data.json"; // Input JSON file
    const std::string csvFilePath = "missing_combinations.csv"; // Output CSV file

    // Data structures
    std::set<std::string> allCombinations;
    std::set<std::string> drawnCombinations;

    // Generate all possible combinations
    std::cout << "Generating all possible combinations..." << std::endl;
    generateAllCombinations(allCombinations);

    // Load drawn numbers
    std::cout << "Loading drawn numbers..." << std::endl;
    loadDrawnNumbers(jsonFilePath, drawnCombinations);

    // Identify missing combinations
    std::cout << "Identifying missing combinations..." << std::endl;
    std::set<std::string> missingCombinations;
    for (const auto& combination : allCombinations) {
        if (drawnCombinations.find(combination) == drawnCombinations.end()) {
            missingCombinations.insert(combination);
        }
    }

    // Save missing combinations to CSV
    std::cout << "Saving missing combinations to CSV..." << std::endl;
    saveToCSV(csvFilePath, missingCombinations);

    std::cout << "Process completed. Missing combinations saved to " << csvFilePath << std::endl;
    return 0;
}
