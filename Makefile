NAME = push_swap
NAME_LIBFT = libft/libft.a

INCLUDES_H = -Iinc -Ilibft

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/moves.c src/sort.c \
	src/stack.c src/exit.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(NAME_LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES_H) $(NAME_LIBFT) -o $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_H) -c $< -o $@

$(NAME_LIBFT):
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re