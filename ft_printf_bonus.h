/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:10:20 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/03 16:57:13 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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

int		ft_printf(const char *str, ...);
int		ft_atoi(char *str, int *index);
void	ft_zero_flag(char *str, int *i);
void	ft_other_flag(char c);
void	ft_print_flags(char flag, va_list	ptr);
void	ft_print_chars(char flag, va_list ptr);
void	ft_print_str(char *str, int len);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int len);
void	ft_putchar(char c);
void	ft_print_ch(char c, int len);
int		ft_get_glblen(int num);
void	ft_decimal(va_list ptr);
void	ft_putnbr(unsigned long int nbr, int base, int alpha);
void	ft_putdgt(unsigned long num, int flag);
int		ft_dcml_len(unsigned long nbr);
void	ft_check_sign(int num);
void	ft_putdgt_dots(int dgt_len, int num);
void	ft_putdgt_zeros(int dgt_len, int flag);
#endif
