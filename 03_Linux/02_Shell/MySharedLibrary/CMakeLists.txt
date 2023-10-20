cmake_minimum_required(VERSION 3.0)
project(mysharedlib)

# Source files for the library
set(SOURCES
    calc.cpp
    )

# Header files for the library
set(HEADERS
    calc.hpp
    )

# Create the shared library
add_library(mysharedlib SHARED ${SOURCES} ${HEADERS})

# Set library version and soversion (optional)
set_target_properties(mysharedlib PROPERTIES
    VERSION 1.0
    SOVERSION 1
    )

# Install the library and header files
install(TARGETS mysharedlib
    LIBRARY DESTINATION /usr/local/lib
    )

install(FILES ${HEADERS} DESTINATION /usr/local/include)
