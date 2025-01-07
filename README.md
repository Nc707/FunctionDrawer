# Function Drawer C++ Project

This project implements a flexible and extensible expression evaluation framework in C++. It includes classes for defining and evaluating mathematical expressions, as well as generating points based on these expressions.

The main components of the project include:
- **Expressions**: Classes for representing and evaluating mathematical expressions.
- **Operations**: Strategies for performing arithmetic and trigonometric operations.
- **Variables**: Classes for representing constants and independent variables.
- **Factories**: Factories for creating expressions and strategies.
- **Point Generators**: Classes for generating points in 2D and 3D spaces based on expressions.

The project is designed to be easily extendable, allowing for the addition of new types of expressions, operations, and point generators with minimal changes to the existing codebase.

## Project Structure

```
FunctionDrawer
├── CMakeLists.txt
├── README.md --> You are here
├── src/
│   ├── Expressions/
│   │   ├── all_expressions.h
│   │   ├── expression.h
│   │   ├── Operations/
│   │   │   ├── all_operations.h
│   │   |   ├── operation.h
|   |   |   ├── unaryOperation.h
│   │   │   ├── binaryOperation.h
│   │   │   ├── Strategies/
|   |   |   |   ├── operationStrategy.h
│   │   │   │   ├── binaryOperations/
│   │   │   │   │   ├── binaryStrategies...
│   │   │   │   ├── unaryOperations/
│   │   │   │   │   ├── unaryStrategies...
│   │   ├── Variables/
│   │   │   ├── all_variables.h
│   │   │   ├── variable.h
│   │   │   ├── Constants/
│   │   │   │   ├── constant.h
│   │   │   ├── IndependentVariables/
│   │   │   │   ├── independentVariable.h
│   ├── Factories/
│   │   ├── abstractExpressionsFactory.h
│   │   ├── basicFactory.h
│   │   ├── realExpressionFactory.cpp
│   │   ├── realExpressionFactory.h
│   ├── PointsGenerators/
│   │   ├── 2DGenerators/
│   │   │   ├── basic2DGenerator.h
│   │   ├── 3DGenerators/
│   │   ├── axisData.h
│   │   ├── Point2DGenerator.h
│   │   ├── Point3DGenerator.h
│   ├── main.cpp
│   ├── var.h
```

## Files Overview

- **src/main.cpp**: This file contains the main function of the application. It sets up the expression and generates points based on a given range.

- **src/Expressions/expression.h**: This file declares the `Expression` class, which serves as a base class for various expression types. It includes a pure virtual method `evaluate` that must be implemented by derived classes.

- **src/Expressions/Operations**: This directory contains the implementation of various operations such as addition, subtraction, multiplication, and division. Each operation is implemented as a class that inherits from `BinaryOperation` or `UnaryOperation`.

- **src/Expressions/Variables**: This directory contains the implementation of various variable types such as `IndependentVariable` and `Constant`. These classes inherit from `Variable`, which in turn inherits from `Expression`.

- **src/Factories**: This directory contains the implementation of factories for creating expressions and strategies. It includes the abstract factory `AbstractExpressionsFactory`, the basic factory `BasicFactory`, and the concrete factory `RealExpressionFactory`.

- **src/PointsGenerators**: This directory contains the implementation of point generators for generating points in 2D and 3D spaces. It includes the `Basic2DGenerator` and the `Basic3DGenerator`.

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