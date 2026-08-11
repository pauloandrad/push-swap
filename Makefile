
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
SRCS = src/main.c \
	src/parsing/parse_args.c \
	src/parsing/error_handling.c \
	src/stack/stack_new.c \
	src/stack/stack_push_pop.c \
	src/stack/stack_utils.c \
	src/operations/single/ops_single.c \
	src/operations/ops_combo.c \
	src/disorder/disorder.c \
	src/selector/strategy_selector.c \
	src/algorithms/simple.c \
	src/algorithms/medium.c \
	src/algorithms/complex.c \
	src/algorithms/adaptive.c \
	src/bench/bench.c

OBJ_DIR = obj

OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADER = includes/push_swap.h

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
