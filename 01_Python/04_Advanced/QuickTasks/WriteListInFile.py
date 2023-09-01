my_list = [1, 2, 3, 4, 5]

filename = "list_output.txt"

try:
    with open(filename, 'w') as file:
        # Iterate through the list and write each element to the file
        for item in my_list:
            file.write(str(item) + '\n')
    print(f"The list has been written to {filename}.")
except Exception as e:
    print(f"An error occurred: {str(e)}")