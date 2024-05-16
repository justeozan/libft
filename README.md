```markdown
# Libft

Libft is a library of functions that we use in 42's projects.

## Table of Contents

- [About](#About)
- [Usage](#usage)
- [Installation](#installation)
- [Documentation](#documentation)
- [Contributing](#contributing)
- [License](#license)

## About

Libft is a collection of standard C functions that we often use in 42's projects. These functions are implemented as part of the 42 curriculum to encourage students to understand common data structures and algorithms. The library includes functions for manipulating strings, memory, linked lists, and more.

## Usage

To use the Libft library in your project, you can simply include the header file `libft.h` and link against the compiled `libft.a` library. You can find the function prototypes and documentation in the header file, and you can link the library using the `-lft` flag.

```c
#include "libft.h"

int main() {
    ft_putstr("Hello, world!\n");
    return 0;
}
```

## Installation

To install Libft, simply clone the repository and compile the library using the provided Makefile.

```bash
git clone https://github.com/your_username/libft.git
cd libft
make
```

This will generate the `libft.a` static library file that you can link against in your projects.

## Documentation

You can find the documentation for each function in the `libft.h` header file. Each function is documented with its purpose, parameters, and return value.

## Contributing

Contributions to Libft are welcome! If you find any bugs or want to suggest improvements, feel free to open an issue or submit a pull request on GitHub.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.