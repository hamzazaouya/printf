/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funs1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:42:38 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/03 15:25:28 by hazaouya         ###   ########.fr       */
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

void	ft_zero_flag(char *str, int *i)
{
	int	nb;

	nb = 0;
	if (str[*i] == '0')
	{
		nb = ft_atoi(str + (*i), i);
		if (str[*i] == '.')
		{
			strc.minfild = nb;
			strc.dot = ft_atoi(str + (++(*i)), i);
		}
		else
			strc.zero = nb;
	}
	else if (str[*i] == '.')
		strc.dot = ft_atoi(str + (++(*i)), i);
	else
	{
		strc.minfild = ft_atoi(str + *i, i);
		if (str[*i] == '.')
			strc.dot = ft_atoi(str + (++(*i)), i);
	}
}

void	ft_other_flag(char c)
{
	if (c == '-')
		strc.minus = 1;
	else if (c == '+')
		strc.plus = 1;
	else if (c == '#')
		strc.hash = 1;
	else if (c == ' ')
		strc.space = 1;
}

void	ft_print_flags(char flag, va_list	ptr)
{
	if (flag == 's' || flag == 'c')
		ft_print_chars(flag, ptr);
	else if (flag == 'd' || flag == 'i')
		ft_decimal(ptr);
	/*else if (c == 'x' || c == 'X' || c == 'u')
		ft_unsigned(c, ptr);
	else if (c == 'p')
		ft_address(ptr);*/
}
