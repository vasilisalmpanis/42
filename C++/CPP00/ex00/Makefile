NAME	=	megaphone
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	megaphone.cpp

OBJ     =	 $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	c++
INCS	=	megaphone.hpp
all : ${NAME}

${NAME}:	${OBJ}
		${CXX}  ${CXXFLAGS} ${OBJ} -o ${NAME} -I ${INCS}

%.o: %.cpp
		${CXX} ${CXXFLAGS} -c $< -o $@ -I ${INCS}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
