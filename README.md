#C++ Object-Oriented Programming Practice

This repository is a collection of C++ exercises and implementations focused on mastering Object-Oriented Programming (OOP), memory management, and data structures.

The projects progress from basic C-style memory handling to advanced C++ concepts like polymorphism and exception safety.


📂 Repository Structure
    Folder / Project,Key Concepts,Description
    
    dynamic-stack,"malloc, realloc, LIFO",Custom stack implementation with manual dynamic memory resizing.
    
    polynomial-class,"Operator Overloading, Rule of Three","A math library for polynomials supporting +, -, * and indexing."
    
    complex-numbers-lib,"Friend Functions, Math Ops",Implementation of complex number arithmetic and phase/absolute calculations.
    
    dynamic-stack-advanced,"Exception Handling, Deep Copy","Advanced stack with try-catch logic and strict ""Rule of Three"" compliance."
    
    cpp-polymorphic-container,"Inheritance, Virtual Methods",Abstract interfaces and limited-size containers using std::vector.
    
    string-concat-c,"Pointers, C-strings",Basic manual memory allocation and string manipulation.
🛠 Technical Highlights
1. Manual Memory Management        

Implementation of the Rule of Three to ensure deep copying and prevent memory leaks:

    Copy Constructor

    Assignment Operator (operator=)

    Destructor

2. Operator Overloading

Extensive use of operator overloading to create intuitive APIs for mathematical objects (Polynomials and Complex numbers):

    Arithmetic: +, -, *, /

    Stream I/O: operator<<

    Accessors: operator[], operator()

3. Polymorphism & Abstraction

    Use of Abstract Base Classes (interfaces) with pure virtual functions.

    Demonstration of Static Members for global configuration within class hierarchies.

    Proper use of Virtual Destructors to ensure safe object deletion in polymorphic code.

🚀 How to Run

Each project is self-contained. You can compile them using g++ (or any C++11/14/17 compatible compiler).

Example for the Stack project:
Bash

cd dynamic-stack
g++ main.cpp -o stack_test
./stack_test

📝 Learning Objectives

    Understanding the transition from C-style procedural code to C++ OOP.

    Mastering the stack and heap memory allocation.

    Learning how to build robust, reusable classes with proper encapsulation.

Author: [docRonal]
Educational project for practicing C++ core principles.
