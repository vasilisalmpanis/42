NAME	=	ft_traceroute
SRC	=	main.c \
		utils.c \

OBJ	=	$(SRC:.c=.o)
RM	=	rm -rf
CC	=	clang

INC	=	ft_traceroute.h \
		defines.h

CFLAGS	=	-Wall -Wextra -Werror -g

all: libft $(NAME) 

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lidn -L./libft -lft
	setcap cap_net_raw=ep $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@if [ ! -d "./libft" ]; then	\
		tar -xf ./libft.tar;	\
	fi
	make -C libft/
	make bonus -C libft/

libft-fclean:
	make fclean -C ./libft 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

clang-format:
	clang-format -i $(SRC) $(INC)

re: fclean all

.PHONY: all clean fclean re
