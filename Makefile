####################################_COLOR_#####################################
GREEN = \033[38;5;10m
GREY = \033[38;5;60m
RED = \033[38;5;9m
END = \033[0m
##################################_COMPILATION_#################################
NAME = nm
CC = clang
FLAG = -Weverything -g
FLAG = -Wall -Wextra -Werror -g
LFT = ./libft/libft.a
SRCS =		srcs/nm.c\
		srcs/handle_64.c\
		srcs/name_sect_64.c\
		srcs/type.c\
		srcs/handle_fat.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -I ./include \
          -I ./libft
###########################_RELINK_MODIFY_.h####################################
RELINK = ./include/malloc.h
################################################################################


all: $(NAME)

$(NAME): $(OBJS)
	@make -j8 -s -C ./libft/
	@$(CC) $(FLAG) $(OBJS) -o $(NAME) $(LFT)
	@printf "✅  Compilation done.\n"

%.o : %.c $(RELINK)
	@printf " ✅                                                              \r"
	@printf "✅  $(notdir $<)\r"
	@$(CC) -c $(FLAG) $< -o $@ $(INCLUDE)

clean:
	@printf "                                                               \r"
	@printf "✅  all .o deleted\n"
	@rm -f $(OBJS)
	@make -s clean -C ./libft/

fclean:
	@printf "                                                               \r"
	@printf "✅ nm deleted\n"
	@rm -f $(NAME) $(OBJS)
	@make -s fclean -C ./libft/

re: fclean all
