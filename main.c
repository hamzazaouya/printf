#include<stdio.h>

int ft_printf(const char *str, ...);

int main(void)
{
	ft_printf("Hello '%-20.10d' world\n", -123);
	printf("Hello '%-20.10d' world\n", -123);
}
