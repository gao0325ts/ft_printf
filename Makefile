NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./ft_printf.h

SRCS = ft_printf.c \
	detect_conversion.c \
	print_args.c \
	ft_printf_c.c \
	ft_printf_s.c \
	ft_printf_p.c \
	ft_printf_d_or_i.c \
	ft_printf_u.c \
	ft_printf_x.c \
	print_hex.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT_NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR) all
	ar rcs $@ $^

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT_DIR)/$(LIBFT_NAME)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re