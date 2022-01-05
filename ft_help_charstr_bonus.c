/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_charstr_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:25:58 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/05 14:12:20 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar(char c)
{
	g_count++;
	write(1, &c, 1);
}

void	ft_print_ch(char c, int len)
{
	int	i;

	i = 0;
	while (i++ < len)
		ft_putchar(c);
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
