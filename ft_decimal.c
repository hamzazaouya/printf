#include "ft_printf_bonus.h"

void	ft_print_decimal(int num)
{
	if(num < 0)
	{
		ft_putchar('-');
		ft_putdgt((unsigned) -num, 1, 10, 0);
	}
	else
		ft_putdgt(num, 0, 10, 0);
}

void ft_decimal(va_list ptr)
{
	int len;
	int num;

	num = va_arg(ptr, int);
	if(num >= 0)
		len = (int) ft_get_glblen((unsigned ) num);
	else
	{
		len = (int ) ft_get_glblen((unsigned )-num);
		len++;
	}
	if(strc.minus)
		ft_print_decimal(num);
	if(strc.minfild && !strc.zero)
		ft_print_ch(' ', strc.minfild - len);
	if(!strc.minus)
		ft_print_decimal(num);
}
