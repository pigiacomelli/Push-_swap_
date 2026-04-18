NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

SRCS = main.c \
       parser.c \
       stack.c \
       stack_utils.c \
       index.c \
       algorithm.c \
       sort_small.c \
       chunk_sort.c \
       operations/operations_swap.c \
       operations/operations_push.c \
       operations/operations_rotate.c \
       operations/operations_reverse.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
