NAME	=	ft_ping
SRC	=	main.c \
		error.c \
		handlers.c \
		dns.c

OBJ	=	$(SRC:.c=.o)
RM	=	rm -rf
CC	=	clang
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	setcap cap_net_raw=ep $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
