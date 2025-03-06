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

The `get_next_line` project involves creating a function that reads a line from a file descriptor and returns it. This function reads one line at a time, handling various edge cases such as different line lengths and end-of-file scenarios. The primary goal is to deepen understanding of file descriptors, buffer management, and dynamic memory allocation in C.

## Function Prototype

```c
char *get_next_line(int fd);
```

- `fd`: The file descriptor to read from.

## Project Requirements

### Mandatory Part

- **Function Name**: `get_next_line`

- **Prototype**: `char *get_next_line(int fd);`

- **Turn-in Files**: `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`

- **Parameters**:
  - `fd`: The file descriptor to read from.

- **Return Value**:
  - Returns the line that has been read.
  - Returns `NULL` if there is nothing else to read or if an error occurred.

- **External Functions**: `read`, `malloc`, `free`

- **Description**:
  - Write a function that returns a line read from a file descriptor.
  - Repeated calls (e.g., using a loop) to your `get_next_line()` function should let you read the text file pointed to by the file descriptor, one line at a time.
  - Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return `NULL`.
  - Ensure that your function works as expected both when reading a file and when reading from the standard input.
  - The returned line should include the terminating `\n` character, except if the end of file was reached and does not end with a `\n` character.
  - Your header file `get_next_line.h` must at least contain the prototype of the `get_next_line()` function.
  - Add all the helper functions you need in the `get_next_line_utils.c` file.
  - A good start would be to understand what a static variable is.
  - Because you will have to read files in `get_next_line()`, add this option to your compiler call: `-D BUFFER_SIZE=n`. It will define the buffer size for `read()`. The buffer size value will be modified by your peer evaluators and the Moulinette in order to test your code.
  - We must be able to compile this project with and without the `-D BUFFER_SIZE` flag in addition to the usual flags. You can choose the default value of your choice.
  - You will compile your code as follows (a buffer size of 42 is used as an example):
    ```bash
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
    ```
  - We consider that `get_next_line()` has an undefined behavior if the file pointed to by the file descriptor changed since the last call whereas `read()` didn’t reach the end of file.
  - We also consider that `get_next_line()` has an undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to.
  - Does your function still work if the `BUFFER_SIZE` value is 9999? If it is 1? 10000000? Do you know why?
  - Try to read as little as possible each time `get_next_line()` is called. If you encounter a new line, you have to return the current line. Don’t read the whole file and then process each line.

### Forbidden

- You are not allowed to use your `libft` in this project.
- `lseek()` is forbidden.
- Global variables are forbidden.

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
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -o your_program your_program.c -L. -lget_next_line
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
