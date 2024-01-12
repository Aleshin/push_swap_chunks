CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
HEADER = push_swap.h

SRCS =	push_swap.c stack_functions_1.c helper_functions.c

OBJS = $(SRCS:.c=.o)

%.o:%.c 	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
