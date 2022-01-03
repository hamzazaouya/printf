/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_dgt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:30:13 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/03 21:30:14 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

unsigned long ft_get_glblen(unsigned long num)
{
	unsigned long len;

	len = ft_dcml_len(num);
	if(strc.dot != -1 && strc.dot > len)
	{
		len = strc.dot;
		if(num < 0)
			len++;
	}
	else if(strc.zero && strc.zero > len)
		len = strc.zero;
	if (strc.plus && num >= 0)
		len++;
	return (len);
}
