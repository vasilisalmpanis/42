NAME	=	ClapTrap
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp ClapTrap.cpp
OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	clang++

all : ${NAME}

${NAME}:	${OBJ}
		${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

%.o: %.c %.h
		${CXX} ${CXXFLAGS} -c $< -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
