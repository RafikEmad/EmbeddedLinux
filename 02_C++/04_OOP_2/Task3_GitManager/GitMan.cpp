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
            std::cout << "6. Push" << std::endl;
            std::cout << "7. Exit" << std::endl;
            std::string gitStatusCommand;
            std::string gitAddCommand;
            std::string gitAddAllCommand;
            std::string gitRemoveCommand;
            std::string gitResetCommand;
            std::string gitCommitCommand;
            std::string gitPushCommand;
            int addResult;
            int removeResult;
            int resetResult;
            int commitResult;
            int pushResult;
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
                    std::cout << "Enter a commit message: ";
                    std::cin.ignore(); // Ignore newline character from previous input
                    std::getline(std::cin, commitMessage_);
                    std::cout << "Performing 'git commit -m \"" << commitMessage_ << "\"'" << std::endl;
                    gitCommitCommand = "cd " + gitDirectoryPath_ + " && git commit -m \"" + commitMessage_ + "\"";
                    commitResult = std::system(gitCommitCommand.c_str()); // Execute 'git commit' command
                    if (commitResult == 0) {
                        std::cout << "Committed changes with message: " << commitMessage_ << std::endl;
                    } else {
                        std::cerr << "Failed to commit changes." << std::endl;
                    }break;
                case 5:
                    std::cout << "Enter the filename to remove: ";
                    std::cin.ignore(); // Ignore newline character from previous input
                    std::getline(std::cin, filename_);
                    std::cout << "Performing 'git reset " << filename_ << "'" << std::endl;
                    gitResetCommand = "cd " + gitDirectoryPath_ + " && git reset " + filename_;
                    resetResult = std::system(gitResetCommand.c_str()); // Execute 'git reset' command
                    if (resetResult == 0) {
                        std::cout << "Unstaged changes for file '" << filename_ << "'." << std::endl;
                    } else {
                        std::cerr << "Failed to unstage changes for file '" << filename_ << "'." << std::endl;
                    }
                    break;
                case 6:
                    std::cout << "Enter your Git username: ";
                    std::cin >> gitUsername_;
                    std::cout << "Enter your Git token: ";
                    std::cin >> gitToken_;
                    std::cout << "Performing 'git push'" << std::endl;
                    // Include the username and token in the git push command
                    //gitPushCommand = "cd " + gitDirectoryPath_ + " && git push --username " + gitUsername_ + " --token " + gitToken_;
                    gitPushCommand = "git push https://" + gitToken_ + "@github.com/" + gitUsername_ + "/" + "EmbeddedLinux" + ".git";
                    pushResult = std::system(gitPushCommand.c_str()); // Execute 'git push' command
                    if (pushResult == 0) {
                        std::cout << "Pushed changes to the remote repository." << std::endl;
                    } else {
                        std::cerr << "Failed to push changes." << std::endl;
                    }
                break;
                case 7:
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
    std::string commitMessage_;
    std::string gitUsername_;
    std::string gitToken_;

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
//       g++ -o GitMan GitMan.cpp
//      ./GitMan file.txt /home/rafik/Desktop/EmbeddedLinux
// 1. Git Status
// 2. Add file
// 3. Add all changes
// 4. Commit
// 5. Remove
// 6. Push
// 7. Exit
// 2
// Enter the filename to add: /home/rafik/Desktop/EmbeddedLinux/02_C++/04_OOP_2/Task3_GitManager/filetoberemoved.txt
// Performing 'git add /home/rafik/Desktop/EmbeddedLinux/02_C++/04_OOP_2/Task3_GitManager/filetoberemoved.txt'
// File '/home/rafik/Desktop/EmbeddedLinux/02_C++/04_OOP_2/Task3_GitManager/filetoberemoved.txt' added to the Git staging area.