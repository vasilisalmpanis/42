NAME	=	Bank
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	Account.cpp tests.cpp

INCS	=	Account.hpp
OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	clang++

all : ${NAME}

${NAME}:	${OBJ}
		${CXX} ${CFLAGS} ${OBJ} -I ${INCS} -o ${NAME}

%.o: %.cpp
		${CXX} ${CFLAGS} -I ${INCS} -c $< -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
