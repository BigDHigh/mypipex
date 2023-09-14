NAME = libftprintf.a

SRC := ft_printf.c \
	ft_putnbr_hex.c \
	ft_putnbr_ret.c \
	ft_putnbr_unsigned_ret.c \
	ft_putnbr_p.c

OBJ := $(SRC:.c=.o)

CFIL := $(SRC:.c=)
CCFLAGS := -Wall -Wextra -Werror

.PHONY: all bonus clean fclean re

all:$(NAME)

$(NAME): $(OBJ)
	$(MAKE) bonus -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
$(OBJ):
	cc -c $(SRC) $(CCFLAGS)
clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ) $(BNS_OBJ)
fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) 
re: fclean all