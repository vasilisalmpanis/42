NAME		= bank
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS		= ./src/DivideAndRule.cpp \
		  ./src/main.cpp

OBJ     	=  $(SRCS:.cpp=.o)
RM		= rm -rf
CXX		= $(shell which g++)
INCS		= ./include/

all : ${NAME}

${NAME}:	${OBJ}
		${CXX}  ${CXXFLAGS} ${OBJ} -o ${NAME} -I ${INCS}

%.o: %.cpp
		${CXX} ${CXXFLAGS} -c $< -o $@ -I ${INCS}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
