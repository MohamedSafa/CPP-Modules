*This project has been created as part of the 42 curriculum by msafa.*

# CPP Module 04 - Subtype Polymorphism, Abstract Classes, and Interfaces

## Description

This project explores polymorphism in C++ through virtual functions, deep copying of composed objects, and abstract classes. It builds an Animal class hierarchy that progressively demonstrates these core OOP concepts.

The project is structured in three exercises of increasing complexity:

- **ex00** - Introduces **virtual functions** and polymorphism: Dog and Cat classes override `makeSound()` through a base Animal pointer. A WrongAnimal/WrongCat pair demonstrates what happens without `virtual`.
- **ex01** - Adds a **Brain** class composed into Dog and Cat, requiring proper **deep copy** semantics so each animal owns an independent copy of its Brain.
- **ex02** - Makes Animal an **abstract class** by declaring `makeSound()` as a pure virtual function (`= 0`), preventing direct instantiation of the base class.

### Key Concepts Learned

- **Virtual functions**: the `virtual` keyword enables dynamic dispatch, calling the correct derived method through a base class pointer.
- **Virtual destructors**: `virtual ~Animal()` ensures derived class destructors are called when deleting through a base pointer.
- **Polymorphism**: a single interface (Animal pointer) that behaves differently depending on the actual object type.
- **Composition**: Dog and Cat own a `Brain*` member, demonstrating the has-a relationship.
- **Deep copy vs shallow copy**: copying pointer members requires allocating new memory and copying the data, not just the pointer.
- **Abstract classes**: classes with at least one pure virtual function (`= 0`) cannot be instantiated directly.
- **Pure virtual functions**: `virtual void makeSound() const = 0` forces derived classes to provide their own implementation.
- **Non-virtual pitfall**: the WrongAnimal example shows that without `virtual`, the base class method is called regardless of the actual object type.

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
./animal
```

### Compilation Flags

All exercises compile with: `-Wall -Wextra -Werror -std=c++98`

## Resources

- [C++ Reference Manual](https://cplusplus.com/reference/)
- [Perplexity AI Search](https://www.perplexity.ai/)

### AI Usage

AI was used as a tutoring tool to deepen understanding of the concepts involved (polymorphism, virtual functions, abstract classes, deep copy). It was also used to generate rigorous test cases to verify correctness, ensure all edge cases are handled, and confirm the absence of memory leaks.
