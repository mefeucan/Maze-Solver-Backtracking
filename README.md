# Maze Solver & Backtracking (C++)

## Project Overview
This project, developed for the **Data Structures and Algorithms** course, finds a path through a dynamic MxN maze using a **Stack-based Backtracking algorithm**. 
It effectively demonstrates how to solve pathfinding problems using LIFO principles.

## Technical Implementation
*   **Algorithm:** Implemented **Recursive Backtracking** logic to explore paths and backtrack from dead ends.
*   **Data Structure:** Developed a custom **Linked List-based Stack** (LIFO) to manage coordinate history and memory efficiently.
*   **Memory Management:** Dynamic memory is manually managed with pointers and proper destructors to ensure zero **Memory Leaks**.
*   **File I/O:** Maps are dynamically loaded from a text file into a 2D dynamic array for flexible maze configurations.

## Project Architecture
The project is built with professional standards including:
*   Modular structure with separated Header (.hpp) and Source (.cpp) files.
*   Automated build system using a **Makefile**.

## How to Run
1. Ensure you have **MinGW (g++)** and **Make** installed.
2. Open terminal and run the build command:
   ```bash
   make
   ./Labirent.exe
