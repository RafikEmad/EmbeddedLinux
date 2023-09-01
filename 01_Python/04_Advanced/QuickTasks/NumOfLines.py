def count_lines(filename):
    try:
        with open(filename, 'r') as file:
            line_count = sum(1 for line in file)
        return line_count
    except FileNotFoundError:
        return f"File '{filename}' not found."
    except Exception as e:
        return f"An error occurred: {str(e)}"

if __name__ == "__main__":
    filename = input("Enter the name of the file: ")
    lines = count_lines(filename)
    print(f"The file '{filename}' contains {lines} lines.")