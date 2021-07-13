NAME = push_swap

BONUS = checker

FILES =	ecex.c	exec2.c	instct.c	push_swap.c	sort.c	tools.c	tools2.c	tools3.c

CHEK =	checker.c	cheker_tools.c	sort.c	tools.c	tools2.c	tools3.c	ecex.c	exec2.c	instct.c	get_next_line.c

CHEK_ = $(addprefix ./srcs/, $(CHEK))

FIL = $(addprefix ./srcs/, $(FILES))

OBJ = $(FIL:.c=.o)

FLAGS = -g -O3 -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(FIL)
	gcc $(FLAGS) $(FIL) -o $(NAME)

bonus :	$(BONUS)

$(BONUS) : $(CHEK_)
	gcc $(FLAGS) $(CHEK_)  -o $(BONUS)

fclean :
	rm  $(NAME) $(BONUS)

re: fclean all 

me:
	@echo $(NAME)
	@echo "#    #  ####   ####  #####   #    #  ####   ####  #####  "
	@echo "##   # #    # #    # #    #  ##   # #    # #    # #    # "
	@echo "# #  # #    # #    # #####   # #  # #    # #    # #####  "
	@echo "#  # # #    # #    # #    #  #  # # #    # #    # #    # "
	@echo "#   ## #    # #    # #    #  #   ## #    # #    # #    # "
	@echo "#    #  ####   ####  #####   #    #  ####   ####  #####  "
