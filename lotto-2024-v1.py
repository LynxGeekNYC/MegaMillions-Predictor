import pandas as pd
import numpy as np

def load_data(file_path):
    """Load data from CSV file"""
    return pd.read_csv(file_path, header=None)

def create_transition_matrix(data):
    """Create transition matrix based on frequency"""
    num_states = 71  # 70 numbers (1-70) + 1 for no occurrence
    transition_matrix = np.zeros((num_states, num_states))
    
    # Iterate over rows to calculate transition matrix
    for index, row in data.iterrows():
        prev_num = None
        for num in row:
            # Convert to integer if possible, otherwise skip
            try:
                num = int(num)
            except ValueError:
                continue
            
            # Check if the number is within the valid range
            if 1 <= num <= 70:
                if prev_num is not None:
                    transition_matrix[prev_num][num] += 1
                prev_num = num
    
    # Normalize transition matrix
    row_sums = transition_matrix.sum(axis=1, keepdims=True)
    transition_matrix /= row_sums

    return transition_matrix

def predict_numbers_freq(transition_matrix, num_sets=1, num_numbers=6):
    """Predict next group of numbers based on frequency"""
    predicted_numbers = []
    
    for _ in range(num_sets):
        current_state = np.random.randint(1, 71)  # Initial state
        numbers = [current_state]
        
        for _ in range(num_numbers - 1):
            next_state = np.random.choice(np.arange(1, 71), p=transition_matrix[current_state])
            numbers.append(next_state)
            current_state = next_state
        
        # Add the 6th number (1-25)
        numbers.append(np.random.randint(1, 26))
        
        predicted_numbers.append(numbers)
    
    return predicted_numbers

def predict_numbers_unused(data, num_sets=1, num_numbers=6):
    """Predict next group of numbers based on unused numbers"""
    used_numbers = set(data.values.flatten().astype(int))  # Flatten all column values into a single set
    unused_numbers = set(range(1, 71)) - used_numbers
    
    predicted_numbers = []
    
    for _ in range(num_sets):
        numbers = np.random.choice(list(unused_numbers), num_numbers - 1, replace=False)
        numbers = list(numbers) + [np.random.randint(1, 26)]  # Add the 6th number
        predicted_numbers.append(numbers)
    
    return predicted_numbers

def main():
    file_path = "prior_results.csv"
    data = load_data(file_path)
    
    transition_matrix = create_transition_matrix(data)
    
    # Predict next group of numbers based on frequency
    predicted_freq_numbers = predict_numbers_freq(transition_matrix)
    print("Predicted numbers based on frequency:")
    for numbers in predicted_freq_numbers:
        print(numbers)
    
    # Predict next group of numbers based on unused numbers
    predicted_unused_numbers = predict_numbers_unused(data)
    print("\nPredicted numbers based on unused numbers:")
    for numbers in predicted_unused_numbers:
        print(numbers)

if __name__ == "__main__":
    main()
