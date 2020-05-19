SRC = ft_printf.c ft_putptr.c parse.c init.c chk_conv.c reparse.c digits.c utoa.c utohex.c otoa.c chk_flag.c doflag.c llitoa.c
OBJ = ft_printf.o
NAME = libftprintf.a

all: $(NAME)

$(NAME):
	gcc -c $(SRC) ./libft/*.c
	ar rcs $(NAME) *.o

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re:
	make fclean all
