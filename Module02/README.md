*This project has been created as part of the 42 curriculum by msafa.*

# CPP Module 02 - Ad-hoc Polymorphism, Operator Overloading, and Fixed-Point Numbers

## Description

This project is a progressive implementation of a **Fixed-Point Number** class in C++98. Fixed-point arithmetic provides a middle ground between integer and floating-point representations, offering predictable precision without the rounding issues inherent to floating-point numbers.

The project is structured in three exercises of increasing complexity:

- **ex00** - Introduces the **Orthodox Canonical Form** (OCF): default constructor, copy constructor, copy assignment operator, and destructor.
- **ex01** - Adds **type conversion** capabilities: constructing from `int` and `float`, converting back via `toInt()` and `toFloat()`, and overloading the `<<` stream insertion operator.
- **ex02** - Implements full **operator overloading**: six comparison operators, four arithmetic operators, pre/post increment/decrement, and static `min`/`max` functions.

### Fixed-Point Representation

The class uses 8 fractional bits, meaning values are internally stored as integers scaled by 256. For example, the value `42.5` is stored as `10880` (`42.5 * 256`). Arithmetic operations account for this scaling to maintain correctness.

## Instructions

### Compilation

Each exercise is self-contained with its own `Makefile`. To compile:

```bash
cd ex00   # or ex01, ex02
make
```

Available Makefile targets:

| Target    | Description                    |
|-----------|--------------------------------|
| `make`    | Compile the program            |
| `make clean`  | Remove object files        |
| `make fclean` | Remove object files and binary |
| `make re`     | Full recompile             |

### Execution

After compilation, run the binary:

```bash
./fixed
```

### Compilation Flags

All exercises compile with: `-Wall -Wextra -Werror -std=c++98`

## Resources

- [C++ Reference Manual](https://cplusplus.com/reference/)
- [Perplexity AI Search](https://www.perplexity.ai/)

### AI Usage

AI was used as a tutoring tool to deepen understanding of the concepts involved (fixed-point arithmetic, operator overloading, Orthodox Canonical Form). It was also used to generate rigorous test cases to verify correctness, ensure all edge cases are handled, and confirm the absence of memory leaks.
