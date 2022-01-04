/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:55:11 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/30 14:25:29 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(unsigned long nbr, int base, char c, int *ctr)
{
	if(nbr >= (unsigned long)base)
		ft_putnbr(nbr / base, base, c, ctr);
	if(nbr % base >= 10)
		ft_putchar (nbr % base - 10 + c, ctr);
	else
		ft_putchar(nbr % base + '0', ctr);
}

void	ft_putptr(unsigned long ptr, int *ctr)
{
	ft_putstr("0x", ctr);
	ft_putnbr(ptr, 16, 'a', ctr);
}

void	ft_puthex(unsigned int nbr, int base,  char c, int *ctr)
{
	if(nbr >= (unsigned int)base)
		ft_puthex(nbr / base, base, c, ctr);
	if(nbr % base >= 10)
		ft_putchar (nbr % base - 10 + c, ctr);
	else
		ft_putchar(nbr % base + '0', ctr);
}

void	ft_putdsm(int dsm, int *ctr)
{
	unsigned int nbr;

	nbr = dsm;
	if(dsm < 0)
	{
		ft_putchar('-', ctr);
		nbr = -dsm;
	}
	ft_putnbr(nbr, 10, '0', ctr);
}
