NAME        = libftprintf.a
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = ft_printf.c\
			hex_adress.c\
			ft_printhex.c\
			ft_putstr.c\
			ft_putchar.c\
			ft_putnbr.c\
			ft_putnbr_unsigned.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -x $(LIBFT)
	ar rcs $(NAME) $(OBJS) *.o
	rm -f *.o

%.o: %.c ft_printf.h $(LIBFT_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re