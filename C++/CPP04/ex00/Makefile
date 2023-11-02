NAME	=	Animal	
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp	
OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	clang++

all : ${NAME}

${NAME}:	${OBJ}
		${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

%.o: %.c
		${CXX} ${CXXFLAGS} -c $< -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
