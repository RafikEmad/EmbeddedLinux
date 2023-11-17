#!/bin/bash

case "$1" in
    linux)
        echo "# List contents of a directory"
        echo "# Usage: ls [options] [directory]"
        echo "ls -l"
        echo "# Print the current working directory"
        echo "# Usage: pwd"
        echo "pwd"
        echo "# Change directory"
        echo "# Usage: cd [directory]"
        echo "cd /path/to/directory"
        echo "# Display file content"
        echo "# Usage: cat [file]"
        echo "cat filename.txt"
        ;;
    cpp)
        echo "// to install: apt-get install g++"
        echo "// to compile: g++ source.cpp"
        echo "// to execute: ./a.out"
        echo "int main() {"
        echo "    std::cout << \"hello\" << std::endl;"
        echo "    return 0;"
        echo "}"
        ;;
    python)
        echo "# To install Python:"
        echo "# For Linux: sudo apt-get install python3"
        echo "# For macOS: brew install python3"
        echo "# Welcome to Python!"
        echo "# Run this code using 'python filename.py'"
        echo "print('Hello, World!')"
        ;;
    bash)
        echo "# Print 'Hello, World!' in Bash"
        echo "echo 'Hello, World!'"
esac
