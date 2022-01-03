/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_dgt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:30:13 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/03 16:58:04 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_dcml_len(unsigned long nbr)
{
	int	i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

int ft_get_glblen(int num)
{
	int len;

	if(num < 0)
	{
		len = ft_dcml_len((unsigned int)(-num));
		len++;
	}
	else
		len = ft_dcml_len(num);
	if (strc.plus && num >= 0)
		len++;
	if(strc.dot != -1 && strc.dot > len)
	{
		len = strc.dot;
		if(num < 0)
			len++;
	}
	else if(strc.zero && strc.zero > len)
		len = strc.zero;
	return (len);
}
