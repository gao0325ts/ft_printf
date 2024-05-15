NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = ft_printf.c \
	detect_conversion.c \
	dispatcher.c \
	printf_c.c \
	printf_s.c \
	printf_p.c \
	printf_d_or_i.c \
	printf_u.c \
	printf_x.c \
	printf_percent.c \
	print_dec.c \
	print_hex.c \
	print_paddings.c \
	count_digits.c	\
	count_len.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT_NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)
	ar rcs $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	make all

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT_DIR)/$(LIBFT_NAME)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re