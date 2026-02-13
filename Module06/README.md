*This project has been created as part of the 42 curriculum by msafa.*

## Description

Module 06 explores C++ type casting mechanisms. The module covers three of the four C++ cast operators (`static_cast`, `dynamic_cast`, `reinterpret_cast`) through three exercises that each focus on a different casting scenario.

### ex00 - Scalar Converter

A non-instantiable utility class `ScalarConverter` with a single static method `convert` that takes a string representation of a C++ literal (char, int, float, double) and displays its conversion to all four scalar types. The class detects the input type, parses it, and performs safe conversions using `static_cast`, handling edge cases like overflow, non-displayable characters, and special IEEE 754 values (nan, inf).

### ex01 - Serializer

A non-instantiable utility class `Serializer` with two static methods: `serialize` takes a `Data*` pointer and converts it to an unsigned integer type (`uintptr_t`) using `reinterpret_cast`, and `deserialize` takes a `uintptr_t` and converts it back to a `Data*` pointer using `reinterpret_cast`. This demonstrates raw memory reinterpretation -- the pointer value is stored as an integer and restored back, preserving the original address.

### ex02 - Identify Real Type

A `Base` class with a public virtual destructor and three empty derived classes `A`, `B`, `C`. A `generate` function randomly creates one of the three types, and two `identify` overloads determine the actual type at runtime using `dynamic_cast`. The pointer version checks for NULL on failed casts, while the reference version catches `std::bad_cast` exceptions on failure. The `typeinfo` header is forbidden, forcing the use of `dynamic_cast` for type identification.

## Instructions

Each exercise is in its own directory with a Makefile. To compile and run:

```
cd ex00 && make && ./convert "42.0f"
cd ex01 && make && ./serialize
cd ex02 && make && ./identify
```

`make clean` removes object files, `make fclean` removes object files and the binary, `make re` rebuilds from scratch.

## Resources

- [C++ Reference Manual](https://cplusplus.com/reference/)
- AI was used as a tutor for understanding casting concepts, as a research tool for C++ type casting behavior and edge cases, and as a tester to verify outputs.