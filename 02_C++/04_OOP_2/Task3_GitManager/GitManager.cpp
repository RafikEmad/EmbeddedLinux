#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

class GitManager {
public:
    GitManager(const std::string& repoPath) : repoPath_(repoPath) 
    {
        // Constructor logic, if needed
    }


    bool add(const std::string& relativeFilePath) {
        // Check if the specified file exists in the working directory
        std::string absoluteFilePath = relativeFilePath;

        // Check if the specified file exists
        struct stat fileInfo;
        if (stat(absoluteFilePath.c_str(), &fileInfo) != 0) {
            std::cerr << "File not found: " << absoluteFilePath << std::endl;
            return false;
        }
        
        // Create the .git/staging directory if it doesn't exist
        std::string stagingDir = repoPath_ + "/.git/staging/";
        mkdir(stagingDir.c_str(), 0777);

        // Copy the file to the staging area
        std::string stagingPath = stagingDir + relativeFilePath;
        if (std::ifstream(absoluteFilePath)) {
            std::ifstream src(absoluteFilePath, std::ios::binary);
            std::ofstream dest(stagingPath, std::ios::binary);

            dest << src.rdbuf();

            std::cout << "Added file: " << relativeFilePath << " to the staging area." << std::endl;
            return true;
        }
        return false;
    }

    bool commit(const std::string& message) {
        // Implement the 'commit' functionality here.
        std::cout << "Committed changes with message: " << message << std::endl;
        return true;
    }

    bool remove(const std::string& fileName) {
        // Implement the 'remove' functionality here.
        std::cout << "Removed file: " << fileName << std::endl;
        return true;
    }
    private:
    std::string repoPath_;
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <action> <file>" << std::endl;
        return 1;
    }

    std::string action = argv[1];
    std::string relativeFilePath = argv[2];

    GitManager git("/Desktop/EmbeddedLinux");

    if (action == "add") {
        git.add(relativeFilePath);
    } else if (action == "commit") {
        std::cout << "Enter commit message: ";
        std::string message;
        std::getline(std::cin, message);
        git.commit(message);
    } else if (action == "remove") {
        git.remove(relativeFilePath);
    } else {
        std::cerr << "Invalid action: " << action << std::endl;
        return 1;
    }

    return 0;
}
