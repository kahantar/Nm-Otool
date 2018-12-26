####################################_COLOR_#####################################
GREEN = \033[38;5;10m
GREY = \033[38;5;60m
RED = \033[38;5;9m
END = \033[0m
##################################_COMPILATION_#################################
BIN = -m32
NAME_NM = ft_nm
NAME_OTOOL = ft_otool
CC = clang
FLAG = -Weverything -g
FLAG = -Wall -Wextra -Werror -g
LFT = ./libft/libft.a
SRCS_NM =		nm/srcs/nm.c\
			nm/srcs/handle_64.c\
			nm/srcs/handle_32.c\
			nm/srcs/name_sect_64.c\
			nm/srcs/name_sect_32.c\
			nm/srcs/type.c\
			nm/srcs/handle_fat.c\
			nm/srcs/sort_ascii.c\
			nm/srcs/print_nm.c\
			nm/srcs/ft_itoa_base.c

SRCS_OTOOL =		otool/srcs/otool.c\
			otool/srcs/name_sect_64.c\
			otool/srcs/name_sect_32.c\
			otool/srcs/incrementing.c\
			otool/srcs/handle_fat.c\
			otool/srcs/ft_itoa_base.c

OBJS_NM = $(SRCS_NM:.c=.o)

OBJS_OTOOL = $(SRCS_OTOOL:.c=.o)

INCLUDE = -I ./include \
          -I ./libft
###########################_RELINK_MODIFY_.h####################################
RELINK = ./include/malloc.h
################################################################################


all: $(NAME_NM) $(NAME_OTOOL)

$(NAME_NM): $(OBJS_NM)
	@make -j8 -s -C ./libft/
	@$(CC) $(FLAG) $(OBJS_NM) -o $(NAME_NM) $(LFT)
	@printf "✅  Compilation ft_nm done.\n"

$(NAME_OTOOL): $(OBJS_OTOOL)
	@make -j8 -s -C ./libft/
	@$(CC) $(FLAG) $(OBJS_OTOOL) -o $(NAME_OTOOL) $(LFT)
	@printf "✅  Compilation ft_otool done.\n"

%.o : %.c $(RELINK)
	@printf " ✅                                                              \r"
	@printf "✅  $(notdir $<)\r"
	@$(CC) -c $(FLAG) $< -o $@ $(INCLUDE)

clean:
	@printf "                                                               \r"
	@printf "✅  all .o deleted\n"
	@rm -f $(OBJS_NM)
	@rm -f $(OBJS_OTOOL)
	@make -s clean -C ./libft/

fclean:
	@printf "                                                               \r"
	@printf "✅ ft_nm and ft_otool deleted\n"
	@rm -f $(NAME_NM) $(OBJS_NM)
	@rm -f $(NAME_OTOOL) $(OBJS_OTOOL)
	@make -s fclean -C ./libft/

re: fclean all
