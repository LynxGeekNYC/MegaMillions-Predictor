import pandas as pd
from collections import Counter

# Read CSV file into a DataFrame
df = pd.read_csv('lottery_results.csv')

# Extract the 'numbers' column from the DataFrame
numbers = df['numbers']

# Count the frequency of each number
number_counts = Counter(numbers)

# Find the number(s) with the highest frequency
most_common_numbers = [number for number, count in number_counts.most_common()]

# Predict the next lottery result based on the most common numbers
next_result = most_common_numbers[0]

print("The predicted next lottery result is:", next_result)
