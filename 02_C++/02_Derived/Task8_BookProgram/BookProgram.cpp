#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

void printContact(const Contact& contact) {
    std::cout << "Name: " << contact.name << std::endl;
    std::cout << "Phone: " << contact.phone << std::endl;
    std::cout << "Email: " << contact.email << std::endl;
    std::cout << "-------------------------" << std::endl;
}

int main() {
    std::vector<Contact> addressBook;

    while (true) {
        std::cout << "Address Book Menu:" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Search Contact" << std::endl;
        std::cout << "3. Update Contact" << std::endl;
        std::cout << "4. List All Contacts" << std::endl;
        std::cout << "5. Delete Specific Contact" << std::endl;
        std::cout << "6. Delete All Contacts" << std::endl;
        std::cout << "7. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            Contact contact;
            std::cout << "Enter Name: ";
            std::cin.ignore(); // Clear newline from previous input
            std::getline(std::cin, contact.name);
            std::cout << "Enter Phone: ";
            std::cin >> contact.phone;
            std::cout << "Enter Email: ";
            std::cin >> contact.email;
            addressBook.push_back(contact);
            std::cout << "Contact added successfully!" << std::endl;
        } else if (choice == 2) {
            std::string searchName;
            std::cout << "Enter Name to search: ";
            std::cin.ignore(); // Clear newline from previous input
            std::getline(std::cin, searchName);
            bool found = false;
            for (const Contact& contact : addressBook) {
                if (contact.name == searchName) {
                    printContact(contact);
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Contact not found." << std::endl;
            }
        } else if (choice == 3) {
            std::string updateName;
            std::cout << "Enter Name to update: ";
            std::cin.ignore(); // Clear newline from previous input
            std::getline(std::cin, updateName);
            bool updated = false;
            for (Contact& contact : addressBook) {
                if (contact.name == updateName) {
                    std::cout << "Enter new Phone: ";
                    std::cin >> contact.phone;
                    std::cout << "Enter new Email: ";
                    std::cin >> contact.email;
                    std::cout << "Contact updated successfully!" << std::endl;
                    updated = true;
                    break;
                }
            }
            if (!updated) {
                std::cout << "Contact not found." << std::endl;
            }
        } else if (choice == 4) {
            std::cout << "Listing all contacts:" << std::endl;
            for (const Contact& contact : addressBook) {
                printContact(contact);
            }
        } else if (choice == 5) {
            std::string deleteName;
            std::cout << "Enter Name to delete: ";
            std::cin.ignore(); // Clear newline from previous input
            std::getline(std::cin, deleteName);
            bool deleted = false;
            for (auto it = addressBook.begin(); it != addressBook.end(); ++it) {
                if (it->name == deleteName) {
                    addressBook.erase(it);
                    std::cout << "Contact deleted successfully!" << std::endl;
                    deleted = true;
                    break;
                }
            }
            if (!deleted) {
                std::cout << "Contact not found." << std::endl;
            }
        } else if (choice == 6) {
            addressBook.clear();
            std::cout << "All contacts deleted successfully!" << std::endl;
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
