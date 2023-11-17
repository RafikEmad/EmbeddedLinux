#!/bin/bash

# Get project name from user input
echo "Enter project name:"
read project_name

# Create project directory
mkdir "$project_name"
cd "$project_name" || exit

# Create directories
mkdir src include bin

# Create Makefile
cat <<EOT >> Makefile
CC = gcc
CFLAGS = -Wall -I./include

SRCDIR = src
INCDIR = include
BINDIR = bin

SRC = \$(wildcard \$(SRCDIR)/*.c)
OBJ = \$(SRC:\$(SRCDIR)/%.c=\$(BINDIR)/%.o)

TARGET = myprogram

\$(BINDIR)/\$(TARGET): \$(OBJ)
	\$(CC) \$(CFLAGS) -o \$@ \$^

\$(BINDIR)/%.o: \$(SRCDIR)/%.c
	\$(CC) \$(CFLAGS) -c -o \$@ \$<

.PHONY: clean
clean:
	rm -rf \$(BINDIR)/*.o \$(BINDIR)/\$(TARGET)
EOT

# Create sample source file
cat <<EOT >> src/main.c
#include <stdio.h>

int main() {
    printf("Hello, $project_name!\n");
    return 0;
}
EOT

echo "Project $project_name created successfully!"
