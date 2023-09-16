# Initialize an empty dictionary to store employee data
employee_database = {}

def add_employee():
    employee_id = input("Enter unique employee ID: ")
    
    if employee_id in employee_database:
        print("Employee with this ID already exists.")
    else:
        name = input("Enter employee name: ")
        job = input("Enter employee job: ")
        salary = float(input("Enter employee salary: "))
        
        employee_database[employee_id] = {'Name': name, 'Job': job, 'Salary': salary}
        print(f"Employee with ID {employee_id} added successfully.")

def print_employee_data():
    employee_id = input("Enter employee ID to view data: ")
    
    if employee_id in employee_database:
        employee_data = employee_database[employee_id]
        print(f"Employee ID: {employee_id}")
        print(f"Name: {employee_data['Name']}")
        print(f"Job: {employee_data['Job']}")
        print(f"Salary: {employee_data['Salary']}")
    else:
        print("Employee not found.")

def remove_employee():
    employee_id = input("Enter employee ID to remove: ")
    
    if employee_id in employee_database:
        del employee_database[employee_id]
        print(f"Employee with ID {employee_id} removed successfully.")
    else:
        print("Employee not found.")

while True:
    print("\nEmployee Database Management System")
    print("1. Add new employee")
    print("2. Print employee data")
    print("3. Remove employee")
    print("4. Exit")
    
    choice = input("Enter your choice (1/2/3/4): ")
    
    if choice == '1':
        add_employee()
    elif choice == '2':
        print_employee_data()
    elif choice == '3':
        remove_employee()
    elif choice == '4':
        print("Exiting the program.")
        break
    else:
        print("Invalid choice. Please select a valid option.")
