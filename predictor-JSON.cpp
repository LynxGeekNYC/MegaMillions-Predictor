#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <nlohmann/json.hpp>

//Here is a modified version of the previous example that reads the previous results 
//from a JSON file and predicts the next 6 groups of numbers based on the previous results, 
//with the prediction for each group being the most common number in the previous results:

//In this modified version, the program reads the previous results from a JSON file using the 
//JSON library by nlohmann. The JSON file should contain an array of arrays, with each inner 
//array representing a group of numbers.

//The rest of the program is similar to the previous example. We define a function 'predict' that 
//takes in the 'previousResults' and returns an integer representing the predicted result for the next 
//group. The function first counts the frequency of each number in the previous results using an unordered 
//map. It then finds the number with the highest frequency and returns it as the prediction.

//In the main function, we read the previous results from the JSON file and store it in a 2D vector. We then 
//use a loop to predict the next 6 groups of numbers, and print the prediction to the console in each iteration.

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
  // Read the previous results from a JSON file
  std::ifstream input("previous_results.json");
  nlohmann::json previousResultsJson;
  input >> previousResultsJson;
  std::vector<std::vector<int>> previousResults = previousResultsJson.get<std::vector<std::vector<int>>>();

  // Predict the next 6 groups of numbers
  for (int i = 0; i < 6; i++) {
    int prediction = predict(previousResults);
    std::cout << "Prediction for group " << i + 1 << ": " << prediction << std::endl;
    previousResults.push_back({prediction});
  }

  return 0;
}
