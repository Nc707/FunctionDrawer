# My C++ Project

This project implements a simple expression evaluation framework in C++. It includes a class `Funcion` that allows for the evaluation of mathematical expressions and the generation of points over a specified range.

## Project Structure

```
my-cpp-project
├── src
│   ├── main.cpp          # Contains the main function and the Funcion class
│   └── Expression
│       └── Expression.h  # Declares the Expression base class
├── CMakeLists.txt        # CMake configuration file
└── README.md             # Project documentation
```

## Files Overview

- **src/main.cpp**: This file contains the main function of the application. It defines the class `Funcion`, which inherits from `Expression`, and includes methods for evaluating expressions and generating points based on a given range.

- **src/Expression/Expression.h**: This file declares the `Expression` class, which serves as a base class for various expression types. It includes a pure virtual method `evaluar` that must be implemented by derived classes.

- **CMakeLists.txt**: This file is the configuration file for CMake. It specifies the project name, the required C++ standard, and the source files to be compiled.

## Building the Project

To build the project, follow these steps:

1. Navigate to the project directory:
   ```
   cd my-cpp-project
   ```

2. Create a build directory:
   ```
   mkdir build
   cd build
   ```

3. Run CMake to configure the project:
   ```
   cmake ..
   ```

4. Build the project:
   ```
   make
   ```

## Running the Application

After building the project, you can run the application using the following command:
```
./your_executable_name
```

Replace `your_executable_name` with the actual name of the compiled executable.