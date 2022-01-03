/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_dgt1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:19:22 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/03 16:57:28 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr(unsigned long int nbr, int base, int alpha)
{
	if (nbr >= (unsigned long int)base)
		ft_putnbr(nbr / base, base, alpha);
	if ((nbr % base) >= 10)
		ft_putchar((nbr % base) + alpha);
	else
		ft_putchar((nbr % base) + '0');
}

void	ft_check_sign(int num)
{
	if(num < 0)
		ft_putnbr((unsigned) -num, 10, 0);
	else
		ft_putnbr(num, 10, 0);
}

void	ft_putdgt_dots(int dgt_len, int num)
{
	if(!strc.dot && !num && !strc.minfild)
		return ;
	else if(strc.dot > 0)
		ft_print_ch('0', strc.dot - dgt_len);
}

void ft_putdgt_zeros(int dgt_len, int flag)
{
	if(flag)
		ft_print_ch('0', strc.zero - dgt_len - 1);
	else
		ft_print_ch('0', strc.zero - dgt_len);
}

void	ft_putdgt(unsigned long num, int flag)
{
	int dgt_len;

	dgt_len = ft_dcml_len(num);
	if(!strc.dot && !num && strc.minfild)
		ft_putchar(' ');
	if(!flag && strc.plus)
		ft_putchar('+');
	if(strc.dot > -1)
	ft_putdgt_dots(dgt_len, num);
	else if(strc.zero)
		ft_putdgt_zeros(dgt_len, flag);
	if(!strc.dot  && !num)
		return ;
	else
		ft_check_sign(num);
}
