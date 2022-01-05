/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:15:43 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/05 13:09:21 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_decimal(int num)
{
	if (num < 0)
	{
		ft_putchar('-');
		ft_putdgt((unsigned) -num, 1, 10, 0);
	}
	else
		ft_putdgt(num, 0, 10, 0);
}

void	ft_decimal(va_list ptr)
{
	int	len;
	int	num;

	num = va_arg(ptr, int);
	if (num >= 0)
		len = (int) ft_get_glblen((unsigned ) num, 10, 0, 0);
	else
	{
		len = (int ) ft_get_glblen((unsigned )-num, 10, 0, 1);
		len++;
	}
	if (strc.minus)
		ft_print_decimal(num);
	if (strc.minfild && !strc.zero)
		ft_print_ch(' ', strc.minfild - len);
	if (!strc.minus)
		ft_print_decimal(num);
}

void	ft_u_decimal(char flag, va_list ptr)
{
	int				len;
	unsigned int	num;
	int				base;

	if (flag == 'u')
		base = 10;
	else
		base = 16;
	if (flag == 'x')
		flag = 'a';
	else if (flag == 'X')
		flag = 'A';
	num = va_arg(ptr, unsigned int);
	len = ft_get_glblen(num, base, flag, 0);
	if (strc.minus)
		ft_putdgt(num, 0, base, flag);
	if (strc.minfild && !strc.zero)
		ft_print_ch(' ', strc.minfild - len);
	if (!strc.minus)
		ft_putdgt(num, 0, base, flag);
}

void	ft_putptr(va_list ptr)
{
	unsigned long	num;
	int				len;

	num = va_arg(ptr, unsigned long);
	len = ft_get_glblen(num, 16, 'p', 0);
	if (strc.minus)
		ft_putdgt(num, 0, 16, 'p');
	if (strc.minfild && !strc.zero)
		ft_print_ch(' ', strc.minfild - len);
	if (!strc.minus)
		ft_putdgt(num, 0, 16, 'p');
}
