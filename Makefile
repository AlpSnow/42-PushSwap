SRC_FILES = push_swap.c \
check_input.c \
functions/ft_atoi_with_validation.c \
functions/ft_split.c \
functions/ft_lstnew.c \
functions/ft_lstadd_back.c \
functions/ft_lstsize.c \
functions/ft_lstclear.c \
instructions/swap.c \
instructions/push.c \
instructions/rotate.c \
instructions/reverse_rotate.c \
algorithm/sorting.c \
algorithm/sorting_helpers.c \
algorithm/target_assignment.c \
algorithm/quickest_move.c \
algorithm/operation_handler.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJFILES = $(SRC_FILES:.c=.o)

NAME = push_swap


all: $(NAME)

$(NAME): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(NAME)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all


.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
