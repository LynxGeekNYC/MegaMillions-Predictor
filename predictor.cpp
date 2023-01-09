#include <iostream>
#include <vector>

//This script first defines a function 'predict' that takes in a 2D vector 'previousResults'
//representing the previous results and returns a vector representing the 'predicted' result 
//for the next group. The 'predict' function in this example simply returns the average of the 
//previous results as the prediction for the next group.
//In the main function, we first define the previous results as a 2D vector. We then use a 
//loop to predict the next 6 groups of numbers. In each iteration of the loop, we call the 
//predict function to get the predicted result for the next group, print the prediction to the 
//console, and add the predicted result to the 'previousResults' vector.
//I hope this helps! Let me know if you have any questions or if you need further assistance.


// Function that predicts the next group of MegaMillion Lotto numbers
std::vector<int> predict(const std::vector<std::vector<int>>& previousResults) {
  // Your prediction algorithm goes here
  std::vector<int> prediction;
  // For example, you can simply return the average of the previous results
  for (int i = 0; i < previousResults[0].size(); i++) {
    int sum = 0;
    for (int j = 0; j < previousResults.size(); j++) {
      sum += previousResults[j][i];
    }
    prediction.push_back(sum / previousResults.size());
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
    std::vector<int> prediction = predict(previousResults);
    std::cout << "Prediction for group " << i + 1 << ": ";
    for (int j = 0; j < prediction.size(); j++) {
      std::cout << prediction[j] << " ";
    }
    std::cout << std::endl;
    previousResults.push_back(prediction);
  }

  return 0;
}



