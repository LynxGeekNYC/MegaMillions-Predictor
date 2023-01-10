#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>

//Here is a modified version of the previous example that reads the previous results from a 
//CSV file and predicts the next 6 groups of numbers based on the previous results, with the 
//prediction for each group being the most common number in the previous results:

//In this modified version, the program reads the previous results from a CSV file. The CSV file 
//should contain a group of numbers on each line, with the numbers in the group separated by commas.
//The rest of the program is similar to the previous example. We define a function 'predict' that takes 
//in the 'previousResults' and returns an integer representing the predicted result for the next group. 
//The function first counts the frequency of each number in the previous results using an unordered map. 
//It then finds the number with the highest frequency and returns it as the prediction.

//In the main function, we read the previous results from the CSV file and store it in a 2D vector. We use a 
//loop to read each line from the CSV file and parse it into a vector of integers. We then use another loop 
//to predict the next 6 groups of numbers, and print the prediction to the console in each iteration.


// Function that predicts the next group of numbers
int predict(const std::vector<std::vector<int>>& previousResults) {
  // Your prediction algorithm goes here
  // For example, you can find the most common number in the previous results
  std::unordered_map<int, int> counts;
  for (int i = 0; i < previousResults.size(); i++) {
    for (int j = 0; j < previousResults[i].size(); j++) {
      counts[previousResults[i][j]]++;
    }
  }
  int prediction = 0;
  int maxCount = 0;
  for (const auto& p : counts) {
    if (p.second > maxCount) {
      prediction = p.first;
      maxCount = p.second;
    }
  }
  return prediction;
}

int main() {
  // Read the previous results from a CSV file
  std::ifstream input("previous_results.csv");
  std::vector<std::vector<int>> previousResults;
  std::string line;
  while (std::getline(input, line)) {
    std::vector<int> group;
    std::stringstream ss(line);
    std::string value;
    while (std::getline(ss, value, ',')) {
      group.push_back(std::stoi(value));
    }
    previousResults.push_back(group);
  }

  // Predict the next 6 groups of numbers
  for (int i = 0; i < 6; i++) {
    int prediction = predict(previousResults);
    std::cout << "Prediction for group " << i + 1 << ": " << prediction << std::endl;
    previousResults.push_back({prediction});
  }

  return 0;
}
