/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_dgt1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:19:22 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/04 22:49:14 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

unsigned long	ft_get_glblen(unsigned long num, int base, int flag, int sign)
{
	unsigned long	len;

	len = ft_dcml_len(num, base);
	if (strc.dot != -1 && strc.dot > (int) len)
		len = strc.dot;
	else if (strc.zero && strc.zero > (int) len)
		len = strc.zero;
	if ((strc.plus && !sign && (flag != 'a' || flag != 'A')) || strc.space)
		len++;
	if (((flag == 'A' || flag == 'a') && strc.hash && num) || flag == 'p')
		len += 2;
	return (len);
}

int	ft_dcml_len(unsigned long nbr, int base)
{
	int	i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr > 0)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

void	ft_putdgt_dots(int dgt_len, unsigned long num)
{
	if (!strc.dot && !num && !strc.minfild)
		return ;
	else if (strc.dot > 0)
		ft_print_ch('0', strc.dot - dgt_len);
}

void	ft_putdgt_zeros(int dgt_len, int sign, int flag)
{
	if (sign && (flag == 'd' || flag == 'i'))
		ft_print_ch('0', strc.zero - dgt_len - 1);
	else
		ft_print_ch('0', strc.zero - dgt_len);
}

void	ft_putdgt(unsigned long num, int sign, int base, int alpha)
{
	int	dgt_len;

	dgt_len = ft_dcml_len(num, base);
	
	if (alpha == 'A' && strc.hash && num)
		ft_putstr("0X", 2);
	else if ((alpha == 'a' && strc.hash && num) || alpha == 'p')
		ft_putstr("0x", 2);
	if ((!strc.dot && !num && strc.minfild) || (strc.space && !sign))
		ft_putchar(' ');
	else if (!sign && strc.plus)
		ft_putchar('+');
	if (strc.dot > -1)
		ft_putdgt_dots(dgt_len, num);
	else if (strc.zero)
	{
		if (sign)
			dgt_len++;
		ft_putdgt_zeros(dgt_len, sign, alpha);
	}
	if (!(!strc.dot && !num))
		ft_putnbr(num, base, alpha);
}
