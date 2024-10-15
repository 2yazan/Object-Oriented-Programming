# Object-Oriented Programming - Labs

This repository contains my labs and assignments for the **Object-Oriented Programming** (OOP) course. Each lab focuses on different OOP concepts, such as file handling, structures, classes, inheritance, threads, templates, and more.

---

## Lab 1: Files and Introduction to QT Development Environment

1. **Task 1**:  
   A text file contains a sequence of integers. The task is to create a typed file containing only the unique numbers from the original text file.
   
2. **Task 2**:  
   Given a file with a number of components that is a multiple of four. The file consists of non-zero integers, and the number of positive components equals the number of negative ones. Transform the file such that two positive numbers alternate with two negative numbers.

3. **Task 3**:  
   Form "Properties: Internet", tabs "Content" and "Advanced" (control panel).

---

## Lab 2: Modular Programming and Interfaces

**Task**:  
Create a program for managing a home film library. The program should allow adding, updating, and displaying movies with relevant information.

---

## Lab 3: Object Decomposition

1. **Task 1**:  
   Develop a program for plotting graphs of mathematical functions.
   
2. **Task 2**:  
   Develop a program to simulate the operation of a gas station.

---

## Lab 4: Classes

Create a class to handle a one-dimensional array of integers with the following features:

- **Fields**:
  - `int *ptr;` (Pointer to the array)
  - `int n;` (Size of the array)

- **Constructor**:  
   A constructor to create an array of size `n`.

- **Methods**:
  - Input array elements from the keyboard.
  - Output array elements to the screen.
  - Sort array elements in ascending order.

- **Overloaded Operators**:
  - Subtraction combined with assignment.
  - Logical negation (NOT).

---

## Lab 5: Class Relationships and Inheritance

1. **Abstract Class**:  
   Create an abstract class `Figure` with methods for calculating the area, perimeter, and displaying information about the figure.

2. **Derived Classes**:  
   Create the following classes derived from `Figure`:
   - Rectangle
   - Circle
   - Triangle
   
   Each class should have its own methods for calculating the area and perimeter.

3. **Array of Figures**:  
   Create an array of `n` figures and display complete information about each figure.

---

## Lab 6: Threads in C++

Create a multithreaded program where:
1. One thread removes spaces in a string and inserts them at a random location.
2. Another thread performs a cyclic shift of the text.
   
Perform synchronous output at each iteration and demonstrate the program in both synchronous and asynchronous modes.

---

## Lab 7: Exception Handling in C++

1. Develop an abstract class for solving equations.
2. Implement a class for solving trigonometric equations (derived from the abstract class), and provide exception handling for issues related to the domain of trigonometric functions.

---

## Lab 8: Class Templates in C++

1. Implement a class template `Dec` through templates.
2. Provide the necessary methods for working with the specified data structure.
3. Handle exceptional situations that may arise during the program's execution.

---

## Lab 9: Using the Standard Template Library (STL)

1. Develop a program to convert a mathematical expression into reverse Polish notation using a stack.
2. Implement arithmetic operations (addition, subtraction, etc.) on the stack.

---

## Assignment: Football Simulation

1. Develop a program that simulates a football (soccer) game.
2. The program should allow the management of players from different teams, simulate matches, and track results across various tournaments.
3. Each team has properties such as morale, attacking skills, and defending skills that affect match outcomes.
4. Each player has attributes like speed, shooting accuracy, and stamina, influencing their behavior in a match.
