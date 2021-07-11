NAME = push_swap

# BONUS = checker

FILES =	ecex.c	exec2.c	instct.c	push_swap.c	sort.c	tools.c	tools2.c	tools3.c

FIL = $(addprefix ./srcs/, $(FILES))

FLAGS = -g #-fsanitize=address -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) $(FIL) -o $(NAME)

fclean :
	rm push_swap

re: fclean all