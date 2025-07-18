//yaeldorani@gmail.com

Square Matrix Project


This project implements a square matrix class (SquareMat) in C++. It includes functionalities such as matrix multiplication, element access, and more. The project also contains unit tests using the doctest framework to ensure correctness.
Requirements

    C++11 compatible compiler (e.g., clang++ or g++)

    make utility

    Valgrind (optional, for memory leak detection)

Project Structure

    SquareMat.hpp and SquareMat.cpp: Implementation of the SquareMat class.

    main.cpp: Demonstration of SquareMat usage.

    test: Directory containing unit tests.

    Makefile: Build and test automation.

Build and Run Instructions
Compile the Project

To compile the main demonstration program:

    make Main

This will generate an executable named main.
Run the Demonstration

After compiling, run the program with:

    ./main

Run Unit Tests

To compile and run the unit tests:

    make test

This will execute all tests located in the test/ directory.
Check for Memory Leaks

To run the unit tests under Valgrind for memory leak detection:

    make valgrind

Ensure Valgrind is installed on your system before running this command.
Clean Build Files

To remove compiled objects and executables:

    make clean

Notes

    The Makefile is configured to handle compilation, testing, and memory checks.

    Ensure that all dependencies are installed and accessible in your system's PATH.

License

This project is licensed under the MIT License. See the LICENSE file for details.

Feel free to customize this README.md further to suit your project's specific needs or to provide additional information.
