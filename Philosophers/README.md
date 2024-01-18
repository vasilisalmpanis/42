# Philosophers

## Overview

This project involves simulating the Dining Philosophers problem using threads and mutexes. The program creates a set of philosophers that share a dining table with forks placed between each pair of philosophers. The goal is to avoid deadlocks and ensure that each philosopher can eat without conflicts.

## Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- `number_of_philosophers`: The number of philosophers at the dining table.
- `time_to_die`: Time in milliseconds for a philosopher to die if they haven't eaten.
- `time_to_eat`: Time in milliseconds for a philosopher to finish eating.
- `time_to_sleep`: Time in milliseconds for a philosopher to sleep.
- `number_of_times_each_philosopher_must_eat (optional)`: The number of times each philosopher must eat. If not provided, the simulation runs indefinitely.

## Compilation
To compile the program, navigate to the `Philosophers/` directory and use the provided Makefile with the following commands:
```
make          # Compile the source files
make clean    # Remove object files
make fclean   # Remove object files and the executable
make re       # Re-compile the program
```

## Implementation Details
- Each philosopher is implemented as a separate thread.
- Forks are represented by mutexes to avoid conflicts.
- Time-related functions like usleep and gettimeofday are used for synchronization.
- The program ensures that philosophers share forks appropriately to prevent deadlocks.

## Example
```
./philo 5 800 200 200
```
This command simulates 5 philosophers with a time to die of 800ms, time to eat of 200ms, and time to sleep of 200ms.
