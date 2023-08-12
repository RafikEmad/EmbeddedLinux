# Sample user data
valid_users = {
    "Ahmed": "1394",
    "Ali": "6078",
    "Amr": "9345"
}

# Get user input
entered_username = input("Enter your username: ")
entered_password = input("Enter your password: ")

# Check if the entered data is correct
if entered_username in valid_users and valid_users[entered_username] == entered_password:
    print("Welcome! You have successfully logged in.")
else:
    print("Incorrect entry. Please check your username and password.")