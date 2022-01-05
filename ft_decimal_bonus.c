/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:15:43 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/05 20:20:18 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_decimal(int num, t_struct *strc)
{
	if (num < 0)
	{
		ft_putchar('-', strc);
		ft_putdgt((unsigned int) -num, strc);
	}else
		ft_putdgt(num, strc);
}

void	ft_decimal(va_list ptr, t_struct *strc)
{
	int	len;
	int	num;

	num = va_arg(ptr, int);
	if (num >= 0)
		len = (int) ft_get_glblen((unsigned ) num, strc);
	else
	{
		strc->sign = 1;
		len = (int ) ft_get_glblen((unsigned )-num, strc);
		len++;
	}
	if (strc->minus)
		ft_print_decimal(num, strc);
	if (strc->minfild && !strc->zero)
		ft_print_ch(' ', strc->minfild - len, strc);
	if (!strc->minus)
		ft_print_decimal(num, strc);
}

void	ft_u_decimal(va_list ptr, t_struct *strc)
{
	int				len;
	unsigned int	num;

	num = va_arg(ptr, unsigned int);
	len = ft_get_glblen(num, strc);
	if (strc->minus)
		ft_putdgt(num, strc);
	if (strc->minfild && !strc->zero)
		ft_print_ch(' ', strc->minfild - len, strc);
	if (!strc->minus)
		ft_putdgt(num, strc);
}

void	ft_putptr(va_list ptr, t_struct *strc)
{
	unsigned long	num;
	int				len;

	num = va_arg(ptr, unsigned long);
	len = ft_get_glblen(num, strc);
	if (strc->minus)
		ft_putdgt(num, strc);
	if (strc->minfild && !strc->zero)
		ft_print_ch(' ', strc->minfild - len, strc);
	if (!strc->minus)
		ft_putdgt(num, strc);
}
