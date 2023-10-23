NAME	=	PhoneBook
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	Phonebook.cpp Contacts.cpp main.cpp

INCS	=	PhoneBook.hpp
OBJ     =   $(SRCS:.cpp=.o)
RM	=	rm -rf
CXX	=	clang++

all : ${NAME}

${NAME}:	${OBJ}
		${CXX} ${CXXFLAGS} ${OBJ} -I ${INCS} -o ${NAME}

%.o: %.cpp
		${CXX} ${CXXFLAGS} -I ${INCS} -c $< -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
