def count_words(filename):
    try:
        with open(filename, 'r') as file:
            text = file.read()
            words = text.split()
        return len(words)
    except FileNotFoundError:
        return f"File '{filename}' not found."
    except Exception as e:
        return f"An error occurred: {str(e)}"

if __name__ == "__main__":
    filename = input("Enter the name of the file: ")
    word_count = count_words(filename)
    print(word_count)