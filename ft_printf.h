/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:10:20 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/05 14:04:47 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdio.h>
# include<string.h>
# include<stdarg.h>
# include<unistd.h>

void	ft_putchar(char c, int *ctr);
void	ft_putstr(char *str, int *ctr);
int		ft_printf(const char *str, ...);
void	ft_putnbr(unsigned long nbr, int base, char c, int *ctr);
void	ft_puthex(unsigned int nbr, int base, char c, int *ctr);
void	ft_putptr(unsigned long ptr, int *ctr);
void	ft_putdsm(int dsm, int *ctr);
#endif
