NAME	=	Fixed
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp Fixed.cpp
OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	clang++

all : ${NAME}

${NAME}:	${OBJ}
		${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

%.o: %.cpp
		${CXX} ${CXXFLAGS} -c $< -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
