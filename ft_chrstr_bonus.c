/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:22:11 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/04 18:28:58 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_ch(char c, int len)
{
	int	i;

	i = 0;
	while (i++ < len)
		ft_putchar(c);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int len)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr("(null)", len);
	else
		while (i < len && str[i])
			ft_putchar(str[i++]);
}

void	ft_print_chars(char flag, va_list ptr)
{
	int		len;
	char	*str;

	if (flag == 'c')
		ft_putchar(va_arg(ptr, int));
	else
	{
		str = va_arg(ptr, char *);
		if (!str && strc.dot != -1)
		{
			ft_print_ch(' ', strc.minfild);
			ft_print_str(str, strc.dot);
		}
		else if (!str && strc.dot == -1)
			ft_putstr(str, 0);
		else
		{
			len = ft_strlen(str);
			if (strc.dot != -1 && len > strc.dot)
				len = strc.dot;
			ft_print_str(str, len);
		}
	}
}

void	ft_print_str(char *str, int len)
{
	int	i;

	i = 0;
	if (strc.minus)
		ft_putstr(str, len);
	while (i++ < (strc.minfild - len))
		ft_putchar(' ');
	if (!strc.minus)
		ft_putstr(str, len);
}
