# Get Next Line Project

## Table of Contents
- [Introduction](#introduction)
- [Mandatory Part](#mandatory-part)
    - [Description](#description)
    - [Usage](#usage)
    - [Compilation](#compilation)
- [Bonus Part](#bonus-part)
    - [Description](#description-bonus)
    - [Files](#files-bonus)

## Introduction

The Get Next Line project involves the creation of a function called `get_next_line` that reads a line from a file descriptor. The project has both a mandatory and a bonus part.

## Mandatory Part

### Description

The `get_next_line` function reads a line from a file descriptor and returns it. Repeated calls to `get_next_line` let you read a text file, one line at a time. The function returns the line that was read or NULL if there is nothing else to read or an error occurred. The returned line includes the terminating `\n` character, except if the end of the file was reached and does not end with a `\n` character.

### Usage

```c
char *get_next_line(int fd);
```

## Compilation
To compile the project, use the following compilation flags, where BUFFER_SIZE can be defined as needed:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=n <files>.c
```

# Bonus Part

## Description
The bonus part of the project involves developing get_next_line using only one static variable and allowing the function to manage multiple file descriptors simultaneously. This means that get_next_line can read from different file descriptors without losing the reading thread of each file descriptor or returning a line from another file descriptor.

## Files (Bonus)
The bonus part of the project involves developing get_next_line using only one static variable and allowing the function to manage multiple file descriptors simultaneously. This means that get_next_line can read from different file descriptors without losing the reading thread of each file descriptor or returning a line from another file descriptor.
- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`
