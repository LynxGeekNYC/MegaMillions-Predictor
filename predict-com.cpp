#include <iostream>
#include <vector>
#include <unordered_map>

//Here is a modified version of the previous example that predicts the next 6 groups of 
//numbers based on the previous results, with the prediction for each group being the most 
//common number in the previous results.

//In this modified version, the 'predict' function takes in the 'previousResults' and returns an 
//integer representing the predicted result for the next group. The function first counts the 
//frequency of each number in the previous results using an unordered map. It then finds the 
//number with the highest frequency and returns it as the prediction.

//The rest of the program is similar to the previous example. We define the previous results 
//as a 2D vector, use a loop to predict the next 6 groups of numbers, and print the prediction 
//to the console in each iteration.

// Function that predicts the next group of MegaMillion winning numbers
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
  // Previous results
  std::vector<std::vector<int>> previousResults = {
    {1, 2, 3, 4, 5, 6},
    {6, 5, 4, 3, 2, 1},
    {2, 4, 6, 8, 10, 12}
  };

  // Predict the next 6 groups of numbers
  for (int i = 0; i < 6; i++) {
    int prediction = predict(previousResults);
    std::cout << "Prediction for group " << i + 1 << ": " << prediction << std::endl;
    previousResults.push_back({prediction});
  }

  return 0;
}
