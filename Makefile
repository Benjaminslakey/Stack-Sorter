SORTER_FILES= 	sources/push_swap.c \
			  	sources/pswap_input.c \
			  	sources/pswap_output.c \
			  	sources/stack_basic.c \
				sources/stack_utility.c \
			  	sources/stack_ops.c \
			  	sources/instructions.c \
			  	sources/instructions2.c \
			  	sources/instructions3.c \
			  	sorter/selection_sort.c \
			  	sorter/insertion_sort.c \
			  	sorter/bubble_sort.c \
				sorter/sort_trip.c \
				sorter/stack_sorting_helpers.c \

CHECKER_FILES=  check/checker.c \
				check/instructions.c \
				gnl/get_next_line.c \
				sources/pswap_input.c \
				sources/pswap_output.c \
				sources/stack_utility.c \
				sources/stack_basic.c \
				sources/stack_ops.c \
				sources/instructions.c \
				sources/instructions2.c \
				sources/instructions3.c \

LIBFT= libft.a

CFLAGS= -Wall -Wextra -Werror

HEADER= -I./push_swap

LIBLINK= -L./libft

NAME= push_swap

CHECKER= checker

.PHONY: test all clean fclean re

all: $(NAME) $(CHECKER)

$(NAME): $(LIBFT) $(SORTER_FILES)
	gcc $(CFLAGS) $(LIBLINK) -o $(NAME) $(SORTER_FILES) $(LIBFT)

$(CHECKER): $(LIBFT) $(CHECKER_FILES)
	gcc $(CFLAGS) $(LIBLINK) -o $(CHECKER) $(CHECKER_FILES) $(LIBFT)

$(LIBFT):
	make -C libft
	mv libft/$(LIBFT) .

clean:
	make clean -C libft
	rm -rf libft.a

fclean: clean
	rm -rf $(NAME)
	rm -rf $(CHECKER)

re: fclean all
