CC =	gcc
NAME =	my_ftl
SRC =	my_putchar.c		\
	my_put_nbr.c		\
	my_putstr.c		\
	my_strdup.c		\
	my_strcmp.c		\
	my_strlen.c		\
	my_putstr_color.c	\
	readline.c		\
	air_shed.c		\
	container.c		\
	system_control.c	\
	system_repair.c		\
	ftl.h			\
	sdl_actions.c		\
	sdl_actions2.c		\
	sdl_actions3.c		\
	loop_choices.c		\
	command_check.c		\
	create_freight.c	\
	get_containers.c	\
	main.c
OBJ =	$(SRC:%.c=%.o)
RM =	rm -f
CFLAGS = -W -Wall -Werror
LDFLAGS = -lSDL -lSDL_image

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

all	:	$(NAME)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	clean
