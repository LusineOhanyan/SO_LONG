NAME	=	so_long

CC		=	CC

CFLAGS	=	-Wall -Wextra -Werror -g -ggdb3

RM		=	-rm -f

SOURCE	=	$(wildcard *.c)

OBJECT	=	$(SOURCE:.c=.o)

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJECT)
			$(CC) -lmlx -framework OpenGL -framework AppKit $(OBJECT) -o $(NAME)

clean:
			$(RM) $(OBJECT)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

