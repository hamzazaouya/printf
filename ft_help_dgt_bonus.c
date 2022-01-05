/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_dgt1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:19:22 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/05 20:20:15 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_get_glblen(unsigned long num, t_struct *strc)
{
	int	len;

	len = ft_dcml_len(num, strc->base);
	if (strc->dot != -1 && strc->dot > (int) len)
		len = strc->dot;
	else if (strc->zero && strc->zero > (int) len)
		len = strc->zero;
	if ((strc->plus && !strc->sign && (strc->flag != 'x' || \
					strc->flag != 'X')) || strc->space)
		len++;
	if (((strc->flag == 'X' || strc->flag == 'x') && strc->hash && num) || \
		   	strc->flag == 'p')
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

void	ft_putdgt_dots(int dgt_len, unsigned long num, t_struct *strc)
{
	if (!strc->dot && !num && !strc->minfild)
		return ;
	else if (strc->dot > 0)
		ft_print_ch('0', strc->dot - dgt_len, strc);
}

void	ft_putdgt_zeros(int dgt_len, t_struct *strc)
{
	if (strc->sign && (strc->flag == 'd' || strc->flag == 'i'))
		ft_print_ch('0', strc->zero - dgt_len - 1, strc);
	else
		ft_print_ch('0', strc->zero - dgt_len, strc);
}

void	ft_putdgt(unsigned long num, t_struct *strc)
{
	int	dgt_len;

	dgt_len = ft_dcml_len(num, strc->base);
	if (strc->alpha == 'A' && strc->hash && num)
		ft_putstr("0X", 2, strc);
	else if ((strc->alpha == 'a' && strc->hash && num) || strc->flag == 'p')
		ft_putstr("0x", 2, strc);
	if ((!strc->dot && !num && strc->minfild) || (strc->space && !strc->sign))
		ft_putchar(' ', strc);
	else if (!strc->sign && strc->plus)
		ft_putchar('+', strc);
	if (strc->dot > -1)
		ft_putdgt_dots(dgt_len, num, strc);
	else if (strc->zero)	
		ft_putdgt_zeros(dgt_len, strc);
	if (!(!strc->dot && !num))
		ft_putnbr(num, strc);
}
