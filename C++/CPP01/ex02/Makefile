NAME	=	brain
CFLAGS	=	-Wall -Wextra -Werror -g -std=c++98 #-fsanitize=address
SRCS	=	main.cpp

OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	c++

all : ${NAME}

${NAME}:	${OBJ}
		${CXX} ${CFLAGS} ${OBJ} -o ${NAME}

%.o: %.c
		${CXX} ${CFLAGS} -c $< -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re