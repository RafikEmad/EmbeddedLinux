#include <iostream>
#include <string>
#include <cstdlib> // for std::system

class GitManager {
public:
    GitManager(const std::string& filename, const std::string& gitDirectoryPath) : filename_(filename), gitDirectoryPath_(gitDirectoryPath) {
        // Check if the specified directory is in a Git repository
        if (!isInGitRepository(gitDirectoryPath_)) {
            std::cout<<gitDirectoryPath<<std::endl;
            std::cerr << "Not in a Git repository. Please specify a valid Git repository directory." << std::endl;
            exit(1);
        }
    }

    void run() {
        while (true) 
        {
            std::cout << "What do you want to do with '" << filename_ << "'?" << std::endl;
            std::cout << "1. Git Status" << std::endl;
            std::cout << "2. Add file" << std::endl;
            std::cout << "3. Add all changes" << std::endl;
            std::cout << "4. Commit" << std::endl;
            std::cout << "5. Remove" << std::endl;
            std::cout << "6. Exit" << std::endl;
            std::string gitStatusCommand;
            std::string gitAddCommand;
            std::string gitAddAllCommand;
            int addResult;
            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Performing 'git status'" << std::endl;
                    gitStatusCommand = "cd " + gitDirectoryPath_ + " && git status";
                    std::system(gitStatusCommand.c_str()); // Execute 'git status' in the specified directory
                    break;
                case 2:
                    std::cout << "Enter the filename to add: ";
                    std::cin.ignore(); // Ignore newline character from previous input
                    std::getline(std::cin, filename_);
                    std::cout << "Performing 'git add " << filename_ << "'" << std::endl;
                    gitAddCommand = "cd " + gitDirectoryPath_ + " && git add " + filename_;
                    addResult = std::system(gitAddCommand.c_str()); // Execute 'git add' command
                    if (addResult == 0) {
                        std::cout << "File '" << filename_ << "' added to the Git staging area." << std::endl;
                    } else {
                        std::cerr << "Failed to add file '" << filename_ << "' to the Git staging area." << std::endl;
                    }
                    break;
                case 3:
                    std::cout << "Performing 'git add --all'" << std::endl;
                    gitAddAllCommand = "cd " + gitDirectoryPath_ + " && git add --all";
                    addResult = std::system(gitAddAllCommand.c_str()); // Execute 'git add --all' command
                    if (addResult == 0) {
                        std::cout << "Added all changes to the Git staging area." << std::endl;
                    } else {
                        std::cerr << "Failed to add all changes to the Git staging area." << std::endl;
                    }
                    break;    
                case 4:
                    std::cout << "Performing 'git commit -m \"Committing " << filename_ << "\"'" << std::endl;
                    // Implement 'git commit' logic here
                    break;
                case 5:
                    std::cout << "Performing 'git rm " << filename_ << "'" << std::endl;
                    // Implement 'git rm' logic here
                    break;
                case 6:
                    std::cout << "Exiting the program." << std::endl;
                    return; // Exit the program
                default:
                    std::cout << "Invalid choice." << std::endl;
            }
        }
    }
private:
    std::string filename_;
    std::string gitDirectoryPath_;

    bool isInGitRepository(const std::string& path) {
        // Use '[ -d .git ]' command to check for the existence of .git directory
        std::string command = "[ -d " + path + "/.git ]";
        int result = std::system(command.c_str());

        // Check if the '[ -d .git ]' command returns 0 (indicating success)
        return result == 0;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <filename> <git_directory_path>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string gitDirectoryPath = argv[2];
    GitManager gitManager(filename, gitDirectoryPath);
    gitManager.run();

    return 0;
}
