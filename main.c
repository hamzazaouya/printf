#include "ft_printf_bonus.h"

int main(void)
{
	char c;
	ft_printf("|%-5p|\n", &c);
	printf("|%-5p|\n", &c);
}
