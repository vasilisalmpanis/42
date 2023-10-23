NAME	=	violence
CXXFLAGS	=	-Wall -Wextra -Werror -g -std=c++98 #-fsanitize=address
SRCS	=	main.cpp Weapon.cpp HumanA.cpp  HumanB.cpp

OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	c++
INC	=	.

all : ${NAME}

${NAME}:	${OBJ}
		${CXX} ${CXXFLAGS} -I ${INC} ${OBJ} -o ${NAME}

%.o: %.c
		${CXX} ${CXXFLAGS} -I ${INC}-c $< -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
