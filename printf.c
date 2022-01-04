/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 08:25:56 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/30 14:25:51 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *ctr)
{
	*ctr = *ctr + 1;
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int *ctr)
{
	int	i;

	if(!str)
	{
		write(1, "(null)", 6);
		*ctr += 6;
		return ;
	}
	i = 0;
	while(str[i])
	{
		ft_putchar(str[i], ctr);
		i++;
	}
}

void	ft_print(char c, int *ctr, va_list arg)
{
	if(c == 'c')
		ft_putchar(va_arg(arg, int), ctr);
	else if(c == 's')
		ft_putstr(va_arg(arg, char *), ctr);
	else if(c == 'p')
		ft_putptr(va_arg(arg, unsigned long), ctr);
	else if(c == 'd' || c == 'i')
		ft_putdsm(va_arg(arg, int), ctr);
	else if(c == 'u')
		ft_putnbr(va_arg(arg, unsigned int), 10, '0',  ctr);
	else if(c == 'x')
		ft_puthex(va_arg(arg, unsigned int), 16, 'a', ctr);
	else if(c == 'X')
		ft_puthex(va_arg(arg, unsigned int), 16, 'A', ctr);
	else if(c == '%')
		ft_putchar ('%', ctr);
}

int	ft_printf(const char *str, ...)
{
	va_list arg;
	int		ctr;

	ctr = 0;
	va_start(arg, str);
	while(*str)
	{
		if(*str == '%')
		{
			ft_print(*(str + 1), &ctr, arg);
			str += 2;
		}
		else
		{
			ft_putchar(*str, &ctr);
			str++;
		}
	}
	return (ctr);
}
/*int main(int ac, char **av)
{
	int a, b;
	char str[] = "XXXX";
	int *ptr = &a;
	int dsm = 125487;
	char c = 'X';
	a = printf("Hello \"%c\" Wrold \"%s\" From \"%p\" morocco \"%d\" and me\n", c, str, ptr, dsm);
	b = ft_printf("Hello \"%c\" Wrold \"%s\" From \"%p\" morocco \"%d\" and me\n", c, str, ptr, dsm);
	printf("%d\n", a);
	printf("%d\n", b);
}*/
