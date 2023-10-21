
- `MySharedLibrary` contains the source code for the shared library.
- `Project` contains the source code for the application that links to the shared library.

## Building and Running
Note: After cloning the project, delete the whole build folder inside both directories: `MySharedLibrary` and `Project` and proceed with the following steps.

To build and run the project, follow these steps:

1. **Build the Shared Library:**

   - Navigate to the `MySharedLibrary` directory.
   - Run the following commands:
     ```bash
     mkdir build
     cd build
     cmake ..
     make
     sudo make install
     ```

2. **Build the Application:**

   - Navigate to the `Project` directory.
   - Run the following commands:
     ```bash
     mkdir build
     cd build
     cmake ..
     make
     ```

3. **Run the Application:**

   - You can now run the application from the `Project/build` directory:
     ```bash
     ./myapp
     ```

   The application should dynamically link to the shared library.
   - Run the following command and you should find libmysharedlib.so between the shared libraries:
     ```bash
     ldd myapp
     ```

## CMake Configuration

- The CMake configurations for both the shared library and the application are provided in the `CMakeLists.txt` files in their respective directories. These configurations set up the build process and ensure dynamic linking to the shared library.

## Troubleshooting

- If you encounter issues related to linking, ensure that the library is correctly installed and in a location where the dynamic linker can find it.