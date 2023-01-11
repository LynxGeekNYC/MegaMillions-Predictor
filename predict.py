import pandas as pd
import random

# Read the CSV file
df = pd.read_csv("lottery_results.csv")

# Get the most common numbers for the first 5 spots
common_nums = df.iloc[:, :5].mode().values[0]

# Get the most common number for the 6th spot
common_num = df.iloc[:, 5].mode().values[0]

# Generate a list of remaining numbers for 6th spot
remaining_nums = [i for i in range(1,26) if i not in common_num]

# Choose a random number from the remaining numbers for 6th spot
next_num = random.choice(remaining_nums)

# Append the next number to the common numbers
common_nums = list(common_nums)
common_nums.append(next_num)

# Print the predicted numbers
print("Predicted numbers:", common_nums)
