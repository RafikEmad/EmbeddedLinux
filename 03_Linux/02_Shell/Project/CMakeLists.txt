cmake_minimum_required(VERSION 3.0)
project(myapp)

# Source file for the main program
set(SOURCES
    main.cpp
    )

# Create the executable and link it with your shared library
add_executable(myapp ${SOURCES})
target_link_libraries(myapp mysharedlib)

# Install the executable (optional)
install(TARGETS myapp DESTINATION /usr/local/bin)
