NAME	=	ClapTrap
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
INC		= .
SRCS	=	main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	c++

all : ${NAME}

${NAME}:	${OBJ}
		${CXX} ${CXXFLAGS} -I ${INC} ${OBJ} -o ${NAME}

%.o: %.c
		${CXX} ${CXXFLAGS} -I ${INC} -c $< -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re