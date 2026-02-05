*This project has been created as part of the 42 curriculum by msafa.*

# CPP Module 03 - Inheritance

## Description

This project introduces class inheritance in C++ through a game-like class hierarchy. Starting from a base ClapTrap class, derived classes extend and override behavior while reusing existing code.

The project is structured in three exercises of increasing complexity:

- **ex00** - Implements the base **ClapTrap** class with hit points, energy points, attack damage, and methods for attacking, taking damage, and repairing.
- **ex01** - Introduces **ScavTrap**, a class that inherits from ClapTrap with boosted stats, an overridden `attack()` method, and a new `guardGate()` ability.
- **ex02** - Adds **FragTrap**, another ClapTrap-derived class with the highest stats and a unique `highFivesGuys()` ability, expanding the inheritance hierarchy.

### Key Concepts Learned

- **Public inheritance**: `class Derived : public Base` to inherit all public and protected members.
- **Protected access specifier**: allowing derived classes to access base class members while keeping them hidden from outside.
- **Constructor chaining**: calling the parent constructor from the derived class initializer list.
- **Copy semantics in inheritance**: copy constructors and assignment operators that delegate to the parent class.
- **Method overriding**: redefining a base class method in a derived class (ScavTrap overrides `attack()`).
- **Extending functionality**: adding new methods in derived classes (`guardGate()`, `highFivesGuys()`).
- **Self-assignment check**: `if (this != &rhs)` pattern in the copy assignment operator.

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
./claptrap    # ex00
./scavtrap    # ex01
./fragtrap    # ex02
```

### Compilation Flags

All exercises compile with: `-Wall -Wextra -Werror -std=c++98`

## Resources

- [C++ Reference Manual](https://cplusplus.com/reference/)
- [Perplexity AI Search](https://www.perplexity.ai/)

### AI Usage

AI was used as a tutoring tool to deepen understanding of the concepts involved (inheritance, constructor chaining, method overriding, protected access). It was also used to generate rigorous test cases to verify correctness, ensure all edge cases are handled, and confirm the absence of memory leaks.
