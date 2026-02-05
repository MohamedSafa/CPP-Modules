*This project has been created as part of the 42 curriculum by msafa.*

# CPP Module 00 - Namespaces, Classes, and Member Functions

## Description

This project introduces the fundamentals of C++ programming, moving from basic syntax and I/O to object-oriented design with classes, encapsulation, and formatted output.

The project is structured in two exercises of increasing complexity:

- **ex00** - A simple command-line utility that converts input text to **uppercase**, introducing `argc`/`argv`, `std::cout`, and `std::toupper`.
- **ex01** - An interactive **phonebook** application that stores up to 8 contacts in a circular buffer, demonstrating class design, encapsulation with getters/setters, `std::getline`, and formatted table output with `std::setw`.

### Key Concepts Learned

- **Namespaces and standard I/O**: using `std::cout`, `std::endl`, and the `<iostream>` header.
- **Classes and encapsulation**: defining classes with private member variables and public methods.
- **Constructors**: initializing object state upon creation.
- **Getters and setters**: controlled access to private data.
- **String handling**: `std::string`, `std::getline()`, `substr()`, `length()`.
- **I/O formatting**: `std::setw()` and `<iomanip>` for aligned table output.
- **Static casting**: `static_cast<char>()` for type conversion.
- **Command-line arguments**: processing `argc` and `argv`.

## Instructions

### Compilation

Each exercise is self-contained with its own `Makefile`. To compile:

```bash
cd ex00   # or ex01
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
./megaphone "hello world"   # ex00
./phonebook                 # ex01
```

### Compilation Flags

All exercises compile with: `-Wall -Wextra -Werror -std=c++98`

## Resources

- [C++ Reference Manual](https://cplusplus.com/reference/)
- [Perplexity AI Search](https://www.perplexity.ai/)

### AI Usage

AI was used as a tutoring tool to deepen understanding of the concepts involved (classes, encapsulation, I/O formatting). It was also used to generate rigorous test cases to verify correctness, ensure all edge cases are handled, and confirm the absence of memory leaks.
