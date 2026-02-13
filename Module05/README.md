*This project has been created as part of the 42 curriculum by msafa.*

# CPP Module 05 - Repetition and Exceptions

## Description

This module is part of the 42 C++ curriculum and focuses on exception handling in C++. Through a series of exercises built around a bureaucratic theme, the project explores how to define, throw, and catch custom exceptions, as well as how to apply core OOP concepts such as inheritance, abstract classes, and polymorphism.

The module is divided into four exercises of increasing complexity:

- **ex00 - Bureaucrat:** Introduces the `Bureaucrat` class with a name and a grade (1 to 150). Throwing custom `GradeTooHighException` and `GradeTooLowException` when grades go out of range.
- **ex01 - Form:** Adds a `Form` class that can be signed by a `Bureaucrat`, provided the bureaucrat's grade meets the required threshold.
- **ex02 - Abstract Forms:** Converts `Form` into an abstract class `AForm` and introduces three concrete form types: `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`, each with unique execution behavior.
- **ex03 - Intern:** Introduces the `Intern` class, which can create any of the concrete forms by name using the `makeForm` method.

## Instructions

Each exercise has its own directory with a dedicated `Makefile`. To compile an exercise:

```bash
cd ex00
make
```

Available Makefile rules:
- `make` or `make all` - Compile the program
- `make clean` - Remove object files
- `make fclean` - Remove object files and the executable
- `make re` - Recompile from scratch

After compilation, run the resulting executable from within the exercise directory:

```bash
./bureaucrat    # ex00
./form          # ex01
./aform         # ex02
./intern        # ex03
```

## Resources

- [C++ Reference](https://cplusplus.com/reference/) - Official C++ documentation and standard library reference
- [cppreference.com](https://en.cppreference.com/) - Comprehensive C++ language and library reference
- AI (Claude) was used as a tool throughout the project for instructional guidance, explaining concepts related to exception handling and polymorphism, and for testing and debugging assistance.
