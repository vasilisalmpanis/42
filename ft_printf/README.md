# ft_printf

This project involves the creation of a library named `libftprintf.a` that includes a custom implementation of the `printf` function, called `ft_printf`. The goal is to mimic the behavior of the original `printf` function from the C library.

## Table of Contents
- [Introduction](#introduction)
- [Requirements](#requirements)
- [Usage](#usage)
- [build](#build)

## Introduction

The `ft_printf` function is designed to replicate the behavior of the standard C library's `printf` function. It handles various format specifiers to print different types of data. The project involves practicing the use of variadic functions, specifically dealing with a variable number of arguments.

## Requirements

### Functionality

The `ft_printf` function should handle the following format specifiers:

- `%c`: Prints a single character.
- `%s`: Prints a string.
- `%p`: Prints a void pointer in hexadecimal format.
- `%d`: Prints a decimal (base 10) number.
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a percent sign.

## Usage

To use the `ft_printf` function in your project, follow these steps:

1. Clone the repository:

    ```bash
   git clone https://github.com/vasilisalmpanis/42
   cd 42/ft_printf
   make  
    ```

    ~~~
    #include "libftprintf.h"
   gcc -o my_program my_program.c libftprintf.a
   ./my_program
    ~~~ 
