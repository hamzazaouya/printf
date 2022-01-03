#include "ft_printf_bonus.h"

void ft_decimal(va_list ptr)
{
	int len;
	int num;

	num = va_arg(ptr, int);
	len = ft_get_glblen(num);
	if(strc.minus)
	{
		if(num < 0)
		{
			ft_putchar('-');
			ft_putdgt((unsigned) -num, 1);
		}
		else
			ft_putdgt(num, 0);
	}
	if(strc.minfild && !strc.zero)
		ft_print_ch(' ', strc.minfild - len);
	if(!strc.minus)
	{
		if(num < 0)
		{
			ft_putchar('-');
			ft_putdgt((unsigned) -num, 1);
		}
		else
			ft_putdgt(num, 0);
	}
}
