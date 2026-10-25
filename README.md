# Rush 01

This project is a C program that solves a skyscraper-style Latin-square puzzle.
The main goal of the project is to solve the 4x4 version, but the solver can also handle 5x5 and 6x6 boards as bonus cases. Larger sizes such as 7x7, 8x8, and 9x9 are not practical here because the search becomes too slow.

## What the program does

The puzzle is a square grid where:

- each row contains the numbers 1 to N exactly once
- each column contains the numbers 1 to N exactly once
- clue values describe how many towers can be seen from each side

The program validates the input, searches for a valid arrangement using backtracking, and prints the solved grid if one exists.

## Supported sizes

- target: 4x4
- bonus working sizes: 5x5 and 6x6
- not feasible in practice: 7x7, 8x8, and 9x9

The solver was designed around the 4x4 challenge, while the larger sizes were only tested as extra cases.

## Input format

The solver expects exactly one argument: a string of integers separated by spaces.

For a side length N, the input must contain 4 x N values:

1. top visibility clues for each column (N values)
2. bottom visibility clues for each column (N values)
3. left visibility clues for each row (N values)
4. right visibility clues for each row (N values)

For a 4x4 puzzle, this means 16 integers total.

Example for a valid 4x4 puzzle:

```bash
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

## Build

```bash
gcc -Wall -Wextra -Werror *.c -o rush01
```

## Run

```bash
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

Example output:

```text
1234
2341
3412
4123
```

If the input is invalid or no valid solution exists, the program prints:

```text
ERROR
```

## Notes

- The core project target is 4x4.
- 5x5 and 6x6 can work as bonus sizes.
- 7x7, 8x8, and 9x9 are too slow for this backtracking approach.
- The implementation uses recursive search with bitmask tracking to keep row and column uniqueness constraints efficient for smaller grids.

## Files

- `main.c` — entry point and command-line handling
- `handle_input.c` — input parsing and validation
- `backtracking.c` — recursive solver logic
- `building_views.c` — visibility checks for clue validation
- `display_array.c` — prints the solved grid
- `array_inits.c` — initializes arrays
- `helper_funcs.c` — helper functions
