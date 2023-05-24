#include "ft_printf.h"

int	main() {
	char			c = 'A';
	char*			str = "Hello, world!";
	void*			ptr = &main;
	int				decimal = 42;
	int				integer = -123;
	unsigned int	unsignedDecimal = 567;
	int				hexLower = 255;
	int				hexUpper = 255;

	// %c
	printf("Regular printf %%c: %c\n", c);
	ft_printf("ft_printf %%c: %c\n", c);

	// %s
	printf("Regular printf %%s: %s\n", str);
	ft_printf("ft_printf %%s: %s\n", str);

	// %p
	printf("Regular printf %%p: %p\n", ptr);
	ft_printf("ft_printf %%p: %p\n", ptr);

	// %d
	printf("Regular printf %%d: %d\n", decimal);
	ft_printf("ft_printf %%d: %d\n", decimal);

	// %i
	printf("Regular printf %%i: %i\n", integer);
	ft_printf("ft_printf %%i: %i\n", integer);

	// %u
	printf("Regular printf %%u: %u\n", unsignedDecimal);
	ft_printf("ft_printf %%u: %u\n", unsignedDecimal);

	// %x
	printf("Regular printf %%x: %x\n", hexLower);
	ft_printf("ft_printf %%x: %x\n", hexLower);

	// %X
	printf("Regular printf %%X: %X\n", hexUpper);
	ft_printf("ft_printf %%X: %X\n", hexUpper);

	// %%
	printf("Regular printf %%%%: %%\n");
	ft_printf("ft_printf %%%%: %%\n");

	// int i = 10;

	// printf("%u\n", (unsigned int))

	return 0;
}
