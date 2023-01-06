import numpy as np

# Assume we have the following 3 rows of Prior MegaMillion winning data, where the last column is the output we want to predict
data = [
    [1, 2, 3, 4, 5, 6],
    [7, 8, 9, 10, 11, 12],
    [13, 14, 15, 16, 17, 18]
]

# Split the data into input (X) and output (y)
X = np.array([row[:5] for row in data])
y = np.array([row[5] for row in data])

# Train a model using the input-output pairs
from sklearn.linear_model import LinearRegression
model = LinearRegression()
model.fit(X, y)

# Predict the output for a new set of input
new_input = np.array([[19, 20, 21, 22, 23]])
prediction = model.predict(new_input)
print(prediction)
