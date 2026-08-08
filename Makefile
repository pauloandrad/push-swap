#   VARIABLES
NAME = push_swap

CC = cc

#   add "-g" flag to use gdb
CFLAGS = -Wall -Wextra -Werror -I includes

#   $(wildcard src/*.c)
#   ls | sed 's/\.c/\.c\ \\/'
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

#   Directory where object files will be stored
OBJ_DIR = obj

#   Transforms "src/stack/stack_new.c" -> "obj/stack/stack_new.o"
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADER = includes/push_swap.h

RM = rm -f

#   RULES
#   "My goal is to construct the NAME variable"
#   C looks in the folder: "does $(NAME) exist and is it up-to-date?". If it's
#   not, it goes down to look for a rule that teaches how to create $(NAME)
all: $(NAME)

#   rule that creates $(NAME)
#   "to create $(NAME), i first need all the OBJS
#   (files with the .o extension) to exist"
#
#   Different from ft_printf: there the result was a library, built with
#   "ar rcs". Here the result is an EXECUTABLE, so the compiler itself
#   links the .o files together.
#
#   -L $(LIBFT_DIR)  =  folder where the linker looks for libraries
#   -lft             =  among them, use "libft.a"
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

#   Enters the $(LIBFT_DIR) folder and runs its Makefile
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

#   PATTERN RULE
#   it tells the Makefile how to transform
#   any .c file into a .o file
#
#   "obj/%.o" depends on "src/%.c"
#   It also depends on $(HEADER): editing push_swap.h (a struct, a
#   prototype) rebuilds everything that uses it, instead of leaving
#   objects that no longer match the header.
#
#   -c  =  compile only until the object is generated
#   $<  =  first requirement  =  .c
#   $@  =  target name  =  .o
#   $(@D)  =  only the folder part of $@
#            ("obj/stack/stack_new.o"  ->  "obj/stack")
#
#   src/ has subfolders, so the matching obj/ subfolder needs to exist
#   before the object can be written into it. "mkdir -p" creates the
#   whole path and stays quiet if it is already there.
$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

#   1. Delete the whole obj/ folder (the .o files and its subfolders)
#   2. make enters $(LIBFT_DIR) folder "$(MAKE) -C ..." and executes the "clean"
#   rule of the Makefile for that folder
clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

#   after deleting the .o files, it also deletes
#   the final file
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

#   rebuild everything from scratch
re: fclean all

#   it tells the Makefile that these words
#   (all, clean, etc.) are not filenames,
#   they are rule names
.PHONY: all clean fclean re
