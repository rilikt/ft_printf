# 🖨️ ft_printf – Custom Implementation of printf()

`ft_printf` is a custom implementation of the C standard library function `printf()`. This project aims to deepen your understanding of variadic functions, memory management, and formatted output—essential tools for any serious C developer.

---

## 📚 Project Overview

The goal is to recreate `printf()` from scratch with limited features and no internal buffering. This includes formatting output for various data types and handling variable arguments using `stdarg.h`.

---

## 🔧 Features

### ✅ Supported Conversions (Mandatory)

| Format | Description                   |
|--------|-------------------------------|
| `%c`   | Print a single character      |
| `%s`   | Print a string                |
| `%p`   | Print a pointer in hex format |
| `%d`   | Print a decimal (int)         |
| `%i`   | Print an integer              |
| `%u`   | Print an unsigned int         |
| `%x`   | Print hex (lowercase)         |
| `%X`   | Print hex (uppercase)         |
| `%%`   | Print a percent sign          |

---

## 🛠️ Implementation Details

- **Prototype**: `int ft_printf(const char *format, ...);`
- No buffering (unlike the original `printf`)
- Only uses: `write`, `malloc`, `free`, `va_start`, `va_arg`, `va_copy`, `va_end`
- Builds a static library: `libftprintf.a`

---

## 🧬 Example Integration

```c
#include "ft_printf.h"

int main(void) {
    ft_printf("Hello, %s! You are %d years old.\n", "Alice", 30);
    return (0);
}
