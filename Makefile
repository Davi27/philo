NAME	=	philo

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -pthread -g

SRC		=	main.c init.c utils.c \
				threads.c actions.c

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean	:
			@rm -rf $(OBJ)

fclean	:	clean
			@rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re