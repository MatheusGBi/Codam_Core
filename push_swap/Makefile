NAME        = push_swap
FT_PRINTF_DIR   = ft_printf
FT_PRINTF      = $(FT_PRINTF_DIR)/libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = push_swap.c\
				push_swap_utils.c\
				push_validity_check.c\
				push_swap_ab_ss_rr.c\
				push_swap_ab_rrr.c\
				push_swap_b.c\
				push_swap_a.c\
				push_swap_simple.c\
				push_swap_bench.c\
				push_swap_stack.c\
				push_swap_medium.c\
				push_swap_utils2.c\
				push_swap_adaptive.c\
				push_swap_utils3.c\
				push_swap_complex.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME) 
	rm -f *.o

%.o: %.c push_swap.h $(FT_PRINTF_DIR)/printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

# debug: $(FT_PRINTF)	figure out how to solve
# 	$(CC) $(CFLAGS) -g $(FT_PRINTF)

.PHONY: all clean fclean re