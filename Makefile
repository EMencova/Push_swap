NAME = push_swap
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -f

SRCS = main.c \
		checks.c \
		errors.c \
		extra_functions.c \
		init_a.c \
		init_nodes_a.c \
		init_nodes_b.c \
		move.c \
		push.c \
		rotate.c \
		reverse.c \
		swap.c \
		sort.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
 
