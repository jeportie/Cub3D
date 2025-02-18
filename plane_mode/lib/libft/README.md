![Screenshot from 2024-10-28 17-20-28](https://github.com/user-attachments/assets/01c2bf74-2b9d-48d5-a734-8a61d65d650e)

# Libft - 42_School Standard library with some improvements and optimizations

A custom library built in C, designed as a functional and comprehensive reimplementation of various standard C functions, along with additional utility functions for common tasks. This library is designed with portability and reliability in mind, suitable for use in any C project that could benefit from an extended C standard library.

## Features

- **Standard C Functions**: Re-implemented functions from `<stdlib.h>`, `<string.h>`, `<unistd.h>`, etc.
- **Custom Utility Functions**: Additional utilities for advanced data handling and common tasks.
- **Memory Safety**: Includes checks for memory allocation and error handling.
- **Printf and GNL**: An extensive version of `ft_printf` with format specifiers support and `get_next_line` for file handling.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Functionality](#functionality)
- [Project Structure](#project-structure)
- [Error Handling](#error-handling)
- [Contributing](#contributing)
- [License](#license)

## Installation

To integrate `libft` into your project, clone the repository and include it in your build configuration. Run the following commands:

```sh
git clone https://github.com/username/libft.git
cd libft
make
```

The `make` command compiles `libft` into a static library file, `libft.a`, which you can link with your projects.

## Usage

Include the main `libft.h` header file in your project and link with `libft.a` during compilation. Example:

```c
#include "libft/libft.h"

int main() {
    char *str = ft_strdup("Hello, libft!");
    ft_putstr_fd(str, 1);
    free(str);
    return 0;
}
```

Compile with:

```sh
gcc -o my_program my_program.c -Llibft -lft
```

## Functionality

### 1. **Boolean Functions**

Custom Boolean functions for character classification and validation.

- `ft_isalnum(int c)`
- `ft_isalpha(int c)`
- `ft_isascii(int c)`
- `ft_isdigit(int c)`
- `ft_isspace(int c)`

### 2. **Memory Management Functions**

Memory allocation and manipulation functions, including enhanced error handling.

- `ft_bzero(void *s, size_t n)`
- `ft_calloc(size_t nmemb, size_t size)`
- `ft_memcpy(void *dest, const void *src, size_t n)`
- `ft_realloc(void *ptr, size_t old_size, size_t new_size)`

### 3. **String and Conversion Functions**

String handling, conversion functions, and additional utilities.

- `ft_atoi(const char *nptr)`
- `ft_strchr(const char *s, int c)`
- `ft_strjoin(const char *s1, const char *s2)`
- `ft_strlen(const char *s)`

### 4. **GNL (Get Next Line)**

Efficient reading function for file descriptors.

- `get_next_line(int fd)`

### 5. **Printf**

Enhanced `ft_printf` and `ft_dprintf` functions with support for various format specifiers.

- `ft_printf(const char *format, ...)`
- `ft_dprintf(int fd, const char *format, ...)`

## Project Structure

The library is structured as follows:

```
libft/
├── include/         # Header files
│   └── libft.h      # Main header
├── src/             # Source files categorized by functionality
│   ├── memory/      # Memory functions
│   ├── string/      # String manipulation
│   ├── io/          # Input/Output functions
│   └── gnl/         # get_next_line implementation
└── Makefile         # Compilation instructions
```

Each function resides in its respective `.c` file under `src/`.

## Error Handling

Error handling follows best practices with consistent checks and defined error codes where applicable:

- **Memory Allocation**: Functions return `NULL` if memory allocation fails.
- **I/O Operations**: Error codes or indicators are returned if any system call fails.

For critical errors, functions such as `ft_check_malloc` or `ft_check_fd` will log a descriptive error and may exit the program gracefully.

## Contributing

We welcome contributions! To get started:

1. Fork the repository.
2. Clone your fork.
3. Create a new branch.
4. Make your changes.
5. Commit and push your changes.
6. Create a pull request.

Please ensure that code changes are well-documented and tested. Contributions should follow the project’s coding style and be consistent with existing implementations.

## License

This library is open source, available under the MIT License. See the `LICENSE` file for more details.

--- 

This README provides a concise, professional overview of `libft`, making it accessible for developers interested in extending their C projects with custom functionality.

## Languages and Tools:

<p align="left">
  <img src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg" height="40" alt="C" />
  <img width="12" />
  <img src="https://github.com/devicons/devicon/blob/master/icons/bash/bash-original.svg" height="40" alt="Bash" />
  <img width="12" />
  <img src="https://github.com/devicons/devicon/blob/master/icons/cmake/cmake-original.svg" height="40" alt="Make" />
  <img width="12" />
  <img src="https://github.com/devicons/devicon/blob/master/icons/git/git-original.svg" height="40" alt="Git" />
  <img width="12" />
</p>

## Connect with Me 🤝

<p align="left">
  <a href="https://profile.intra.42.fr/users/jeportie">
    <img src="https://badge.mediaplus.ma/greenbinary/jeportie?1337Badge=off&UM6P=off" alt="Jerome's 42 Badge" />
  </a>
</p>

- [Jerome's GitHub Profile](https://github.com/jeportie)

<div>
  <img height="150" src="https://github-readme-stats.vercel.app/api?username=jeportie&show_icons=true&theme=default" alt="Jerome's GitHub stats" />
</div>
