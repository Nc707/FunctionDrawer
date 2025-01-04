# Function Drawer C++ Project

This project implements a simple expression evaluation framework in C++. It includes a class `Function` that allows for the evaluation of mathematical expressions and the generation of points over a specified range.

## Project Structure

```
FunctionDrawer
├── src
│   ├── main.cpp          # Contains the main function
│   ├── Expression.h      # Declares the Expression base class
│   ├── function.h        # Declares the Function class
│   ├── Operations        # Contains operation classes
│   │   ├── addition.cpp
│   │   ├── binaryOperation.h
│   │   ├── division.cpp
│   │   ├── exponent.cpp
│   │   ├── multiplication.cpp
│   │   ├── operations.h
│   │   └── substraction.cpp
│   └── Variables         # Contains variable classes
│       ├── all-variables.h
│       ├── constant.h
│       ├── independentVariable.cpp
│       ├── independentVariable.h
│       └── variable.h
├── CMakeLists.txt        # CMake configuration file
└── README.md             # Project documentation
```

## Files Overview

- **src/main.cpp**: This file contains the main function of the application. It sets up the expression and generates points based on a given range.

- **src/Expression.h**: This file declares the `Expression` class, which serves as a base class for various expression types. It includes a pure virtual method `evaluate` that must be implemented by derived classes.

- **src/function.h**: This file declares the `Function` class, which takes an `Expression` and generates points by evaluating the expression over a range.

- **src/Operations**: This directory contains the implementation of various operations such as addition, subtraction, multiplication, and division. Each operation is implemented as a class that inherits from `BinaryOperation`.

- **src/Variables**: This directory contains the implementation of various variable types such as `IndependentVariable` and `Constant`. These classes inherit from `Variable`, which in turn inherits from `Expression`.

- **CMakeLists.txt**: This file is the configuration file for CMake. It specifies the project name, the required C++ standard, and the source files to be compiled.

## Building the Project

To build the project, follow these steps:

1. Navigate to the project directory:
   ```
   cd FunctionDrawer
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
./FunctionDrawer
```