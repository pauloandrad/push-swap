*This project has been created as part of the 42 curriculum by pahenriq.*

---

# 📚 Libft — Optimized for ft_printf

> A reduced and optimized version of libft containing only the essential functions needed for the ft_printf project, along with a custom `ft_utoa_base` function for base conversion utilities.

---

## 📋 Table of Contents

- [Description](#description)
- [Project Structure](#project-structure)
- [Compilation & Linking](#compilation--linking)
- [Functions Reference](#functions-reference)
- [Technical Rules](#technical-rules)

---

## Description

**Libft** in this project is a **minimized and optimized version** of the full libft library, containing only the essential functions required for the **ft_printf** implementation. Rather than including all standard C library reimplementations, this version focuses on performance and code efficiency by including only what is necessary.

### Functions Included

This reduced libft contains the following functions used by ft_printf:

**Output Functions:**
- `ft_putchar_fd` — Outputs a single character to a file descriptor
- `ft_putstr_fd` — Outputs a string to a file descriptor

**String Utilities:**
- `ft_strlen` — Calculates the length of a string
- `ft_itoa` — Converts an integer to a string representation

**Custom Utility:**
- `ft_utoa_base` — Converts an unsigned long integer to a string in a specific base (binary, octal, decimal, hexadecimal, etc.) — a custom function optimized for printf number formatting

This streamlined approach avoids unnecessary bloat while providing all the building blocks needed for a fully functional printf implementation.

---

## Project Structure

```
libft/
├── Makefile
├── libft.h
├── ft_putchar_fd.c
├── ft_putstr_fd.c
├── ft_strlen.c
├── ft_itoa.c
├── ft_utoa_base.c
└── README.md
```

> This is a minimal implementation containing only the functions required by ft_printf. Functions are compiled into `libft.a` static archive located at the root of the libft directory.

---

## Compilation & Linking

### Requirements

- GCC or compatible C compiler
- `make` utility
- UNIX-based system (Linux / macOS or Windows with POSIX tools)

### Compiling libft

From the `libft/` directory:

```bash
make          # Compile libft.a
make clean    # Remove .o object files
make fclean   # Remove .o files and libft.a
make re       # Clean and recompile from scratch
```

### Linking with ft_printf

The parent Makefile (in the printf directory) handles linking automatically. The libft.a is compiled and linked to the printf executable through:

```bash
$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
```

Where:
- `$(LIBFT)` points to `libft/libft.a`
- `$(IFLAGS)` includes the path to `libft.h` header

To include libft functions in your code:
```c
#include "libft.h"
```

### Makefile Rules

| Rule | Description |
|------|-------------|
| `make all` or `make` | Compiles `libft.a` |
| `make clean` | Removes `.o` object files |
| `make fclean` | Removes `.o` files and `libft.a` |
| `make re` | Runs `fclean` then `all` |

> The Makefile uses `ar` to create the static library. Compilation flags: `-Wall -Wextra -Werror`

---

## Functions Reference

This optimized libft for ft_printf includes the following functions:

### Output Functions

| Function | Prototype | Description |
|----------|-----------|-------------|
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Outputs a single character `c` to file descriptor `fd` |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Outputs the entire string `s` to file descriptor `fd` |

### String Utilities

| Function | Prototype | Description |
|----------|-----------|-------------|
| `ft_strlen` | `size_t ft_strlen(const char *s)` | Returns the length of string `s` (number of characters, excluding the null terminator) |
| `ft_itoa` | `char *ft_itoa(int n)` | Allocates and returns a string representing the integer `n`, including the sign for negative numbers. Returns `NULL` on allocation failure |

### Custom Utilities

| Function | Prototype | Description |
|----------|-----------|-------------|
| `ft_utoa_base` | `char *ft_utoa_base(unsigned long n, int base, const char *charset)` | Allocates and returns a string representing the unsigned long `n` in the specified `base` (2-36). Uses `charset` to determine digit characters (e.g., `"0123456789abcdef"` for hexadecimal). Returns `NULL` on allocation failure |

> Common file descriptors: `0` = stdin, `1` = stdout, `2` = stderr.

---

## Technical Rules

These constraints apply to the entire project:

- Written in **C** only
- Must follow **42 Norm** (style rules) — norm errors result in grade 0
- **No global variables** allowed
- Helper/internal functions must be declared as `static`
- No unexpected exits (no segfaults, bus errors, double frees, etc.)
- **No memory leaks** — all heap-allocated memory must be freed
- Library is created using the `ar` command — `libtool` is **forbidden**
- The `libft.a` archive must be generated at the **root** of the repository
- All `.c` files must compile cleanly with `-Wall -Wextra -Werror`
- The `restrict` qualifier and `-std=c99` flag are **forbidden**
- Unused files must **not** be submitted

---

## Integration Notes

This optimized libft is specifically designed to work with the **ft_printf** project. All five functions are directly used by the printf handlers:

- **ft_putchar_fd** and **ft_putstr_fd** → Output formatted text to stdout
- **ft_strlen** → Calculate string lengths for output metrics
- **ft_itoa** → Convert signed integers to strings
- **ft_utoa_base** → Convert unsigned numbers to various bases (binary, octal, decimal, hexadecimal)

The parent Makefile in the printf directory automatically handles compilation and linking of this library.
