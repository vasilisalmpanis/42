NAME	=	ft_ping
SRC	=	main.c \
		error.c \
		handlers.c \
		dns.c \
		checksum.c \
		utils.c

OBJ	=	$(SRC:.c=.o)
RM	=	rm -rf
CC	=	clang
CFLAGS	=	-Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lidn
	setcap cap_net_raw=ep $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
