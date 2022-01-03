/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:06:12 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/03 16:46:57 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init(void)
{
	strc.minus = 0;
	strc.plus = 0;
	strc.hash = 0;
	strc.space = 0;
	strc.minfild = 0;
	strc.zero = 0;
	strc.dot = -1;
}

int	ft_get_str(char *str, va_list ptr)
{
	int i;

	i = 0;
	while((str[i]	>= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+' ||\
			str[i] == '#' || str[i] == ' ' || str[i] == '.')
	{
		if((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
			ft_zero_flag(str, &i);
		else
			ft_other_flag(str[i]);
		i++;
	}
	if (!i ||str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == ' ')
		i++;
	ft_print_flags(str[--i], ptr);
	return (i + 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;

	g_count = 0;
	va_start(ptr, str);
	while(*str)
	{
		if(*str == '%')
		{
			ft_init();
			str += ft_get_str((char *)str + 1, ptr);
		}
		else
			ft_putchar(*str);
		str++;
	}
	return (g_count);
}
