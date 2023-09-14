NAME = pipex

SRC := main.c \
		ft_check_command_and_get_path.c \
		utils.c \
		ft_special_split.c \
		errors.c \
		ft_get_command_arg_array.c

BNS_SRC := main_bonus.c \
		ft_check_command_and_get_path.c \
		utils.c \
		ft_special_split.c \
		errors.c \
		ft_get_command_arg_array.c

OBJ := $(SRC:.c=.o)

BNS_OBJ := $(BNS_SRC:.c=.o)

#CFIL := $(SRC:.c=)
#CCFLAGS := -Wall -Wextra -Werror
#CCFLAGS := -g -fsanitize=address
CCFLAGS := -g
.PHONY: all bonus clean fclean re

all:$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./ft_printf
	 cc $(CCFLAGS) $(OBJ) ./ft_printf/libftprintf.a -o $(NAME)
$(OBJ):
	cc -c $(SRC) $(CCFLAGS)
bonus: $(BNS_OBJ)
	$(MAKE) -C ./ft_printf
	 cc $(CCFLAGS) $(BNS_OBJ) ./ft_printf/libftprintf.a -o $(NAME)
$(BNS_OBJ):
	cc -c $(BNS_SRC) $(CCFLAGS)

clean:
	$(MAKE) clean -C ./ft_printf
	rm -f $(OBJ) $(BNS_OBJ)
fclean: clean
	$(MAKE) fclean -C ./ft_printf
	rm -f $(NAME) 
re: fclean all
rebonus: fclean bonus