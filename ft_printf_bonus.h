/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:42:35 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/04 21:09:37 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
#define FT_PRINTF_BONUS_H
# include<stdio.h>
#include <stdlib.h>
# include<string.h>
# include<stdarg.h>
# include<unistd.h>
int	g_count;

typedef struct t_struct{
	int minus;
	int plus;
	int hash;
	int space;
	int minfild;
	int zero;
	int dot;
}		t_struct;

t_struct strc;

void	ft_putchar(char c);
void	ft_init(void);
int	ft_get_str(char *str, va_list ptr);
int	ft_printf(const char *str, ...);
void	ft_print_ch(char c, int len);
int	ft_strlen(char *str);
void	ft_putstr(char *str, int len);
void	ft_print_chars(char flag, va_list ptr);
void	ft_print_str(char *str, int len);
void	ft_print_decimal(int num);
void	ft_decimal(va_list ptr);
void	ft_u_decimal(char flag, va_list ptr);
void	ft_putptr(va_list ptr);
unsigned long	ft_get_glblen(unsigned long num, int base, int flag, int sign);
int	ft_dcml_len(unsigned long nbr, int base);
void	ft_putdgt_dots(int dgt_len, unsigned long num);
void	ft_putdgt(unsigned long num, int sign, int base, int alpha);
int	ft_atoi(char *str, int *index);
void	ft_zero_flag(char *str, int *i);
void	ft_other_flag(char c);
void	ft_print_flags(char flag, va_list	ptr);
void	ft_putnbr(unsigned long int nbr, int base, int alpha);
#endif
