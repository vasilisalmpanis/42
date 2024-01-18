# Libft 

This is my first school project written in C. It includes the implementation of various standard library functions with names prefixed by 'ft_'.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Build](#build)

## Introduction

Welcome to my Libft! This project includes custom implementations of standard library functions, following the naming convention with the 'ft_' prefix.

## Features

List of implemented functions:

- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_strlen`
- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_toupper`
- `ft_tolower`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_memchr`
- `ft_memcmp`
- `ft_strnstr`
- `ft_atoi`
- `ft_calloc`
- `ft_strdup`

## Usage

The Makefile creates a static library of these functions. To use simple compile your C program and include
the libft.h header file and include the libft.a file in the compilation of your program

## Build
```bash
make
```
~~~
#include "libft.h" // relative filepath
~~~

~~~
gcc your_c_file.c libft.a
./a.out
~~~
