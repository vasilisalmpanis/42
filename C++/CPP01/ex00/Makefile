NAME	=	Zombie
CFLAGS	=	-Wall -Wextra -Werror -g -std=c++98
SRCS	=	main.cpp randomChump.cpp Zombie.cpp newZombie.cpp

OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	clang++
INC	=	.

all : ${NAME}

${NAME}:	${OBJ}
		${CXX} ${CFLAGS} ${OBJ}  -I ${INC} -o ${NAME}

%.o: %.c
		${CXX} ${CFLAGS}  -I ${INC} -c $< -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
