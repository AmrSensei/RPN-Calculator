# RPN Calculator

A command-line Reverse Polish Notation (RPN) calculator written in C++.

The calculator evaluates mathematical expressions using a stack, supports basic arithmetic operations and exponentiation, and includes input validation, error handling, and an interactive menu.

## Features

- **RPN expression evaluation** using a stack.
- **Arithmetic operations:** addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`).
- **Exponentiation** using (`^`).
- **Input validation** to detect malformed numbers and invalid expressions.
- **Error handling** for division by zero, insufficient operands, invalid results, and other input errors.
- **Stack inspection** to view the current stack contents.
- **Operation counter** to track operations across successfully evaluated expressions.
- **Interactive command-line interface** for evaluating expressions, clearing the calculator, viewing the stack, and exiting the program.

## What Is RPN?

Reverse Polish Notation is a mathematical notation in which operators follow their operands, eliminating the need for parentheses or operator precedence rules.

For example, the conventional expression:

```text
(3 + 4) * 2
```

is written in RPN as:

```text
3 4 + 2 *
```

The calculator evaluates the expression from left to right using a stack:

1. Push `3` onto the stack.
2. Push `4` onto the stack.
3. Apply `+` to the top two operands and push the result (`7`).
4. Push `2` onto the stack.
5. Apply `*` and push the final result (`14`).

## Supported Operators

| Operator | Operation      | Example        |
| -------- | -------------- | -------------- |
| `+`      | Addition       | `3 4 +` → `7`  |
| `-`      | Subtraction    | `10 3 -` → `7` |
| `*`      | Multiplication | `3 4 *` → `12` |
| `/`      | Division       | `10 2 /` → `5` |
| `^`      | Exponentiation | `2 3 ^` → `8`  |

**Important:** The second operand is popped first, so operand order matters for subtraction and division.

## Getting Started

You can either download the source code directly or clone the repository.

### Option 1: Download the ZIP

1. Open this repository on GitHub.
2. Click the green **Code** button.
3. Select **Download ZIP**.
4. Extract the downloaded archive.
5. Open a terminal in the extracted project folder and compile the source files.

### Option 2: Clone the Repository

```bash
git clone https://github.com/AmrSensei/RPN-Calculator.git
cd RPN-Calculator
```

### Compile

Make sure you have a C++17-compatible compiler installed, such as GCC.

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp rpn.cpp ui.cpp -o rpn
```

Run the resulting executable:

**Windows (MinGW):**

```powershell
.\rpn.exe
```

**Linux:**

```bash
./rpn
```

## Usage

Run the program and choose an option from the interactive menu.

```text
Please choose an option :
1. Enter an Expression to evaluate.
2. Clear the Calculator.
3. Print the Stack
4. Quit The Program
```

### Example

To evaluate:

```text
5 1 2 + 4 * + 3 -
```

Enter the expression when prompted.

Expected result:

```text
The result is = 14
```

This corresponds to:

\[
5 + (1 + 2) \times 4 - 3 = 14
\]

### Menu Options

1. **Enter an expression:** Evaluate an RPN expression.
2. **Clear the calculator:** Clear the current stack and reset the operation counter after confirmation.
3. **Print the stack:** Display the current stack contents.
4. **Quit:** Exit the program after confirmation.

## Error Handling

The calculator checks for several invalid situations, including:

- Expressions containing too few operands for an operator.
- Expressions that leave extra operands on the stack.
- Division by zero.
- Malformed numeric input.
- Numbers outside the supported parsing range.
- Results that are not finite, such as infinity or NaN.

## Project Structure

```text
.
├── main.cpp    # Program entry point
├── rpn.h       # RPN class declaration
├── rpn.cpp     # Expression evaluation and calculator logic
├── ui.h        # User interface declaration
├── ui.cpp      # Interactive menu and input/output handling
└── README.md   # Project documentation
```

## Concepts Practiced

This project was an opportunity to practice:

- Classes, member functions, and encapsulation.
- The Standard Library's `std::stack`.
- Function declarations and definitions across header and source files.
- `const` member functions.
- Exception handling with `try`, `throw`, and `catch`.
- Numeric parsing with `std::stod`.
- Input validation and floating-point checks.
- Separating application logic from the user interface.
