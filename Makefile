NAME = libftprintf.a
SRCM = functions.c printf.c
SRCB =ft_chrstr_bonus.c\
	  ft_decimal_bonus.c\
	  ft_help_dgt_bonus.c\
	  ft_make_dsg_bonus.c\
	  ft_printf_bonus.c ft_help_charstr_bonus.c
CC = cc

CFLAGS = -Wall -Wextra -Werror
OBJM := $(SRCM:.c=.o)
OBJB := $(SRCB:.c=.o)

all : $(NAME)

bonus : $(OBJB) 
	ar -rc  $(NAME) $(OBJB)

$(NAME) : $(OBJM)  
	ar -rc $(NAME) $(OBJM)
clean :
	rm -f $(OBJM) $(OBJB)
fclean: clean
	rm -f $(NAME)
re : fclean all
