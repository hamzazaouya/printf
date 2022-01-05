/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:22:11 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/05 18:32:04 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_make_str(va_list ptr, t_struct *strc)
{
	char	*str;
	int		len;

	str = va_arg(ptr, char *);
	if (!str && strc->dot != -1)
	{
		ft_print_ch(' ', strc->minfild, strc);
		ft_print_str(str, strc->dot, strc);
	}
	else if (!str && strc->dot == -1)
	{
		ft_print_ch(' ', strc->minfild - 6, strc);
		ft_putstr(str, 6, strc);
	}
	else
	{
		len = ft_strlen(str);
		if (strc->dot != -1 && len > strc->dot)
			len = strc->dot;
		ft_print_str(str, len, strc);
	}
}

void	ft_print_chars(va_list ptr, t_struct *strc)
{
	if (strc->flag == 'c')
	{
		if (strc->minus)
			ft_putchar(va_arg(ptr, int), strc);
		ft_print_ch(' ', strc->minfild - 1, strc);
		if (!strc->minus)
			ft_putchar(va_arg(ptr, int), strc);
	}
	else
		ft_make_str(ptr, strc);
}

void	ft_print_str(char *str, int len, t_struct *strc)
{
	int	i;

	i = 0;
	if (strc->minus)
		ft_putstr(str, len, strc);
	while (i++ < (strc->minfild - len))
		ft_putchar(' ', strc);
	if (!strc->minus)
		ft_putstr(str, len, strc);
}
