SRC = ft_printf.c ft_putptr.c parse.c init.c chk_conv.c\
	reparse.c digits.c utoa.c utohex.c otoa.c chk_mod.c\
	domod.c llitoa.c chk_flag.c chk_prec.c reinit.c
OBJ = $(SRC:%.c = %.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME):
	gcc -c $(SRC) ./libft/*.c
	ar rcs $(NAME) *.o

clean:
	rm -f *.o

fclean:
	rm -f *.o $(NAME)

re:
	make fclean all
