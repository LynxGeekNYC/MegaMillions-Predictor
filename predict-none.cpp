#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <algorithm>

//Here is a modified version of the previous example that reads the previous results from a 
//CSV file, then it will predict the next 6 groups of numbers based on the numbers that 
//haven't been used yet:

//In this modified version, the program reads the previous results from a CSV file and stores it 
//in a 2D vector as before, however, now the 'predict' function will take those numbers and will add 
//them to an unordered set so that it can use this set to filter out the numbers that haven't been used yet.
//Then, we will use a loop that starts from 1 and goes up to 100 and will append to a vector each number that 
//hasn't been used yet, and then we will randomize this vector as a new prediction of numbers.
//Finally, we will use a loop to predict the next 6 groups of numbers, and we will print the prediction to the 
//console in each iteration, before appending the predictions to the previous results so that the new predictions 
//will be considered as previous results on the next iteration.

// Function that predicts the next group of numbers
std::vector<int> predict(const std::vector<std::vector<int>>& previousResults) {
  // Your prediction algorithm goes here
  std::unordered_set<int> usedNumbers;
  for (int i = 0; i < previousResults.size(); i++) {
    for (int j = 0; j < previousResults[i].size(); j++) {
      usedNumbers.insert(previousResults[i][j]);
    }
  }
  std::vector<int> predictions;
  for (int i = 1; i <= 100; i++) {
    if (usedNumbers.count(i) == 0) {
      predictions.push_back(i);
    }
  }
  std::random_shuffle(predictions.begin(), predictions.end());
  return predictions;
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
    std::vector<int> predictions = predict(previousResults);
    std::cout << "Prediction for group " << i + 1 << ": ";
    for (int j = 0; j < predictions.size(); j++) {
      std::cout << predictions[j] << " ";
    }
    std::cout << std::endl;
    previousResults.push_back(predictions);
  }

  return 0;
}
