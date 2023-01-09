# disclaimer
Disclaimer: Lottery games are based on random chance and it is not possible to predict or guarantee the outcome of a draw using any type of mathematical or statistical model. Predicting a random event is virtually impossible. I am not making any promises nor guarantees that this actually works. This is all for fun and entertainment purposes only. 

# MegaMillions Predictor Python
Toying with a Linear Regression Model Algorithm using Python to Predict MegaMillion Lotto Numbers. So far, it's been accurately predicting 2-3 numbers.

To predict future numbers based on prior results, you could use a machine learning algorithm that takes in the previous numbers as input and outputs the predicted numbers. One approach you could take is to use a supervised learning algorithm, where you provide the model with examples of input-output pairs and train it to predict the output given a new input.

Here's an example of how you could implement this in Python.

This example uses a linear regression model to predict the output based on the input, but you could try using other types of models to see if they perform better.

# MegaMillion Predictor C++

The C++ variant of the script seems to work better. It shows the most common winning number in each group. 

predictor.cpp - this is a basic varient that predict future numbers based on average (doesn't work that well.)
predictor-COMP.cpp - this is a basic varient that predicts future numbers based on frequency based on prior results (this seems to get 2-4 numbers correct almost every time
predictor-JSON.cpp - Same as "-COMP" variant but the data is stored in a JSON file instead of the code itself for better efficiency

JSON file with prior winning MegaMillion Lotto results will be available soon
