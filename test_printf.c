#include "ft_printf.h"

int main(void)
{
    int a = ft_printf("Hello %s %d %u %x %% %c %p\n", "world", -42, 42u, 255u, 'A', (void*)0x1234);
    int b = printf("Hello %s %d %u %x %% %c %p\n", "world", -42, 42u, 255u, 'A', (void*)0x1234);
    printf("ft_printf returned %d, printf returned %d\n", a, b);
    return 0;
}
