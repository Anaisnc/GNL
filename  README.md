*This project has been created as part of the 42 curriculum by ancourt.*

# ft_printf

## Description

This project goal was to reproduce the original printf function, handling only the following conversions cspdiuxX% :

• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

## Instructions

### Compilation

The project is compiled using the Makefile:

make
make clean
make fclean
make re

This produces the static library : libftprintf.a

### Usage

To us the library:
```c
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h" 

int	main(void)
{
	int	original;
	int	crafted;

	char	*str = "Hello world";
	char	*empty_str = "";
	char	*null_str = NULL;
	void	*ptr = str;
	void	*null_ptr = NULL;
	int	n = 12;
	int	neg = -12;
	int	zero = 0;
	unsigned int u = 12;
	unsigned int u_large = 4294967295;

	original = printf("%s %s %s\n", str, empty_str, null_str);
	crafted = ft_printf("%s %s %s\n", str, empty_str, null_str);
	printf("%d | %d\n\n", original, crafted);

	original = printf("%d %d %d\n", n, neg, zero);
    crafted = ft_printf("%d %d %d\n\n", n, neg, zero);
    printf("%d | %d\n\n", original, crafted);

	original = printf("%u %u\n", u, u_large);
    crafted = ft_printf("%u %u\n\n", u, u_large);
    printf("%d | %d\n\n", original, crafted);

	original = printf("%x %X\n", u_large, u_large);
    crafted = ft_printf("%x %X\n\n", u_large, u_large);
    printf("%d | %d\n\n", original, crafted);

	original = printf("%p %p\n", ptr, null_ptr);
    crafted = ft_printf("%p %p\n\n", ptr, null_ptr);
    printf("%d | %d\n\n", original, crafted);

	original = printf("%%\n");
    crafted = ft_printf("%%\n\n");
    printf("%d | %d\n\n", original, crafted);

    return (0);
}
```
## Resources

### References

- Documentation on printf and formatted output : [https://www.geeksforgeeks.org/c/printf-in-c/](https://www.geeksforgeeks.org/c/printf-in-c/)
- Articles and tutorials on variadic functions in C
Books:
C Programming A modern Approach K.N.KING : to understand variable-length argument lists.

AI:
To help me improve explanations and structure this README.