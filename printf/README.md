_This project has been created as part of the 42 curriculum by **srosu**._

# FT_PRINTF

**keywords**: `Unix logic`
**skills**: `Rigor · Algorithms & AI`

## Description

`ft_printf` is a project from the 42 curriculum. The objective is to recreate a simplified version of the standard `printf` function in C, handling formatted output through variadic arguments and low-level write operations.

The project enforces a deep understanding of:

- Variadic functions using `<stdarg.h>`
- Format string parsing and specifier dispatching
- Base conversion for integers, hexadecimals, and pointers
- Low-level output using the `write` syscall

The function must handle the following format specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.

## Key Concepts

### Variadic Functions

A variadic function accepts a variable number of arguments. In C, this is done through the `<stdarg.h>` macros: `va_list` declares the argument list, `va_start` initializes it, `va_arg` retrieves the next argument with a given type, and `va_end` cleans up. Since `printf` doesn't know at compile time how many arguments it will receive, understanding how these macros work under the hood is central to the project.

### Format String Parsing

The format string is scanned character by character. Regular characters are written directly to output. When a `%` is encountered, the next character determines which conversion to apply. This dispatch logic is the core of the implementation and must handle every specified conversion correctly, including edge cases like `%%` and `NULL` pointers passed to `%s`.

### Base Conversion

Printing integers in different bases (decimal, hexadecimal, octal) requires converting a number digit by digit using modulo and division. For `%x` and `%X`, the result is expressed in base 16 with lowercase or uppercase letters respectively. For `%p`, the pointer address is cast to an `unsigned long` and printed in hexadecimal with a `0x` prefix.

### Return Value

Like the original `printf`, `ft_printf` returns the total number of characters printed. This requires tracking every single `write` call and accumulating the byte count throughout the entire execution, including across all helper functions.

## How It Works

### Core Logic

The main function scans the format string one character at a time. When it encounters a `%`, it reads the next character and routes execution to the corresponding handler. Every other character is printed as-is. The return value accumulates across all output operations.

### Internal Functions

**`ft_printf(const char *format, ...)`**
The entry point. Initializes the `va_list`, iterates over the format string, and dispatches to the appropriate handler for each specifier. Returns the total character count.

**`type_is(char c, va_list args)`**
The dispatcher. Takes the specifier character and the argument list, calls the correct output function, and returns the number of characters printed.

**`ft_putchar_fd(char c, int fd)`**
Writes a single character to the given file descriptor using `write`.

**`ft_putstr_fd(char *s, int fd)`**
Writes a string to the given file descriptor. Handles `NULL` input by printing `(null)`.

**`ft_putnbr_fd(int n, int fd)`**
Prints a signed integer. Handles `INT_MIN` explicitly to avoid undefined behavior on negation.

**`ft_putnbr_unsigned_fd(unsigned int n, int fd)`**
Prints an unsigned integer without sign handling.

**`ft_putnbr_base(unsigned long n, char *base, int fd)`**
Converts and prints a number in an arbitrary base. Used for `%x`, `%X`, and `%p`.

## File Structure

```
.
├── ft_printf.c                # Main function and parsing loop
├── type_is.c                  # Specifier dispatcher
├── ft_putchar_fd.c            # Character output
├── ft_putstr_fd.c             # String output
├── ft_putnbr_fd.c             # Signed integer output
├── ft_putnbr_unsigned_fd.c    # Unsigned integer output
├── ft_putnbr_base.c           # Base conversion output
└── ft_printf.h                # Header and prototypes
```

## Compilation & Usage

### 1. Clone the repository

```bash
git clone git@github.com:srosu/ft_printf.git
cd ft_printf
```

### 2. Build the static library

```bash
make
```

This produces `ft_printf.a`.

### 3. Compile your program against the library

```bash
cc -Wall -Wextra -Werror main.c ft_printf.a -o program
```

### 4. Example usage

```c
ft_printf("Hello, %s! You are %d years old.\n", "Alice", 30);
ft_printf("Pointer: %p\n", ptr);
ft_printf("Hex: %x / %X\n", 255, 255);
```

## Makefile Rules

| Rule          | Effect                                          |
| ------------- | ----------------------------------------------- |
| `make`        | Compiles all sources and produces `ft_printf.a` |
| `make clean`  | Removes all `.o` object files                   |
| `make fclean` | Removes `.o` files and `ft_printf.a`            |
| `make re`     | Full rebuild (`fclean` + `make`)                |

## Edge Cases Handled

- `NULL` passed to `%s` prints `(null)`
- `INT_MIN` handled correctly in `%d` and `%i`
- `%p` with a null pointer prints `(nil)`
- `%%` prints a literal percent sign
- Return value accurately reflects the total number of characters written

## Resources

### Technical Documentation

- `man 3 printf` — behavior of the original function, specifier definitions, and return value semantics
- `man 2 write` — low-level output syscall used throughout the implementation
- `man 0 stdarg.h` — variadic argument macros: `va_list`, `va_start`, `va_arg`, `va_end`

### Articles & Guides

- GeeksforGeeks — [Variadic functions in C](https://www.geeksforgeeks.org/variadic-functions-in-c/): covers how `va_arg` retrieves arguments at runtime
- 42 student write-ups — walkthroughs of the parse → dispatch → convert pattern that underpins the implementation

### Testing & Debugging Tools

- **Valgrind Memcheck** — used to verify the absence of memory leaks
- **AddressSanitizer (ASan)** — catch buffer overflows and use-after-free errors at runtime (`-fsanitize=address`)
- **printf-tester** by [Tripouille](https://github.com/Tripouille/printfTester) and **pft** — community testers used to validate behavior across all specifiers and edge cases

## Use of AI

AI tools such as Claude were used as supplementary resources to clarify certain concepts, assist with debugging, and help with documentation.

All implementations and design choices were carried out independently.
