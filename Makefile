NAME = push_swap
SRC = argv_checks.c argv_to_list.c do_sorting.c generic_median.c list_checks.c main.c quick_sort.c sort_funcs_1.c sort_funcs_2.c sort_funcs.c \
		sort_helpers.c sort_stack_a.c sort_stack_b.c sort_utils.c
OBJ = $(SRC:.c=.o)
CC = cc
FLAG = -Wall -Werror -Wextra
OPTION = -o

all: $(NAME)

$(NAME):
		$(MAKE) all -C ./libft
		$(CC) $(OPTION) $(NAME) $(FLAG) $(SRC) libft/libft.a

clean: 
		$(MAKE) clean -C ./libft
		rm -f $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)

re:		fclean all

bonus:	all

.PHONY: all bonus clean fclean re