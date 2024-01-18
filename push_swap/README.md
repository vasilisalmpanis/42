# Push_Swap

## Table of Contents
- [Introduction](#introduction)
- [Requirements](#requirements)
    - [Project Files](#project-files)
    - [Compilation](#compilation)
- [Usage](#usage)
    - [Examples](#examples)
- [Rules](#rules)

## Introduction

The Push_swap program is designed to sort stacks using a specific set of operations. The goal is to display the smallest list of instructions possible to sort the stack, with the smallest number being at the top.
This project is designed to us learn what time complexity is.

## Requirements

### Project Files

- Makefile
- *.h
- *.c

### Compilation

The Makefile should include the following targets:

- `NAME`: Set the name of the executable (push_swap).
- `all`: Compile the source files.
- `clean`: Remove object files.
- `fclean`: Remove object files and the executable.
- `re`: Rebuild the executable.

## Usage

The program `push_swap` takes as an argument the stack "a," formatted as a list of integers. The program displays the smallest list of instructions possible to sort the stack "a," where the smallest number is at the top.

### Examples

```bash
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

```
$>./push_swap 0 one 2 3
Error
```

## Rules
- You have 2 stacks named "a" and "b."
- The stack "a" contains a random amount of negative and/or positive numbers that cannot be duplicated.
- The stack "b" is initially empty.
- The goal is to sort numbers in ascending order into stack "a."
- Available operations:
  - sa (swap a)
  - sb (swap b)
  - ss (sa and sb at the same time)
  - pa (push a)
  - pb (push b)
  - ra (rotate a)
  - rb (rotate b)
  - rr (ra and rb at the same time)
  - rra (reverse rotate a)
  - rrb (reverse rotate b)
  - rrr (rra and rrb at the same time)