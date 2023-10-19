NAME	=	Fixed
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp Fixed.cpp Point.cpp bsp.cpp
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