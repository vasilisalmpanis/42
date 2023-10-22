NAME	=	megaphone
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	megaphone.cpp

OBJ     =	 $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	clang++
INCS	=	megaphone.hpp
all : ${NAME}

${NAME}:	${OBJ}
		${CXX}  ${CFLAGS} ${OBJ} -o ${NAME} -I ${INCS}

%.o: %.c
		${CXX} ${CFLAGS} -c $< -o $@ -I ${INCS}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
