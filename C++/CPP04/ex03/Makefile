NAME	=	Materia	
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp AMateria.cpp Ice.cpp Cure.cpp
OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	clang++

all : ${NAME}

${NAME}:	${OBJ} 
		${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

%.o: %.cpp %.h
		${CXX} ${CXXFLAGS} -c $< -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
