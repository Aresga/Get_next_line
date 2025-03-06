# get_next_line

An implementation of the `get_next_line` function, developed as part of the Hive Helsinki curriculum. This project focuses on reading a line from a file descriptor, enhancing understanding of file I/O operations and memory management in C.

## Table of Contents

- [Introduction](#introduction)
- [Function Prototype](#function-prototype)
- [Project Requirements](#project-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The `get_next_line` project involves creating a function that reads a line from a file descriptor and stores it in a provided variable. This function reads one line at a time, handling various edge cases such as different line lengths and end-of-file scenarios. The primary goal is to deepen understanding of file descriptors, buffer management, and dynamic memory allocation in C.

## Function Prototype

```c
int get_next_line(int fd, char **line);
```

- `fd`: The file descriptor to read from.
- `line`: A pointer to a variable where the function will store the line read from the file descriptor.

## Project Requirements

- The function should return:
  - `1` if a line has been read successfully.
  - `0` if the end of the file has been reached.
  - `-1` in case of an error.
- The function should handle multiple file descriptors without interfering with each other's readings.
- Memory allocated on the heap should be properly freed when necessary to avoid memory leaks.

## Installation

To include `get_next_line` in your project:

1. Clone the repository:

   ```bash
   git clone https://github.com/Aresga/get_next_line.git
   ```

2. Navigate to the project directory:

   ```bash
   cd get_next_line
   ```

3. Compile the library:

   ```bash
   make
   ```

   This will generate the `get_next_line.a` library file.

## Usage

To use `get_next_line` in your project:

1. Include the header file in your source code:

   ```c
   #include "get_next_line.h"
   ```

2. Compile your project with the `get_next_line.a` library. For example:

   ```bash
   gcc -Wall -Wextra -Werror -o your_program your_program.c -L. -lget_next_line
   ```

3. Run your program:

   ```bash
   ./your_program
   ```

## Project Structure

- `get_next_line.c`: Contains the main `get_next_line` function.
- `get_next_line.h`: Header file with function prototypes and necessary includes.
- `get_next_line_utils.c`: Contains utility functions used by `get_next_line`.
- `Makefile`: Script to build the library.

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature-name`.
3. Commit your changes: `git commit -m 'Add feature'`.
4. Push to the branch: `git push origin feature-name`.
5. Submit a pull request.
