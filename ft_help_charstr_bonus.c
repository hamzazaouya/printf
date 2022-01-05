/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_charstr_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:25:58 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/05 18:30:44 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar(char c, t_struct *strc)
{
	strc->ctr++;
	write(1, &c, 1);
}

void	ft_print_ch(char c, int len, t_struct *strc)
{
	int	i;

	i = 0;
	while (i++ < len)
		ft_putchar(c, strc);
}

void	ft_putstr(char *str, int len, t_struct *strc)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr("(null)", len, strc);
	else
		while (i < len && str[i])
			ft_putchar(str[i++], strc);
}
