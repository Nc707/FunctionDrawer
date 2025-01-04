# Function Drawer C++ Project

This project implements a simple expression evaluation framework in C++. It includes a class `Function` that allows for the evaluation of mathematical expressions and the generation of points over a specified range.

## Project Structure

```
FunctionDrawer
├── CMakeLists.txt
├── README.md --> You are here
├── src
│   ├── expression.h
│   ├── function.h
│   ├── main.cpp
│   ├── Operations
│   │   ├── binaryOperation.h
│   │   ├── binaryOperations
│   │   │   ├── addition.cpp
│   │   │   ├── division.cpp
│   │   │   ├── exponent.cpp
│   │   │   ├── logaritm.cpp
│   │   │   ├── multiplication.cpp
│   │   │   ├── substraction.cpp
│   │   ├── operations.h
│   │   ├── unaryOperation.h
│   │   ├── unaryOperations
│   │   │   ├── negation.cpp
│   │   │   ├── trigonometricOperations
│   │   │   │   ├── cosine.cpp
│   │   │   │   ├── sine.cpp
│   │   │   │   ├── tangent.cpp
│   ├── var.h
│   ├── Variables
│   │   ├── all-variables.h
│   │   ├── integerConstant.h
│   │   ├── integerIndependentVariable.h
│   │   ├── realConstant.h
│   │   ├── realIndependentVariable.h
│   │   ├── variable.h
```

## Files Overview

- **src/main.cpp**: This file is the playground area. It is currently used to test out the Project

- **src/expression.h**: This file declares the `Expression` class, which serves as a base class for various expression types. It includes a pure virtual method `evaluate` that must be implemented by derived classes.

- **src/function.h**: This file declares the `Function` class, which takes an `Expression` and generates points by evaluating the expression over a range.

- **src/Operations**: This directory contains the implementation of various operations such as addition, subtraction, multiplication, and division. Each operation is implemented as a class that inherits from `BinaryOperation` or `UnaryOperation`.

- **src/Variables**: This directory contains the implementation of various variable types such as `RealIndependentVariable` and `RealConstant`. These classes inherit from `Variable`, which in turn inherits from `Expression`.

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