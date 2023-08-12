# Input list
numbers = [15, 6, 42, 32, 9, 21, 18]

# Initialize the largest variable with the first element of the list
largest = numbers[0]

# Loop through the list to find the largest item
for num in numbers:
    if num > largest:
        largest = num

# Print the largest item
print(f"The largest item in the list is: {largest}")
#########################################
print("################################################")
# Input list
numbers = [15, 6, 42, 32, 9, 21, 18]

# Find the largest item using max()
largest = max(numbers)
print(f"The largest item in the list is: {largest}")

# Sort the list using sorted()
sorted_numbers = sorted(numbers)
print("The sorted list:", sorted_numbers)