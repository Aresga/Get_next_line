# Get Next Line

## Overview

**Get Next Line** is a C programming project aimed at creating a function that reads a line (terminated by a newline character `\n`) from a file descriptor. This project is designed to handle reading from files or standard input efficiently, managing memory allocation, and supporting multiple file descriptors when the bonus part is implemented. It’s a part of Hive Helsinki curriculum, emphasizing skills in static variables, memory management, and file I/O operations.

The function `get_next_line` returns:
- **1** if a line is successfully read,
- **0** if the end of the file is reached,
- **-1** if an error occurs.

## Features

- Reads a line from a file descriptor, regardless of buffer size (defined by `BUFFER_SIZE`).
- Handles memory allocation dynamically to store the line.
- Preserves unread content for subsequent calls using a static variable.
- (Bonus, if implemented) Supports reading from multiple file descriptors simultaneously.

## Repository Structure

- `get_next_line.c`: Core implementation of the `get_next_line` function.
- `get_next_line.h`: Header file with function prototype and necessary includes.
- `get_next_line_utils.c`: Helper functions (e.g., string manipulation utilities).
- (Optional) `main.c`: Test file for running and verifying the function (not included in submission).

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Aresga/Get_next_line.git
   cd Get_next_line
   ```

2. Compile the project with your desired `BUFFER_SIZE` (e.g., 32):
   ```bash
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o gnl
   ```
   
## Usage

To use `get_next_line` in your own project:

1. Include the header in your code:
   ```c
   #include "get_next_line.h"
   ```

2. Call the function in a loop to read a file line by line:
   ```c
   #include <fcntl.h>
   #include <stdio.h>
   #include "get_next_line.h"

   int main(void)
   {
       int fd = open("test.txt", O_RDONLY);
       char *line;

       if (fd < 0)
           return (1);
       while ((line = get_next_line(fd)) != NULL)
       {
           printf("%s", line);
           free(line); // Don’t forget to free the returned line!
       }
       close(fd);
       return (0);
   }
   ```

3. Compile with your program:
   ```bash
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 your_program.c get_next_line.c get_next_line_utils.c -o your_program
   ```

## Testing

- Create a `test.txt` file with some text to read:
  ```bash
  echo -e "Line 1\nLine 2\nLine 3" > test.txt
  ```

- Run the compiled program:
  ```bash
  ./gnl
  ```

- Expected output:
  ```
  Line 1
  Line 2
  Line 3
  ```

## Notes

- The `BUFFER_SIZE` value can be adjusted at compile time to optimize performance or test edge cases (e.g., `BUFFER_SIZE=1` or `BUFFER_SIZE=9999`).
- Ensure proper memory management by freeing each line returned by `get_next_line`.
- For the bonus part (if included), test with multiple file descriptors to verify functionality.

## Author

- GitHub: [Aresga](https://github.com/Aresga)

## License

This project is unlicensed and intended for educational purposes as part of the 42 school curriculum.

---
