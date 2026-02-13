NAME = form

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# Concepts from Exercise 01
# 1. Separation of Concerns ✓
# Form decides who can sign it (in beSigned())
# Bureaucrat just attempts to sign and reports result (in signForm())
# Each class handles its own rules
# 2. Invariant Safety ✓
# A Form can never be signed by someone unqualified
# The exception guarantees this — no way to bypass the check
# Better than returning true/false which caller might ignore
# 3. Encapsulation ✓
# _signed is private, only changed through beSigned()
# No setter — can't cheat the system
# 4. Exception-based Error Handling ✓
# Caller must handle errors (or crash)
# Can't silently ignore failures
# what() provides clear error messages


# Your Understanding ✓
# 1. Try/Catch vs If/Else
# If/else = optional checking, caller can forget
# Try/catch = forced error handling, can't ignore
# System crashes if you don't catch → invariant safety
# 2. Separation of Concerns
# Form knows its rules
# Bureaucrat just asks and reports
# Easy to modify one without touching the other
# 3. Encapsulation
# _signed only changes through beSigned()
# No backdoor to cheat the system
# 4. Forward Declaration
# Two classes need each other → circular dependency
# Solution: class Form; tells compiler "this exists, details later"
# Full #include goes in .cpp where you actually use the methods