/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:42:35 by hazaouya          #+#    #+#             */
/*   Updated: 2022/01/05 19:31:08 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include<stdio.h>
# include <stdlib.h>
# include<string.h>
# include<stdarg.h>
# include<unistd.h>

typedef struct t_struct{
	int	minus;
	int	plus;
	int	hash;
	int	space;
	int	minfild;
	int	zero;
	int	dot;
	int flag;
	int sign;
	int base;
	int ctr;
	int alpha;
}		t_struct;

void	ft_putchar(char c, t_struct *strc);
void	ft_print_ch(char c, int len, t_struct *strc);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int len, t_struct *strc);
void	ft_print_chars(va_list ptr, t_struct *strc);
void	ft_print_str(char *str, int len, t_struct *strc);
void	ft_print_decimal(int num, t_struct *strc);
void	ft_decimal(va_list ptr, t_struct *strc);
void	ft_u_decimal(va_list ptr, t_struct *strc);
void	ft_putptr(va_list ptr, t_struct *strc);
int		ft_get_glblen(unsigned long num, t_struct *strc);
int		ft_dcml_len(unsigned long nbr, int base);
void	ft_putdgt_dots(int dgt_len, unsigned long num, t_struct *strc);
void	ft_putdgt(unsigned long num, t_struct *strc);
void	ft_zero_flag(char *str, int *i, t_struct *strc);
void	ft_other_flag(char c, t_struct *strc);
void	ft_print_flags(va_list	ptr, t_struct *strc);
void	ft_putnbr(unsigned long int nbr, t_struct *strc);
#endif
