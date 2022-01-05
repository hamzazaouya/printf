/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:06:12 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/05 19:26:00 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init(t_struct *strc)
{
	strc->minus = 0;
	strc->plus = 0;
	strc->hash = 0;
	strc->space = 0;
	strc->minfild = 0;
	strc->zero = 0;
	strc->dot = -1;
	strc->flag = 0;
	strc->sign = 0;
	strc->base = 10;
	strc->alpha = 0;
}

void	ft_get_flag(char flag, t_struct *strc)
{
	if(flag == 'd')
		strc->flag = 'd';
	else if(flag == 'i')
		strc->flag = 'i';
	else if(flag == 's')
		strc->flag = 's';
	else if(flag == 'c')
		strc->flag = 'c';
	else if(flag == 'x')
		strc->flag = 'x';
	else if(flag == 'X')
		strc->flag = 'X';
	else if(flag == 'u')
		strc->flag = 'u';
	else if(flag == 'p')
		strc->flag = 'p';
	if(flag == 'x' || flag == 'X' || flag == 'p')
		strc->base = 16;
	if(flag == 'x' || strc->flag == 'p')
		strc->alpha = 'a';
	if(flag == 'X')
		strc->alpha = 'A';
}

int	ft_get_str(char *str, va_list ptr, t_struct *strc)
{
	int	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || \
				str[i] == '+' || str[i] == '#' || str[i] == ' ' || \
				str[i] == '.')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
			ft_zero_flag(str, &i, strc);
		else
			ft_other_flag(str[i++], strc);
	}
	ft_get_flag(str[i],  strc);
	ft_print_flags(ptr, strc);
	return (i + 1);
}

int	ft_printf(const char *str, ...)
{
	va_list		ptr;
	t_struct	strc;

	strc.ctr = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			ft_init(&strc);
			str += ft_get_str((char *)str + 1, ptr, &strc);
			if (*(str - 1) == '%' && *(str) == '%')
				ft_putchar(*str, &strc);
		}
		else
			ft_putchar(*str, &strc);
		str++;
	}
	return (strc.ctr);
}
