import sys

# Check if there are command-line arguments
if len(sys.argv) == 1:
    print("No command-line arguments provided.")
else:
    # Print the command-line arguments one by one
    print("Command-line arguments:")
    for arg in sys.argv[1:]:
        print(arg)