NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)
INCLUDES = -I ./includes -I  ./libft

LIBFT_DIR = ./libft
LIBFT = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $@ $^

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus:
	$(MAKE) all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT_DIR)/$(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re