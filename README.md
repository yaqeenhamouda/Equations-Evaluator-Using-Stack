# Stack-based Expression Validator and Prefix Converter in C

## Overview
This project implements a **stack-based system** in C to perform the following operations:

1. **Validate arithmetic expressions** containing numbers, operators, and brackets `()`, `[]`.
2. **Convert valid infix expressions** to their **prefix (Polish) notation**.
3. Support for **expression reversal**, **operator priority handling**, and **error reporting**.

The project includes:
- A **linked list** to store multiple expressions read from a file.
- Two **stack implementations**:
  - **Stack of characters** for operator/bracket handling.
  - **Stack of integers** (prepared but not fully used in the provided code).
- Utility functions to handle **expression validation**, **prefix conversion**, and **error diagnosis**.

---

## Features
- Reads expressions from a file.
- Checks for syntax correctness, such as:
  - Properly opened and closed brackets.
  - No consecutive operators.
  - No operators at the beginning or end of an expression.
  - Operators placed correctly with respect to brackets.
- Converts valid infix expressions to **prefix notation**.
- Provides detailed reasons for invalid expressions.

---

## Code Structure
### Data Structures:
- `StackChar`: Stack implementation for `char` elements (used in expression parsing).
- `StackInteger`: Stack implementation for `int` elements.
- `LinkedList`: Linked list to store multiple expressions from a file.

### Main Functionalities:
1. **ReadFile()**: Reads expressions line by line from a user-provided file and stores them in a linked list.
2. **IsValid()**: Validates each expression and returns an error code if the expression is invalid.
3. **PrintReason()**: Displays human-readable error messages based on the validation result.
4. **Reverse()**: Reverses an expression and adjusts brackets accordingly.
5. **convertToPrefix()**: Converts a valid infix expression to prefix notation using a stack.

---

## How It Works
1. The user is prompted to enter the file name.
2. The program reads and parses each line (expression) into a linked list.
3. Each expression is validated using the **IsValid()** function.
4. Valid expressions are then **converted to prefix notation** using **convertToPrefix()**.
5. The project outputs either the converted expression or a specific reason why it is invalid.

---

## Files
- `main.c`: Contains all the logic for stack operations, linked list handling, file reading, validation, and conversion to prefix notation.

---

## How to Compile and Run

### Compilation:
```bash
gcc -o expression_converter main.c
