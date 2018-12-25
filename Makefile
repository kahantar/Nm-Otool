####################################_COLOR_#####################################
GREEN = \033[38;5;10m
GREY = \033[38;5;60m
RED = \033[38;5;9m
END = \033[0m
##################################_COMPILATION_#################################
BIN = -m32
NAME_NM = nm
NAME_OTOOL = otool
CC = clang
FLAG = -Weverything -g
FLAG = -Wall -Wextra -Werror -g
LFT = ./libft/libft.a
SRCS_NM =		ft_nm/srcs/nm.c\
			ft_nm/srcs/handle_64.c\
			ft_nm/srcs/handle_32.c\
			ft_nm/srcs/name_sect_64.c\
			ft_nm/srcs/name_sect_32.c\
			ft_nm/srcs/type.c\
			ft_nm/srcs/handle_fat.c\
			ft_nm/srcs/sort_ascii.c\
			ft_nm/srcs/print_nm.c\
			ft_nm/srcs/ft_itoa_base.c

SRCS_OTOOL =		ft_otool/srcs/otool.c\
			ft_otool/srcs/name_sect_64.c\
			ft_otool/srcs/name_sect_32.c\
			ft_otool/srcs/incrementing.c\
			ft_otool/srcs/handle_fat.c\
			ft_otool/srcs/ft_itoa_base.c

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
	@printf "✅  Compilation nm done.\n"

$(NAME_OTOOL): $(OBJS_OTOOL)
	@make -j8 -s -C ./libft/
	@$(CC) $(FLAG) $(OBJS_OTOOL) -o $(NAME_OTOOL) $(LFT)
	@printf "✅  Compilation otool done.\n"

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
	@printf "✅ nm and otool deleted\n"
	@rm -f $(NAME_NM) $(OBJS_NM)
	@rm -f $(NAME_OTOOL) $(OBJS_OTOOL)
	@make -s fclean -C ./libft/

re: fclean all
