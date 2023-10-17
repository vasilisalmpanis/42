NAME	=	Zombie
CFLAGS	=	-Wall -Wextra -Werror -g -std=c++98
SRCS	=	main.cpp randomChump.cpp Zombie.cpp newZombie.cpp

OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CC	=	c++

all : ${NAME}

${NAME}:	${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re