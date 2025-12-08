CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -I$(PRINTF_DIR)
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf


SRC = main.c push.c rotate.c swap.c
OBJ = $(SRC:.c=.o)


LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
NAME = push_swap


all: $(NAME)


$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean


re: fclean all

.PHONY: all clean fclean re
