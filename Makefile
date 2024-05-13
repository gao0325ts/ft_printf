NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = ft_printf.c \
	detect_conversion.c \
	dispatcher.c \
	ft_printf_c.c \
	ft_printf_s.c \
	ft_printf_p.c \
	ft_printf_d_or_i.c \
	ft_printf_u.c \
	ft_printf_x.c \
	print_dec.c \
	print_hex.c \
	print_paddings.c \
	count_digits.c

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

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT_DIR)/$(LIBFT_NAME)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re