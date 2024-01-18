# Pipex

## Overview

This project focuses on handling pipes and aims to replicate the behavior of certain shell commands using C programming. The program takes four arguments - file1, cmd1, cmd2, and file2 - and executes a series of commands with input and output redirection.

## Usage

```bash
./pipex file1 cmd1 cmd2 file2
```

## Build
```
make
```

## Examples
- Basic usage
    ```
    ./pipex infile "ls -l" "wc -l" outfile
    ```
    Should behave like: `< infile ls -l | wc -l > outfile`
- Another Example
    ```
    ./pipex infile "grep a1" "wc -w" outfile
    ```
    Should behave like: `< infile grep a1 | wc -w > outfile`

## Bonus features

- Multiple Pipes:
    Execute multiple commands with pipes:
    ```
    ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
    ``` 
    Should behave like: `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`
    - Here_doc and Redirection:
      Support for "here_doc" and redirection:
    ```
    ./pipex here_doc LIMITER cmd cmd1 file
    ``` 
    Should behave like: `cmd << LIMITER | cmd1 >> file`    

## Makefile
 ```
 make          # Compile the source files
 make clean    # Remove object files
 make fclean   # Remove object files and the executable
 make re       # Re-compile the program
 ```
