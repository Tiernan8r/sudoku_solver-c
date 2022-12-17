# Sudoku Solver:

A simple CLI based sudoku solver, written in C.

### Compilation:

The `Makefile` should be all you need to compile and have a binary to run, requires `make` and `gcc` installed on your system.

```console
$ make
```

### Running:

Once the binary is compiled, it can be run with
```console
$ ./solver
```

The help message gives an overview of it's usage:
```console
$ ./solver --help
./solver - Solves a given sudoku grid.
USAGE:

./solver [flags] <file>

FLAGS:

-h/--help:      Display this message.

VALUES:

<file>:         The file to read for board input, defaults to stdin if unset.
```

The input needs to be encoded as follows:
* '\n' and 'EOF' characters are ignore as input, the reading ends on an 'EOF'.
* ' ' is interpreted as an empty cell.
* For a 9x9 sudoku grid, 1-9 are interpreted as cell values.
* For a 16x16 grid, the characters 1-9 and A-F are interpreted (upper case only).

* If the number of values given do not correspond to a valid sudoku table, the program will not run.

#### Example:
**Input**: 
 5  2 9 3
9    6  4
    1
 2 46   8
 748
     1 7
 9      5
5 1    26

Is interpreted as the cells:

```raw
+---+---+---+---+---+---+---+---+---+
|   | 5 |   |   | 2 |   | 9 |   | 3 |
+---+---+---+---+---+---+---+---+---+
| 9 |   |   |   |   | 6 |   |   | 4 |
+---+---+---+---+---+---+---+---+---+
|   |   |   |   | 1 |   |   |   |   |
+---+---+---+---+---+---+---+---+---+
|   | 2 |   | 4 | 6 |   |   |   | 8 |
+---+---+---+---+---+---+---+---+---+
|   | 7 | 4 | 8 |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   | 1 |   | 7 |   |
+---+---+---+---+---+---+---+---+---+
|   | 9 |   |   |   |   |   |   | 5 |
+---+---+---+---+---+---+---+---+---+
| 5 |   | 1 |   |   |   |   | 2 | 6 |
+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+
```

```console
$ ./solver example_input/test_input
3.txt
READING INPUT...
INPUT:
+---+---+---+---+---+---+---+---+---+
| 7 | 6 |   | 1 |   | 9 |   | 3 | 8 |
+---+---+---+---+---+---+---+---+---+
|   | 9 |   | 3 | 7 | 4 |   | 6 | 2 |
+---+---+---+---+---+---+---+---+---+
|   | 3 |   |   |   |   | 4 |   |   |
+---+---+---+---+---+---+---+---+---+
|   | 2 | 7 |   | 5 |   | 9 |   | 3 |
+---+---+---+---+---+---+---+---+---+
| 9 |   | 5 | 4 |   |   | 6 |   |   |
+---+---+---+---+---+---+---+---+---+
|   | 8 |   | 9 |   | 7 |   | 5 |   |
+---+---+---+---+---+---+---+---+---+
| 8 |   | 1 | 2 |   | 6 |   |   |   |
+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   | 1 | 7 | 2 | 6 |
+---+---+---+---+---+---+---+---+---+
|   |   |   | 7 | 4 |   |   | 9 |   |
+---+---+---+---+---+---+---+---+---+
SOLVING...
OUTPUT:
+---+---+---+---+---+---+---+---+---+
| 7 | 6 | 4 | 1 | 2 | 9 | 5 | 3 | 8 |
+---+---+---+---+---+---+---+---+---+
| 5 | 9 | 8 | 3 | 7 | 4 | 1 | 6 | 2 |
+---+---+---+---+---+---+---+---+---+
| 1 | 3 | 2 | 8 | 6 | 5 | 4 | 7 | 9 |
+---+---+---+---+---+---+---+---+---+
| 4 | 2 | 7 | 6 | 5 | 8 | 9 | 1 | 3 |
+---+---+---+---+---+---+---+---+---+
| 9 | 1 | 5 | 4 | 3 | 2 | 6 | 8 | 7 |
+---+---+---+---+---+---+---+---+---+
| 6 | 8 | 3 | 9 | 1 | 7 | 2 | 5 | 4 |
+---+---+---+---+---+---+---+---+---+
| 8 | 7 | 1 | 2 | 9 | 6 | 3 | 4 | 5 |
+---+---+---+---+---+---+---+---+---+
| 3 | 4 | 9 | 5 | 8 | 1 | 7 | 2 | 6 |
+---+---+---+---+---+---+---+---+---+
| 2 | 5 | 6 | 7 | 4 | 3 | 8 | 9 | 1 |
+---+---+---+---+---+---+---+---+---+
```