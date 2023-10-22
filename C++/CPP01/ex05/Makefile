NAME	=	harl
CFLAGS	=	-Wall -Wextra -Werror -g -std=c++98 #-fsanitize=address
SRCS	=	main.cpp Harl.cpp

OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	c++
INC =	.

all : ${NAME}

${NAME}:	${OBJ}
		${CXX} ${CFLAGS} -I ${INC} ${OBJ} -o ${NAME}

%.o: %.c
		${CXX} ${CFLAGS} -I ${INC} -c $< -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re