/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funs1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:42:38 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/05 19:33:06 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_atoi(char *str, int *index)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	*index += i;
	return (nb);
}

void	ft_zero_flag(char *str, int *i, t_struct *strc)
{
	int	nb;

	nb = 0;
	if (str[*i] == '0')
	{
		nb = ft_atoi(str + (*i), i);
		if (str[*i] == '.')
		{
			strc->minfild = nb;
			strc->dot = ft_atoi(str + (++(*i)), i);
		}
		else
			strc->zero = nb;
	}
	else if (str[*i] == '.')
		strc->dot = ft_atoi(str + (++(*i)), i);
	else
	{
		strc->minfild = ft_atoi(str + *i, i);
		if (str[*i] == '.')
			strc->dot = ft_atoi(str + (++(*i)), i);
	}
}

void	ft_other_flag(char c, t_struct *strc)
{
	if (c == '-')
		strc->minus = 1;
	else if (c == '+')
		strc->plus = 1;
	else if (c == '#')
		strc->hash = 1;
	else if (c == ' ')
		strc->space = 1;
}

void	ft_print_flags(va_list	ptr, t_struct *strc)
{
	if (strc->flag == 's' || strc->flag == 'c')
		ft_print_chars(ptr, strc);
	else if (strc->flag == 'd' || strc->flag == 'i')
		ft_decimal(ptr, strc);
	else if (strc->flag == 'x' || strc->flag == 'X' || strc->flag == 'u')
		ft_u_decimal(ptr, strc);
	else if (strc->flag == 'p')
		ft_putptr(ptr, strc);
}

void	ft_putnbr(unsigned long int nbr, t_struct *strc)
{
	if (nbr >= (unsigned long int) strc->base)
		ft_putnbr(nbr / strc->base, strc);
	if (nbr % strc->base >= 10)
		ft_putchar (nbr % strc->base - 10 + strc->alpha, strc);
	else
		ft_putchar(nbr % strc->base + '0', strc);
}
