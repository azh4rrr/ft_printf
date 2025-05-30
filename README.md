# 🖨️ ft_printf

<div align="center">

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

**A custom implementation of the printf function in C** 🚀

*42 School Common Core project - Recreating one of the most essential functions in programming*

</div>

---

## 🎯 What is ft_printf?

`ft_printf` is a custom recreation of the standard C library function `printf()`. This project challenges you to understand variadic functions, format specifiers, and low-level output operations while building one of the most commonly used functions in C programming.

Perfect for understanding:
- **Variadic functions** and `va_list`
- **Format string parsing**
- **Type conversion and formatting**
- **Memory management in C**

## ⭐ Features

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Character | `ft_printf("%c", 'A')` → `A` |
| `%s` | String | `ft_printf("%s", "Hello")` → `Hello` |
| `%d` / `%i` | Signed decimal integer | `ft_printf("%d", 42)` → `42` |
| `%u` | Unsigned decimal integer | `ft_printf("%u", 42U)` → `42` |
| `%x` | Hexadecimal (lowercase) | `ft_printf("%x", 255)` → `ff` |
| `%X` | Hexadecimal (uppercase) | `ft_printf("%X", 255)` → `FF` |
| `%p` | Pointer address | `ft_printf("%p", ptr)` → `0x7fff5fbff8ac` |
| `%%` | Literal percent | `ft_printf("%%")` → `%` |

## 🚀 Quick Start

### 1. Clone the repository
```bash
git clone https://github.com/azh4rrr/ft_printf.git
cd ft_printf
```

### 2. Compile
```bash
# Using the Makefile
make

# Clean up
make clean
make fclean
make re
```

### 3. Use it in your project
```c
#include "libftprintf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "World");
    ft_printf("Number: %d, Hex: %x\n", 42, 42);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

## 💡 Usage Examples

### Basic Usage
```c
#include "libftprintf.h"

int main(void)
{
    int count;
    
    // Character and string formatting
    count = ft_printf("Character: %c\n", 'A');
    ft_printf("Printed %d characters\n", count);
    
    // String handling (including NULL)
    ft_printf("String: %s\n", "Hello World");
    ft_printf("NULL string: %s\n", NULL);  // Prints "(null)"
    
    // Integer formatting
    ft_printf("Positive: %d, Negative: %d\n", 42, -42);
    ft_printf("Unsigned: %u\n", 4294967295U);
    
    // Hexadecimal formatting
    ft_printf("Lowercase hex: %x\n", 255);
    ft_printf("Uppercase hex: %X\n", 255);
    
    // Pointer formatting
    int var = 42;
    ft_printf("Pointer: %p\n", &var);
    
    // Percent literal
    ft_printf("Progress: 50%%\n");
    
    return (0);
}
```

### Advanced Examples
```c
// Mixed formatting
ft_printf("User %s (ID: %d) has %u points and lives at %p\n", 
          "Alice", 1001, 15000U, &user);

// Edge cases
ft_printf("Zero: %d, Max int: %d, Min int: %d\n", 
          0, 2147483647, -2147483648);

// Hexadecimal showcase
ft_printf("Colors: Red=#%X, Green=#%x, Blue=#%X\n", 
          0xFF0000, 0x00ff00, 0x0000FF);
```

## 🛠️ Implementation Details

### Core Functions

#### Main Function
- `ft_printf()` - Main function that parses format string and handles variadic arguments

#### Format Handlers
- `ft_puttchar()` - Handles `%c` (character output)
- `ft_puttstr()` - Handles `%s` (string output with NULL protection)
- `ft_puttnbr()` - Handles `%d` and `%i` (signed integers)
- `ft_putunbr()` - Handles `%u` (unsigned integers)
- `ft_puthex()` - Handles `%x` (lowercase hexadecimal)
- `ft_putuhex()` - Handles `%X` (uppercase hexadecimal)
- `ft_puthexx()` - Handles `%p` (pointer addresses)

### Architecture
```
ft_printf()
    ├── Format string parsing
    ├── Variadic argument handling
    └── check() - Format specifier dispatcher
            ├── Character formatting (%c)
            ├── String formatting (%s)
            ├── Integer formatting (%d, %i, %u)
            ├── Hexadecimal formatting (%x, %X)
            └── Pointer formatting (%p)
```

## 🔍 Technical Highlights

### Variadic Functions
```c
int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    // Process arguments
    va_end(args);
    return (count);
}
```

### Recursive Number Conversion
```c
void ft_puttnbr(int x, int *count)
{
    if (x == -2147483648)  // Handle INT_MIN edge case
    {
        ft_puttstr("-2147483648", count);
        return;
    }
    if (x < 0)
    {
        ft_puttchar('-', count);
        x = -x;
    }
    if (x > 9)
        ft_puttnbr(x / 10, count);  // Recursive call
    ft_puttchar(x % 10 + '0', count);
}
```

### Smart Memory Management
- No memory leaks
- Efficient character-by-character output
- Proper NULL handling for strings

## 🧪 Testing

### Test File Example
```c
#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
    printf("=== Testing ft_printf ===\n");
    
    // Compare with standard printf
    printf("Standard: ");
    int std_count = printf("Hello %s, number %d\n", "World", 42);
    
    printf("Custom:   ");
    int ft_count = ft_printf("Hello %s, number %d\n", "World", 42);
    
    printf("Standard returned: %d\n", std_count);
    printf("ft_printf returned: %d\n", ft_count);
    
    return (0);
}
```

### Edge Cases Covered
- `INT_MIN` (-2147483648)
- `NULL` string pointers
- Zero values
- Maximum unsigned integers
- Invalid format specifiers
- Empty format strings

## 📊 Performance & Standards

### 42 School Standards ✅
- **Norminette compliant**  
- **No forbidden functions** (except `write`, `malloc`, `free`, `va_start`, `va_arg`, `va_copy`, `va_end`)  
- **No memory leaks**  
- **Mandatory requirements only** - passes all required tests  

### Return Value
- Returns the number of characters printed (like standard `printf`)
- Returns -1 on error

## 🔧 Compilation Flags
```bash
gcc -Wall -Wextra -Werror -I. ft_printf.c printf_func.c printf_utils.c
```

## 📄 Project Structure

```
📦 ft_printf/
├── 📄 ft_printf.c           # Main implementation
├── 📄 printf_func.c         # Core formatting functions
├── 📄 printf_utils.c        # Utility functions
├── 📄 libftprintf.h         # Header file
├── 📄 Makefile              # Build configuration
└── 📄 README.md             # This file
```

## 🆚 Differences from Standard printf

| Feature | Standard printf | ft_printf |
|---------|----------------|-----------|
| Format specifiers | All specifiers | `c s d i u x X p %` |
| Field width | Supported | Not implemented |
| Precision | Supported | Not implemented |
| Flags (`-`, `+`, `#`, etc.) | Supported | Not implemented |
| Length modifiers | Supported | Not implemented |

## 🎓 Learning Outcomes

This project teaches:
- **Variadic functions** - Understanding `va_list`, `va_start`, `va_arg`, `va_end`
- **Format parsing** - String analysis and character-by-character processing
- **Type conversion** - Converting integers to different bases (decimal, hexadecimal)
- **Recursion** - Implementing number printing through recursive calls
- **Memory management** - Safe string handling and NULL pointer protection
- **System calls** - Using `write()` system call for output

## 🤝 Contributing

Found a bug or want to improve the implementation? Feel free to:
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

<div align="center">

**Made with ❤️ by [azh4rrr](https://github.com/azh4rrr)**

*42 School Common Core project - mandatory requirements completed*

*If this helped you understand printf better, give it a ⭐!*

</div>
