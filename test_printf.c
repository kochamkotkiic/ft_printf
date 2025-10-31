#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int a, b;

    printf("===== BASIC TEST =====\n");
    a = ft_printf("Hello %s %d %u %x %% %c %p\n", "world", -42, 42u, 255u, 'A', (void*)0x1234);
    b = printf("Hello %s %d %u %x %% %c %p\n", "world", -42, 42u, 255u, 'A', (void*)0x1234);
    printf("ft_printf returned %d, printf returned %d\n\n", a, b);

    printf("===== EDGE CASES =====\n");

    // %s — null and empty strings
    a = ft_printf("Empty: '%s', NULL: '%s'\n", "", NULL);
    b = printf("Empty: '%s', NULL: '%s'\n", "", (char *)NULL);
    printf("ft_printf: %d, printf: %d\n\n", a, b);

    // %c — special characters
    a = ft_printf("Chars: %c %c %c %c\n", 'A', '0', '\t', '\n');
    b = printf("Chars: %c %c %c %c\n", 'A', '0', '\t', '\n');
    printf("ft_printf: %d, printf: %d\n\n", a, b);

    // %d / %i — limits and zero
    a = ft_printf("INT_MIN: %d, INT_MAX: %d, zero: %d\n", INT_MIN, INT_MAX, 0);
    b = printf("INT_MIN: %d, INT_MAX: %d, zero: %d\n", INT_MIN, INT_MAX, 0);
    printf("ft_printf: %d, printf: %d\n\n", a, b);

    // %u — limits
    a = ft_printf("UINT_MAX: %u, small: %u\n", UINT_MAX, 1u);
    b = printf("UINT_MAX: %u, small: %u\n", UINT_MAX, 1u);
    printf("ft_printf: %d, printf: %d\n\n", a, b);

    // %x and %X — zero and big numbers
    a = ft_printf("hex lower: %x %x, upper: %X %X\n", 0, 4095, 0, 4095);
    b = printf("hex lower: %x %x, upper: %X %X\n", 0, 4095, 0, 4095);
    printf("ft_printf: %d, printf: %d\n\n", a, b);

    // %p — null and big pointer
    a = ft_printf("Pointer NULL: %p, valid: %p\n", NULL, (void *)ULONG_MAX);
    b = printf("Pointer NULL: %p, valid: %p\n", NULL, (void *)ULONG_MAX);
    printf("ft_printf: %d, printf: %d\n\n", a, b);

    // %% — consecutive and mixed
    a = ft_printf("Percent signs: %% %% %% End\n");
    b = printf("Percent signs: %% %% %% End\n");
    printf("ft_printf: %d, printf: %d\n\n", a, b);

    // combo stress test
    a = ft_printf("Mix: %s %d %u %x %X %c %p %%\n", "Test", -12345, 4294967295u, 3735928559u, 3735928559u, 'Z', (void*)0xDEADBEEF);
    b = printf("Mix: %s %d %u %x %X %c %p %%\n", "Test", -12345, 4294967295u, 3735928559u, 3735928559u, 'Z', (void*)0xDEADBEEF);
    printf("ft_printf: %d, printf: %d\n\n", a, b);

	ft_printf("INT_MAX: %d\n", INT_MAX);
    ft_printf("INT_MIN: %d\n", INT_MIN);
    ft_printf("UINT_MAX: %u\n", UINT_MAX);
    ft_printf("Zero: %d %u %x\n", 0, 0u, 0u);
    ft_printf("Negative hex: %x\n", -1);
    ft_printf("Pointer NULL: %p\n", NULL);
    ft_printf("Char edge: %c %c\n", 0, 127);
    ft_printf("String empty: '%s'\n", "");
    ft_printf("String NULL: '%s'\n", (char *)NULL);

    return 0;
}
