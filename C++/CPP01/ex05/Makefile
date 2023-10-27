NAME	=	harl
CXXFLAGS	=	-Wall -Wextra -Werror -g -std=c++98 #-fsanitize=address
SRCS	=	main.cpp Harl.cpp

OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	clang++
INC =	.

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
