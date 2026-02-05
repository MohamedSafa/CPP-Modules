*This project has been created as part of the 42 curriculum by msafa.*

# CPP Module 01 - Memory Allocation, Pointers, References, and File Streams

## Description

This project explores C++ memory management, the distinction between pointers and references, file I/O, and member function pointers. It builds a solid foundation for writing safe, resource-aware C++ code.

The project is structured in six exercises of increasing complexity:

- **ex00** - Creates Zombie objects on the **stack vs heap**, demonstrating `new`/`delete` and object lifetime.
- **ex01** - Allocates a **dynamic array** of Zombies with `new[]`/`delete[]`, introducing array memory management.
- **ex02** - A short program comparing **pointers and references** by printing addresses and values.
- **ex03** - Two Human classes that hold a Weapon as a **reference vs pointer**, showing practical trade-offs between the two.
- **ex04** - A `sed`-like tool that reads a file, performs **string replacement**, and writes to a new file using `ifstream`/`ofstream`.
- **ex05** - Implements a complaint system using **member function pointers** as an array-based dispatch mechanism.

### Key Concepts Learned

- **Stack vs heap allocation**: understanding object lifetime with `new`/`delete` vs local scope.
- **Dynamic arrays**: allocating and freeing arrays with `new[]`/`delete[]`.
- **References vs pointers**: references must be initialized and cannot be null; pointers offer flexibility.
- **References as class members**: must be initialized in the constructor initializer list.
- **File I/O**: reading with `std::ifstream`, writing with `std::ofstream`, and checking `is_open()`.
- **String manipulation**: `find()`, `substr()`, and building a global search-and-replace algorithm.
- **Member function pointers**: `void (Class::*ptr)()` syntax and invocation with `(this->*ptr)()`.
- **Destructor behavior**: observing when destructors are called for stack vs heap objects.

## Instructions

### Compilation

Each exercise is self-contained with its own `Makefile`. To compile:

```bash
cd ex00   # or ex01, ex02, ex03, ex04, ex05
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
./zombie       # ex00, ex01
./brain        # ex02
./violence     # ex03
./sed file s1 s2  # ex04
./harl         # ex05
```

### Compilation Flags

All exercises compile with: `-Wall -Wextra -Werror -std=c++98`

## Resources

- [C++ Reference Manual](https://cplusplus.com/reference/)
- [Perplexity AI Search](https://www.perplexity.ai/)

### AI Usage

AI was used as a tutoring tool to deepen understanding of the concepts involved (memory allocation, references vs pointers, file streams, function pointers). It was also used to generate rigorous test cases to verify correctness, ensure all edge cases are handled, and confirm the absence of memory leaks.
