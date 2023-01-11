import pandas as pd
import random

# Read the CSV file
df = pd.read_csv("lottery_results.csv")

# Get the most common numbers for all spots
common_nums = df.mode().values[0]

# Generate a list of remaining numbers for all spots
remaining_nums = [i for i in range(1,71) if i not in common_nums[:5]] + [i for i in range(1,26) if i not in common_nums[5:]]

# Choose random numbers from the remaining numbers
next_nums = random.sample(remaining_nums, 6)

# Print the predicted numbers
print("Predicted numbers:", next_nums)
