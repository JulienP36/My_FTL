CC =	gcc
NAME =	my_ftl
SRC =	my_putchar.c	\
	my_put_nbr.c	\
	my_putstr.c	\
	my_strdup.c	\
	readline.c	\
	air_shed.c	\
	container.c	\
	ftl.h		\
	main.c
OBJ =	$(SRC:%.c=%.o)
RM =	rm -f
CFLAGS = -W -Wall -Werror

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all	:	$(NAME)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	clean
