*This project has been created as part of the 42 curriculum by msafa.*

# C++ Module 08 — Templated Containers, Iterators & Algorithms

---

## Description

This module explores advanced C++ template programming with a focus on STL containers, iterators, and algorithms. The goal is to understand how to write generic, reusable code that works seamlessly with the Standard Template Library, and to learn how to extend STL components through inheritance and custom iterator interfaces.

The module is composed of three exercises, each building on the previous in terms of complexity — from a simple templated function, to a container class with bulk insertion, to full iterator-enabled stack inheritance.

All exercises are compiled with the **C++98 standard** and strict flags: `-Wall -Wextra -Werror`.

---

## Instructions

### Requirements

- A C++98-compliant compiler (e.g., `g++`)
- `make`

### Compilation & Execution

Each exercise lives in its own directory and has its own `Makefile`.

```bash
# Exercise 00
cd ex00 && make && ./easyfind

# Exercise 01
cd ex01 && make && ./span

# Exercise 02
cd ex02 && make && ./mutantstack
```

To clean build artifacts:

```bash
make clean   # removes object files
make fclean  # removes object files and binary
make re      # fclean + recompile
```

---

## Exercises

### ex00 — easyfind

A templated function that searches for the first occurrence of an integer value inside any STL container (vector, list, deque, etc.) and returns an iterator to it. Throws `std::runtime_error` if the value is not found.

**Key concepts used:**
- `template <typename T>` — generic function that works with any container type
- `std::find()` — STL algorithm that returns an iterator to the first match
- Iterator interface — using `container.begin()` / `container.end()` to traverse generically
- `typename T::iterator` — dependent type name inside a template; `typename` tells the compiler this is a type, not a value

---

### ex01 — Span

A `Span` class that holds up to `N` integers and provides two operations:
- `shortestSpan()` — minimum difference between any two stored values
- `longestSpan()` — difference between the largest and smallest values

Also supports bulk insertion via a templated `addRange(begin, end)` method.

**Key concepts used:**
- Template member function (`addRange`) inside a non-template class — allows the method to accept iterators from any container
- `std::sort()` — used to sort a copy of the internal vector before scanning adjacent pairs for the shortest span
- `std::min_element()` / `std::max_element()` — STL algorithms for finding extremes efficiently
- Exception handling — throws when container is full or fewer than 2 elements exist

---

### ex02 — MutantStack

A template class that publicly inherits from `std::stack<T>` and adds full iterator support — forward, reverse, const, and const-reverse — by exposing the underlying protected container `this->c`.

**Key concepts used:**

| Concept | Role in MutantStack |
|---|---|
| `template <typename T>` | Makes `MutantStack` generic over element type |
| Class template inheritance | `class MutantStack : public std::stack<T>` — inherits all stack behavior |
| `typedef` | Creates readable aliases for the iterator types (e.g., `typedef typename ... iterator`) |
| `typename` (in typedef) | Required to tell the compiler that `container_type::iterator` is a type, not a member or value — mandatory when accessing nested types in dependent contexts |
| `this->c` | Accesses the protected underlying container of `std::stack` (a `std::deque<T>` by default) to delegate iterator calls |
| `container_type` | The nested type inside `std::stack` that refers to the actual underlying container |
| Forward iterators (`begin`/`end`) | Allow range-based traversal of the stack from bottom to top |
| Reverse iterators (`rbegin`/`rend`) | Allow traversal from top to bottom |
| Const iterators | Allow read-only iteration on `const MutantStack` instances |
| Copy constructor & assignment | Ensure correct copying of the full stack state |

**Why `typename` in typedefs?**
When a type is dependent on a template parameter (e.g., `std::stack<T>::container_type::iterator`), the compiler cannot know at parsing time whether `iterator` is a type or a static member. The `typename` keyword explicitly disambiguates it as a type, which is required by the C++ standard.

**Why `typedef`?**
`typedef` is the C++98 way to create type aliases. It names a complex type (like a nested iterator type) so it can be used simply as `iterator`, `const_iterator`, etc. throughout the class.

**Why inherit from `std::stack` instead of wrapping it?**
Inheritance gives `MutantStack` all of `std::stack`'s interface for free (`push`, `pop`, `top`, `size`, `empty`) while allowing extension with iterators. Wrapping would require manually forwarding every method. The trade-off is that inheriting from non-virtual STL containers carries risks (no virtual destructor), but for this controlled use case it is appropriate.

---

## Resources

- [cppreference — std::stack](https://en.cppreference.com/w/cpp/container/stack)
- [cppreference — std::find](https://en.cppreference.com/w/cpp/algorithm/find)
- [cppreference — std::sort](https://en.cppreference.com/w/cpp/algorithm/sort)
- [cppreference — Iterator library](https://en.cppreference.com/w/cpp/iterator)
- [cppreference — Templates](https://en.cppreference.com/w/cpp/language/templates)
- [cppreference — typename disambiguator](https://en.cppreference.com/w/cpp/keyword/typename)
- [cppreference — typedef declaration](https://en.cppreference.com/w/cpp/language/typedef)
- [C++ STL Containers overview](https://en.cppreference.com/w/cpp/container)

### AI Usage

AI (Claude) was used throughout this project as a **tutor, research assistant, and tester**:

- **Tutor:** Explaining the purpose of `typename` in dependent type contexts, the difference between function templates and class templates, why `this->c` is needed to access protected members in template inheritance, and iterator category requirements.
- **Research:** Clarifying C++98 standard rules, understanding `std::stack`'s internal `container_type`, and reviewing STL algorithm complexity guarantees.
- **Tester:** Reviewing test cases for edge conditions (empty containers, single elements, overfilling), verifying exception messages, and checking that all iterator variants behave correctly.
