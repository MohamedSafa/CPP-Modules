*This project has been created as part of the 42 curriculum by msafa.*

## Description

Module 09 introduces the **C++ Standard Template Library (STL)**, focusing on the practical use of containers and algorithms to solve real-world problems efficiently. Each exercise uses a different STL container, and containers cannot be reused across exercises.

**Core concepts covered:**
- STL containers: `std::map`, `std::stack`, `std::vector`, `std::deque`
- Iterators and standard algorithms
- Parsing and input validation
- Time complexity and algorithmic efficiency
- The **Ford-Johnson merge-insert sort algorithm** (one of the most comparison-efficient sorting algorithms known)

---

### Exercise 00 — Bitcoin Exchange

Reads a CSV database of historical Bitcoin prices and evaluates an input file of date/value pairs, outputting each value multiplied by the exchange rate on or before the given date.

**Concepts:** `std::map`, lower-bound date lookup, CSV parsing, input validation.

**Why `std::map`?**

The database is a collection of date-price pairs where we need to look up the closest date efficiently. `std::map` was the natural fit for three reasons:

- **Automatic sorting on insertion:** every date inserted goes directly into its sorted position. A `std::vector` stores elements in insertion order — to use `lower_bound` on it you must sort it manually first, adding an extra step.
- **Natural key-value structure:** `map["2011-01-03"] = 0.30` directly expresses the relationship. With a `std::vector` you would need to manage pairs manually or use parallel arrays.
- **O(log n) closest date lookup:** `map.lower_bound(date)` finds the closest date in O(log n) with no setup. With a sorted `std::vector`, `std::lower_bound` is also O(log n) comparisons — but you still had to sort it first, and there is no built-in key concept.

In short: `std::map` gives automatic sorting, O(log n) lookup, and natural key-value pairing all at once, with no manual sorting step required.

### Exercise 01 — Reverse Polish Notation

Evaluates a mathematical expression given in Reverse Polish Notation (postfix notation). Operators supported: `+ - * /`.

**Concepts:** `std::stack`, postfix expression evaluation, error handling.

**Why `std::stack`?**

RPN evaluation works by pushing numbers and, when hitting an operator, popping the last two numbers inserted. This is exactly LIFO — last in, first out.

Example: `3 4 2 * +`
- Push `3`, push `4`, push `2`
- Hit `*` → pop `2` and `4`, push `8`
- Hit `+` → pop `8` and `3`, push `11`

Other containers fail here because:
- `std::queue` is FIFO — when hitting `*` it gives `3` and `4` from the front, not `2` and `4` from the back. Wrong operands.
- `std::list` has no `top()` — to get the last element you must traverse manually.
- `std::map` was already used in ex00 and is forbidden here.

`std::stack` exposes exactly `push`, `pop`, and `top` — the three operations RPN needs and nothing more.

### Exercise 02 — PmergeMe

Sorts a sequence of positive integers using the **Ford-Johnson merge-insert sort algorithm**, implemented independently for two containers (`std::vector` and `std::deque`). Displays the time taken by each container.

**Concepts:** `std::vector`, `std::deque`, Jacobsthal sequence, binary insertion sort, recursive divide-and-conquer, comparison counting.

**Why `std::vector` and `std::deque`?**

The Ford-Johnson algorithm requires random access by index and iterator arithmetic for binary search (`mid = lo + (hi - lo) / 2`). Both `std::vector` and `std::deque` support these. `std::list` for example has no random access and no iterator arithmetic, making binary search impossible with it.

The subject requires two different containers implementing the same algorithm so their performance can be compared. `std::deque` supports the same operations as `std::vector` (random access, iterator arithmetic, `push_back`, `insert`) making it a fair side-by-side comparison.

**Why is `std::vector` faster for large inputs?**

The difference comes down to memory layout:

`std::vector` stores all elements in a single contiguous block:
```
vector [3000 ints]:
[1][2][3][4]...[3000]   <- one block in memory, all adjacent
```

`std::deque` stores elements in fixed-size chunks (~128 ints per chunk on most systems), scattered across memory and connected by a pointer map:
```
deque [3000 ints] = ~24 chunks:
chunk01: [1  ][2  ]...[128]   <- somewhere in memory
chunk02: [129][130]...[256]   <- somewhere else
chunk03: [257][258]...[384]   <- somewhere else
...
chunk24: [2945]...[3000][ ]   <- somewhere else
map: [ptr01][ptr02]...[ptr24] <- extra pointer table
```

When the CPU accesses elements in a vector, surrounding elements are already loaded into cache. In a deque, jumping between elements during binary search or insertion can cross chunk boundaries — forcing the CPU to follow a pointer to a different memory location not in cache, causing a cache miss and stalling while waiting for RAM.

For small inputs (5 or 21 elements), everything fits in one or two chunks — the timing difference is negligible. For 3000 elements spanning 24 chunks, these cache misses accumulate across ~30,000 comparisons — which is exactly where the timing gap between vector and deque becomes visible.

---

## Instructions

### Compilation

Each exercise has its own `Makefile`. Navigate to the exercise directory and run:

```
make
```

To rebuild from scratch:

```
make re
```

To clean object files and binary:

```
make fclean
```

All exercises compile with `c++ -Wall -Wextra -Werror -std=c++98`.

---

### Exercise 00 — btc

**Input file format** — one entry per line:
```
date | value
```
- `date` must be in `YYYY-MM-DD` format
- `value` must be a positive float or integer between 0 and 1000

**Example:**
```
./btc input.txt
```

---

### Exercise 01 — RPN

- Numbers used as arguments are single digits (less than 10)
- The expression must be passed as a single quoted argument
- Operators: `+ - * /`

**Examples:**
```
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
```

---

### Exercise 02 — PmergeMe

- Any number of positive integers may be passed as separate arguments
- Handles at least 3000 elements
- Displays comparison count and execution time for both `std::vector` and `std::deque`

**Examples:**
```
./PmergeME 3 5 9 7 4
./PmergeME 131 87 56 167 391 142 23 22 537 705 242 305 552 456 303 162 235 13 511 792 518
./PmergeME `shuf -i 1-100000 -n 3000 | tr "\n" " "`
```

---

## AI Usage

AI (Claude) was used throughout this project in the following roles:

**Visualization and step-by-step tracing**
AI helped trace the Ford-Johnson algorithm step by step on concrete inputs (e.g. 21 elements), explaining exactly which comparison is made at each level of the recursion, how pend elements are reordered after the recursive sort, and where each insertion lands in the main sequence.

**Testing machine**
AI was used to run large batches of random inputs (100,000 trials) to find edge cases — for example, discovering that 21 elements can be sorted in as few as 64 comparisons, and identifying which input orderings produce 65 or 66 comparisons and why.

---

## Resources

- [cppreference.com — C++ Standard Library](https://en.cppreference.com/w/) — official C++ documentation for all STL containers, iterators, and algorithms used in this module
- [Human explanation and step-by-step visualisation of the Ford-Johnson algorithm — dev.to](https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91)
- [Ford-Johnson Algorithm: Merge-Insertion — Medium](https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42)
