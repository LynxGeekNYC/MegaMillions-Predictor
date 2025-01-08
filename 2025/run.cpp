#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

// Function to generate all possible combinations of numbers
void generateCombinations(std::set<std::vector<int>>& combinations) {
    std::vector<int> temp(5);
    for (int i = 1; i <= 66; ++i) {
        for (int j = i + 1; j <= 67; ++j) {
            for (int k = j + 1; k <= 68; ++k) {
                for (int l = k + 1; l <= 69; ++l) {
                    for (int m = l + 1; m <= 70; ++m) {
                        temp[0] = i;
                        temp[1] = j;
                        temp[2] = k;
                        temp[3] = l;
                        temp[4] = m;
                        combinations.insert(temp);
                    }
                }
            }
        }
    }
}

int main() {
    std::ifstream file("Lottery_Mega_Millions_Winning_Numbers.csv");
    std::string line;
    std::map<int, std::map<int, int>> frequency;
    std::set<std::vector<int>> allCombinations;
    std::set<std::vector<int>> winningCombinations;

    // Read the header
    std::getline(file, line);

    // Read the data
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, numbers;
        std::getline(ss, date, ',');
        std::getline(ss, numbers);

        std::istringstream numStream(numbers);
        std::vector<int> nums(5);
        int pos = 0;
        while (numStream >> nums[pos]) {
            ++pos;
        }

        // Count frequency of each position
        for (size_t i = 0; i < nums.size(); ++i) {
            frequency[i + 1][nums[i]]++;
        }

        // Sort to maintain order
        std::sort(nums.begin(), nums.end());
        winningCombinations.insert(nums);
    }

    // Generate all possible combinations
    generateCombinations(allCombinations);

    // Find combinations that have not won
    std::set<std::vector<int>> combinationsNotWon;
    std::set_difference(allCombinations.begin(), allCombinations.end(),
                        winningCombinations.begin(), winningCombinations.end(),
                        std::inserter(combinationsNotWon, combinationsNotWon.begin()));

    std::cout << "Combinations that have not won yet: " << combinationsNotWon.size() << std::endl;

    // Print most common numbers for each position
    for (const auto& pos : frequency) {
        int maxFreq = 0;
        int num = 0;
        for (const auto& freq : pos.second) {
            if (freq.second > maxFreq) {
                maxFreq = freq.second;
                num = freq.first;
            }
        }
        std::cout << "Position " << pos.first << ": Number " << num << " appeared " << maxFreq << " times" << std::endl;
    }

    return 0;
}
