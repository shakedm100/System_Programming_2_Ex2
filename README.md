# Exercise 2: Square Matrix & Operators

## Overview
This project implements SquareMat class which is a square matrix and matrix related operators.

1. **Addition(+) and Subtraction(-) operators**  
   Add or subtract two matrices.

2. **Unary minus(-) operator**  
   Negates all elements of the matrix.

3. **Matrix/Scalar(*) multiplication**  
   Executes multipication between two matrices or a matrix and scalar.

4. **Member(%) multiplication**  
   Multiplies equal indexes between two matrices.

5. **Modulo(%)**  
   Executes modulo logic between a matrix and scalar.

6. **Division(/)**
    Divies all the members of the matrix with a number.

7. **Exponent(^)**
    Raises the matrix to an integer power.

8. **Increase(++) and Decrease(--)**
    Increases or decreases all the members of a matrix by one, implements prefix and postfix implementations.

9. **Transpose(~)**
    Transposes a matrix

10. **Get/Set Index[]**
    Receives a specific index or change it's value.

11. **Equality(==) and Inequality**
    Two matrices are equal if and only if(iff) the sum of their members are equal.

12. **Greater(>)/Lesser(<) than**
    Same as 11.

13. **EqualGreater(>=)/EqualLesser(<=) than**
    Same as 11.

14. **Determinant(!)**
    Calculates the determinant of the matrix.

15. **Operators +=,-=,*=,/=,%=**
    Executes addition, subtraction, multiplication, division and member multiplication/modulo
    Remark: *= and %= also have two usages - one with matrix and one with scalar.

16. **Output(<<)**
    Prints the matrix members using cout

The project is implemented in C++ with g++ compiler.

## Features

- **Square matrix data structure**  
  Implementation of a square matrix with nxn members

- **Operator implementation:**
  Implements all the stated above operators

- **Testing**
  - **Unit Tests:** Written using the Doctest framework.
  - **Memory Leak Checks:** Conducted using Valgrind.

## Installation and Build Instructions

This project uses a Makefile for building. Ensure you have `make` and a C++ compiler (supporting C++11) installed and a g++ compiler.

### Build Targets

- **Main Application:**  
  Compiles the project with `main.cpp` as the entry point.
  ```bash
  make main
  ```
  
- **Test Suite:**  
  Compiles and runs the unit tests (located in `test.cpp`).
  ```bash
  make test
  ```
  
- **Valgrind Check:**  
  Compiles the test target and runs Valgrind to check for memory leaks.
  ```bash
  make valgrind
  ```

- **Clean Build Artifacts:**  
  Removes all generated object files and executables.
  ```bash
  make clean
  ```

## Project Structure

```
.
├── matrix.cpp               # Implements a square matrix & it's operators.
├── matrix.hpp               # Declarations for square matrix & operators.
├── main.cpp                 # Main program entry point.
├── makefile                 # Build configuration and targets.
├── test.cpp                 # Unit tests using Doctest.
└── README.md                # Project documentation.
```

### Detailed Components

1. **matrix.cpp / matrix.hpp:**  
   Implements the square and it's operators that are stated in the overview section

2. **main.cpp:**  
   Provides a basic interface to try the matrices operators on a few predefined matrices.

3. **test.cpp:**  
   Contains unit tests to validate the correctness of the square matrix and it's operators functionality using Doctest.

4. **makefile:**  
   Contains targets to build the main application, run tests, perform Valgrind memory checks, and clean up build artifacts.

## Usage Examples

To compile and run the main application:
```bash
make main
./main
```

To compile and run the unit tests:
```bash
make test
./test
```

To run the tests under Valgrind (for memory leak checking):
```bash
make valgrind
./test
```

To clean up build artifacts:
```bash
make clean
```

## Author

**Shaked Michael**  
Email: shaked1mi@gmail.com