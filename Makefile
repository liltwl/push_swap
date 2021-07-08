NAME = push_swap

# BONUS = checker

FILES = pushtest1.c

FLAGS = -g #-fsanitize=address -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) $(FILES) -o $(NAME)

fclean :
	rm push_swap

re: fclean all