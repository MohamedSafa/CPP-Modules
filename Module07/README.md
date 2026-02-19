*This project has been created as part of the 42 curriculum by msafa.*

# C++ Module 07 - C++ Templates

## Description

This module introduces C++ templates, a core feature that enables writing generic, type-independent code. Through three exercises, the module covers function templates and class templates, progressing from simple template functions to a fully templated container class.

## Exercises

- **ex00 - Start with a few functions:** Implements template functions `swap`, `min`, and `max` that work with any type supporting comparison operators.
- **ex01 - Iter:** Implements a template function `iter` that applies a given function to every element of an array, demonstrating templates with function pointers/functors.
- **ex02 - Array:** Implements a templated `Array` class with dynamic allocation, deep copy semantics, bounds checking, and the Orthodox Canonical Form.

## Instructions

Each exercise has its own directory with a Makefile. To compile:

```bash
cd ex00  # or ex01, ex02
make
./whatever  # or ./iter, ./array (check Makefile for binary name)
```

Requires a C++ compiler with C++98 support.

## Resources

- [C++ Reference](https://en.cppreference.com/) - Official C++ documentation
- [ISO C++ Templates](https://isocpp.org/wiki/faq/templates) - Templates FAQ
- AI (Claude) was used as a tutor for explaining template concepts and for testing/validating outputs.
